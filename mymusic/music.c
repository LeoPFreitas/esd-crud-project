//
// Created by mind on 11/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "music.h"

musica *createMusicNode(int *musicId) {
  struct musica *newMusic = malloc(sizeof(struct musica));

  fflush(stdin);

  printf("Título: ");
  scanf("%s", newMusic->titulo);
  fflush(stdin);

  printf("Artista: ");
  scanf("%s", newMusic->artista);
  fflush(stdin);

  printf("Album: ");
  scanf("%s", newMusic->album);
  fflush(stdin);

  printf("Duração em segundos: ");
  scanf("%d", &newMusic->duracao);
  fflush(stdin);

  newMusic->id = (*musicId)++;

  return newMusic;
}

void insertOnTree(ArvAVL *arvAvl, int *musicId) {
  musica *newMusic = createMusicNode(musicId);

  insere_ArvAVL(arvAvl, newMusic);
}

//void *convertHHMMSSAndPrint(musica_no *musicaNo) {
//    int sec, h, m, s;
//
//    h = (musicaNo->musica->duracao) / 3600;
//    m = (musicaNo->musica->duracao - (3600 * h)) / 60;
//    s = (musicaNo->musica->duracao - (3600 * h) - (m * 60));
//
//    printf("%d:%d:%d\n", h, m, s);
//}

void printAllMusics(struct treeAVLNode **arvAvl) {
  if (!isTreeAVLEmpty(arvAvl)) {
    printf("\n\nLista de Musicas: \n");
    emOrdem_ArvAVL(arvAvl);
  } else {
    printf("Lista de muscia vazia\n");
  }
}

void makePrincipalMenu() {
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                               MENU PINCIPAL                                                |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Cadastrar nova música\n");
  printf("2 - Imprime todas as músicas da lista\n");
  printf("3 - Remover musica\n");
  printf("4 - Playlists\n");
  printf("0 - Sair do programa\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
}

void makePlaylistMenu() {
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                                MENU PLAYLIST                                               |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Criar nova Playlist\n");
  printf("2 - Shuffle Playlist\n");
  printf("3 - Imprime Playlist\n");
  printf("0 - Voltar para o Menu Principal\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
}
