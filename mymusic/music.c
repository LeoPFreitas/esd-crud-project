//
// Created by mind on 11/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "strings.h"
#include "music.h"


musica *createMusicNode() {
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
    // TODO improve get duration
    scanf("%d", &newMusic->duracao);
    fflush(stdin);
    return newMusic;
}

void insertOnHead(musica_no *ll) {
    struct musica_no *newMusicNode = malloc(sizeof(struct musica));

    struct musica *newMusic = createMusicNode();

    newMusicNode->musica = newMusic;

    newMusicNode->prox = ll->prox;
    newMusicNode->ant = ll;
    if (ll->prox != NULL) {
        ll->prox->ant = newMusicNode;
    }
    ll->prox = newMusicNode;
}

void listAndPrintLL(musica_no *ll) {
    while (ll->prox != NULL) {
        printf("ID: %d TITULO: %s ARTISTAl: %s ALBUM: %s DURACAO: dura \n", ll->prox->musica->id, ll->prox->musica->titulo, ll->prox->musica->artista, ll->prox->musica->album);
        ll = ll->prox;
    }
}