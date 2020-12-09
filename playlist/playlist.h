//
// Created by mind on 22/11/2020.
//

#ifndef PROJECT1_PLAYLIST_H
#define PROJECT1_PLAYLIST_H

#include "../mymusic/music.h"

// Struct Playlist
typedef struct playlist_no {
    musica *musica;
    struct playlist_no *prox;
} playlist_no;

// Struct Linked List Playlists
typedef struct lplaylists_no {
    int id;
    char nome[200];
    playlist_no *musicas;
    struct lplaylists_no *prox;
} lplaylists_no;

playlist_no *makePlaylistNo();

void insertMusicOnPlaylist(musica_no *ll, int musicId, playlist_no *playlist);

playlist_no *makePlaylist(musica *ll);

void printPlaylistMusics(lplaylists_no *p);

void insertOnPLaylistHead(musica_no *ll, int playlistId, lplaylists_no *lpl);

void removeMusicFromPlaylists(lplaylists_no *lpl);


int playlistNoSize(playlist_no *list);

void shufflePlaylist(lplaylists_no *lplaylistsNo);

int playlistLinkedListSize(lplaylists_no *lplaylistsNo);

#endif //PROJECT1_PLAYLIST_H
