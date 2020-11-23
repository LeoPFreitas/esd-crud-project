//
// Created by mind on 22/11/2020.
//

#ifndef PROJECT1_PLAYLIST_H
#define PROJECT1_PLAYLIST_H

#include "../mymusic/music.h"

playlist_no* makePlaylistNo();

void insertMusicOnPlaylist(musica_no *ll, int musicId, playlist_no *playlist);

playlist_no *makePlaylist(musica *ll);

void printPlaylistMusics(lplaylists_no *p);

void insertOnPLaylistHead(musica_no *ll, int *playlistId, lplaylists_no *lpl);

#endif //PROJECT1_PLAYLIST_H
