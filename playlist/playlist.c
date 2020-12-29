//
// Created by mind on 22/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "../mymusic/music.h"
#include "../playlist/playlist.h"

void removeMusicFromPlaylists(lplaylists_no *lpl) {
  int musicId;
  printf("Digite o ID da musica: ");
  scanf("%d", &musicId);

  // loop through playlists
  while (lpl->prox != NULL) {

    // get the playlist_node head pointer
    playlist_no *head = lpl->prox->musicas;

    // find the music inside that playlist
    playlist_no *temp = head;

    while (temp->prox != head) {
      // loop playlist
      playlist_no *aux = temp;
      temp = temp->prox;
      if (temp->musica->id == musicId) {
        printf("Remover musica ID %d\n", temp->musica->id);
        aux->prox = temp->prox;
//        temp->prox = NULL;
        free(temp);
        break;
      }
    }
    // go to the next playlist
    lpl = lpl->prox;
  }
}

int playlistLinkedListSize(lplaylists_no *lplaylistsNo) {
  int size = 0;

  if (lplaylistsNo->prox == NULL) {
    return 0;
  }

  while (lplaylistsNo->prox != NULL) {
    size++;
    lplaylistsNo = lplaylistsNo->prox;
  }

  return size;
}

int playlistNoSize(playlist_no *list) {
  int size = 0;

  playlist_no *head = list;

  if (list->prox == head) {
    return 0;
  }

  while (list->prox != head) {
    size++;
    list = list->prox;
  }

  return size;
}

lplaylists_no *createPlaylist(struct lplaylists_no *playlistsll) {
  // criar um no de playlist
  struct lplaylists_no *playList = malloc(sizeof(lplaylists_no));

  // Pega o nome da playlist
  printf("Digite o nome da playlist: ");
  scanf("%s", playList->nome);
  fflush(stdin);

  // buscar o local correto de insercao na lista de playlists e incrementar id;
  lplaylists_no *p = playlistsll;
  while (p->prox != NULL) {
    p = p->prox;
  }
  p->prox = playList;
  p->prox->id = p->id + 1;

  return playList;
}

void getVectorOfMusics(int **v, int *listMusicSize) {
  (*listMusicSize) = 0;
  printf("Digite o tamanho da playlist: ");
  scanf("%d", listMusicSize);

  if (*listMusicSize <= 0) {
    printf("\nPlaylist criada sem musica!\n");
    return;
  }

  (*v) = malloc((*listMusicSize) * sizeof(int));
  fflush(stdin);

  printf("Digite os id das musicas separadas por espaco: ");
  for (int j = 0; j < (*listMusicSize); ++j) {
    scanf("%d", &(*v)[j]);
  }
}

void addMusicsToPlaylist(ArvAVL *arvAVL, const int *v, int listMusicSize, struct playlist_no *musicListHead) {
  playlist_no *temp = musicListHead;

  for (int j = 0; j < listMusicSize; ++j) {
    int aux = v[j];

    // buscar na arvore a musica
    struct musica *tempMusicPointer = consulta_ArvAVL(arvAVL, aux);
    if (tempMusicPointer == NULL) {
      printf("Null");
    }

    // cria o proximo no de musica
    struct playlist_no *next = malloc(sizeof(playlist_no));
    temp->prox = next;
    next->musica = tempMusicPointer;

    temp = temp->prox;
  }

  temp->prox = musicListHead->prox;

}

void createPlaylistWithMusics(ArvAVL *arvAVL, struct lplaylists_no *playlistsll) {
  lplaylists_no *playList = createPlaylist(playlistsll);

  // atribui lista de musicas à playlist
  playList->musicas = malloc(sizeof(playlist_no));

  // Pegar lista de musicas que o cara quer
  int *v;
  int listMusicSize;
  getVectorOfMusics(&v, &listMusicSize);

  struct playlist_no *musicListHead = playList->musicas;

  addMusicsToPlaylist(arvAVL, v, listMusicSize, musicListHead);
}

lplaylists_no *getDesiredPlaylist(int id, struct lplaylists_no *listOfPlaylistsTemp) {
  // checa se a lista de playlist tem 1 playlist pelo menos
  if (listOfPlaylistsTemp->prox == NULL) {
    printf("Playlist não encontrada.\n");
    return NULL;
  }

  // procura a playlista desejada
  do {
    listOfPlaylistsTemp = listOfPlaylistsTemp->prox;
    if (listOfPlaylistsTemp->id == id) {
      break;
    }
  } while (listOfPlaylistsTemp->prox != NULL);

  // verificar se encontrou ou se saiu NULL
  if (listOfPlaylistsTemp == NULL) {
    return NULL;
  }

  return listOfPlaylistsTemp;
}

int getPlaylistID() {
  int id;
  printf("Digite o id da playlist: ");
  scanf("%d", &id);
  return id;
}

void printPLaylistMusics(struct lplaylists_no *listOfPlaylistsTemp) {
  playlist_no *temp = listOfPlaylistsTemp->musicas;

  if (temp->prox == NULL) // playlist nao tem musicas
    printf("\nPLaylist não possui nenhuma musica\n");
  else {
    temp = temp->prox;
    do {
      printf("MUSICA: %s ID: %d\n", temp->musica->titulo, temp->musica->id);
      temp = temp->prox;
    } while (temp->musica != listOfPlaylistsTemp->musicas->prox->musica);
    printf("\nFim\n");
  }
}

void printPLaylist(struct lplaylists_no *playlistsll) {// pegar o id da playlist desejada
  int id = getPlaylistID();

  // procurar se a playlist existe e retornar ponteiro para ela
  struct lplaylists_no *listOfPlaylistsTemp = playlistsll;
  listOfPlaylistsTemp = getDesiredPlaylist(id, listOfPlaylistsTemp);

  if (listOfPlaylistsTemp != NULL) {
    printPLaylistMusics(listOfPlaylistsTemp);
  } else {
    printf("\n\nPLaylist não encontrada!!\n");
  }
}

void shufflePlaylist(lplaylists_no *lplaylistsNo) {
  printf("Digite o ID da playlist: ");
  int id = -1;
  scanf("%d", &id);

  int lplSize = playlistLinkedListSize(lplaylistsNo);
  lplaylists_no *lplNode = lplaylistsNo->prox;
  while (lplSize > 0) {
    if (lplNode->id == id) {
      break;
    }
    lplNode = lplNode->prox;
    lplSize--;
  }

  if (lplSize == 0) {
    printf("PLaylist não encontrada.\n");
    return;
  }


  playlist_no *head = lplNode->musicas;
  int count = playlistNoSize(head);

  for (int i = 0; i < count; ++i) {
    int musicSize = playlistNoSize(head);
    playlist_no *n1 = head->prox;
    playlist_no *n2 = head->prox;
    musica *temp;


    int a = (rand() % (musicSize - 1));
    int b = (rand() % (musicSize - 1));

    // get first
    for (int i = 0; i < a; ++i) {
      n1 = n1->prox;
    }

    // get second
    for (int i = 0; i < b; ++i) {
      n2 = n2->prox;
    }

    temp = n1->musica;
    n1->musica = n2->musica;
    n2->musica = temp;
  }
}