//
// Created by mind on 11/11/2020.
//

#ifndef PROJECT1_MUSIC_H
#define PROJECT1_MUSIC_H

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


typedef struct playlist_no {
    musica *musica;
    struct playlist_no *prox;
} playlist_no;


typedef struct lplaylists_no {
    int id;
    char nome[200];
    playlist_no *musicas;
    struct lplaylists_no *prox;
} lplaylists_no;

musica *createMusicNode();

void insertOnHead(musica_no *musica);

// TODO implement hour method
void listAndPrintLL(musica_no *ll);


// TODO implement method
char *convertHHMMSS(musica *musica);

#endif //PROJECT1_MUSIC_H
