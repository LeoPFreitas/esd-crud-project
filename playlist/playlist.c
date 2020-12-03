//
// Created by mind on 22/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../mymusic/music.h"
#include "../playlist/playlist.h"

void insertMusicOnPlaylist(musica_no *ll, int musicId, playlist_no *playlist) {
  /*  Função: Enserir nova música na playlist
   *  Params: Ponteiro para lista de músicas, INT id das músicas, Ponteiro da playlist
   *  Return: void
   */

  // TODO extract to validation method (isMusicValid)
  musica_no *nodeMusic = ll->prox;
  while (nodeMusic->musica->id != musicId) {
    // TODO verificar se id existe
    nodeMusic = nodeMusic->prox;
  }

  playlist_no *newNode = malloc(sizeof(playlist_no));
  newNode->musica = nodeMusic->musica;

  // insert
  if (playlist->prox == NULL) {
    playlist->prox = newNode;
    newNode->prox = playlist;
  } else {
    playlist_no *playlistTemp = playlist;
    while (playlistTemp->prox != playlist) {
      playlistTemp = playlistTemp->prox;
    }
    newNode->prox = playlist;
    playlistTemp->prox = newNode;
  }
}

playlist_no *makePlaylist(musica *ll) {
  /*  Função: Criar uma nova playlist
   *  Params: Ponteiro da lista de músicas
   *  Return: Ponteiro da playlist criada
   */

  int size = 0;

  printf("Digite o tamanho da playlist: ");
  scanf("%d", &size);
  int v[size];
  fflush(stdin);

  printf("Digite os id das musicas separadas por espaco: ");
  for (int j = 0; j < size; ++j) {
    scanf("%d", &v[j]);
  }

  // create playlist
  struct playlist_no *playlistNo = malloc(sizeof(struct playlist_no));
  playlistNo->prox = playlistNo;

  for (int j = 0; j < size; ++j) {
    int aux = v[j];
    insertMusicOnPlaylist(ll, aux, playlistNo);
  }

  return playlistNo;
}

void insertOnPLaylistHead(musica_no *ll, int playlistId, lplaylists_no *lpl) {
  /*  Função: Inserie playlist na lista de playlists
   *  Params: Ponteiro de lista de músicas, INT playlistId, ponteiro para lista de playlist
   *  Return: void
   */

  struct lplaylists_no *newPlaylist = malloc(sizeof(lplaylists_no));


  if (lpl->prox == NULL) {
    lpl->prox = newPlaylist;
  } else {
    while (lpl->prox != NULL) {
      lpl = lpl->prox;
    }
    lpl->prox = newPlaylist;
  }

  printf("Digite o nome da playlist: ");
  scanf("%s", newPlaylist->nome);
  fflush(stdin);
  lpl->prox->id = playlistId;
  newPlaylist->musicas = makePlaylist(ll);
}

/*  Função: Printa a playlist escolhida
*  Params: Ponteiro para lista de playlist
*  Return: void
*/
void printPlaylistMusics(lplaylists_no *p) {
  int id;
  printf("Digite o id da playlist: ");
  scanf("%d", &id);

  // check if there is playlist
  if (p->prox == NULL) {
    printf("Playlist não encontrada.\n");
    return;
  }

  int size = playlistLinkedListSize(p);

  while (p->prox != NULL && p->id != id) {
    p = p->prox;

    // find here
    if (p->id == id) {
      break;
    }
    size--;
  }

  // Not found
  if (p->prox == NULL && size == 0) {
    printf("Playlist não encontrada.\n");
    return;
  }

  playlist_no *head = p->musicas;
  if (head->prox == head)
    printf("\nList is Empty!!!");
  else {
    int size = playlistNoSize(head);
    printf("\nAs músicas da playlist %d são: \n", id);
    while (size > 0) {
      head = head->prox;
      printf("MUSICA: %s ID: %d\n", head->musica->titulo, head->musica->id);
      size--;
    }
    printf("\nFim\n");
  }
}

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
        temp->prox = NULL;
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

void shuffleTwo(lplaylists_no *lplaylistsNo) {
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
    playlist_no *temp = malloc(sizeof(playlist_no));


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

    temp->musica = n1->musica;
    n1->musica = n2->musica;
    n2->musica = temp->musica;
  }


}