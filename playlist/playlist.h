//
// Created by mind on 22/11/2020.
//

#ifndef PROJECT1_PLAYLIST_H
#define PROJECT1_PLAYLIST_H

#include "../mymusic/music.h"

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

void removeMusicFromPlaylists(lplaylists_no *lpl, ArvAVL *root);

int getPlaylistSize(playlist_no *head);

void shuffle(lplaylists_no *lplNode);

void shufflePlaylist(lplaylists_no *lplaylistsNo);

lplaylists_no *createPlaylist(struct lplaylists_no *playlistsll);

void getVectorOfMusics(int **v, int *listMusicSize);

void addMusicsToPlaylist(ArvAVL *arvAVL, const int *v, int listMusicSize, struct playlist_no *musicListHead);

void createPlaylistWithMusics(ArvAVL *arvAVL, struct lplaylists_no *playlistsll);

lplaylists_no *getDesiredPlaylist(int id, struct lplaylists_no *listOfPlaylistsTemp);

int getPlaylistID();

void printPLaylistMusics(struct lplaylists_no *listOfPlaylistsTemp);

void printPLaylist(struct lplaylists_no *playlistsll);

#endif //PROJECT1_PLAYLIST_H
