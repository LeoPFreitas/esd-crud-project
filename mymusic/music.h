//
// Created by mind on 11/11/2020.
//

#ifndef PROJECT1_MUSIC_H
#define PROJECT1_MUSIC_H

#include <stdbool.h>
#include "../ADT/treeAVL.h"

typedef struct musica {
    int id;
    char titulo[200];
    char artista[200];
    char album[200];
    int duracao; //segundos
} musica;


typedef struct musica_no {
    musica *musica;
    struct musica_no *ant;
    struct musica_no *prox;
} musica_no;

void insertOnTree(struct treeAVLNode **arvAvl, int *musicId);

musica *createMusicNode(int *musicId);

void printAllMusics(struct treeAVLNode **arvAvl);

void *convertHHMMSS(musica *musica);

int isMusicLinkedListEmpty(musica_no *ll);

void makePrincipalMenu();

void makePlaylistMenu();

#endif //PROJECT1_MUSIC_H
