//
// Created by mind on 22/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
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
    playlist_no *temp = head->prox;
    printf("\nAs músicas da playlist %d são: \n", id);
    while (temp != head) {
      printf("MUSICA: %s\n", temp->musica->titulo);
      temp = temp->prox;
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
        printf("Remover musica ID %d", temp->musica->id);
        aux->prox = temp->prox;
        temp->prox = NULL;
        break;
      }
    }
    // go to the next playlist
    lpl = lpl->prox;
  }
}

void shuffle(playlist_no *playlistNo) {
  /*  Função: Troca a ordem das músicas de lugar
   *  Params: Ponteiro para a playlist
   *  Return: void
   */

  int playListSize = playlistNoSize(playlistNo);

  if (playListSize == 0) {
    printf("\nLista de musicas vazia.\n");
    return;
  }

  //todo passa o restande das posições para trocar
  shuffleTwo(playlistNo, 1, 3);
  shuffleTwo(playlistNo, 2, 4);

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

void shuffleTwo(playlist_no *playll, int a, int b) {
  /*  Função: Troca de posição a musica na posição A com a musica da posição B
   *  Params: Ponteiro da playlist, int posiçãoA, int posiçãoB
   *  Return: void
   */
  playlist_no *head = playll;

  playlist_no *ant1 = head;
  playlist_no *n1 = head->prox;
  playlist_no *ant2 = head;
  playlist_no *n2 = head->prox;

  // get first
  for (int i = 0; i < a; ++i) {
    ant1 = ant1->prox;
    n1 = n1->prox;
  }

  // get second
  for (int i = 0; i < b; ++i) {
    ant2 = ant2->prox;
    n2 = n2->prox;
  }

  // change pos
  playlist_no *temp = n1->prox;

  n1->prox = n2->prox;
  ant1->prox = n2;

  n2->prox = temp;
  ant2->prox = n1;

}

//void deleteNode(struct Node **head_ref, int position)
//{
//    // If linked list is empty
//    if (*head_ref == NULL)
//        return;
//
//    // Store head node
//    struct Node* temp = *head_ref;
//
//    // If head needs to be removed
//    if (position == 0)
//    {
//        *head_ref = temp->next;   // Change head
//        free(temp);               // free old head
//        return;
//    }
//
//    // Find previous node of the node to be deleted
//    for (int i=0; temp!=NULL && i<position-1; i++)
//        temp = temp->next;
//
//    // If position is more than number of nodes
//    if (temp == NULL || temp->next == NULL)
//        return;
//
//    // Node temp->next is the node to be deleted
//    // Store pointer to the next of node to be deleted
//    struct Node *next = temp->next->next;
//
//    // Unlink the node from linked list
//    free(temp->next);  // Free memory
//
//    temp->next = next;  // Unlink the deleted node from list
//}