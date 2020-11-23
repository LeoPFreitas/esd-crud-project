//
// Created by mind on 22/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "../mymusic/music.h"

void insertMusicOnPlaylist(musica_no *ll, int musicId, playlist_no *playlist) {
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
    int size = 0;
    int i = 0;
    char temp;

    printf("Digite o tamanho da playlist: ");
    scanf("%d", &size);
    int v[size];

    printf("Digite os id das musicas separadas por espaco: ");
    do {
        scanf("%d%c", &v[i], &temp);
        i++;
    } while (temp != '\n');

    // create playlist
    struct playlist_no *playlistNo = malloc(sizeof(struct playlist_no));
    playlistNo->prox = playlistNo;

    for (int j = 0; j < 2; ++j) {
        insertMusicOnPlaylist(ll, v[j], playlistNo);
    }

    return playlistNo;
}

void insertOnPLaylistHead(musica_no *ll, int *playlistId, lplaylists_no *lpl) {
    struct lplaylists_no *newPlaylist = malloc(sizeof(lplaylists_no));
    lpl->prox = newPlaylist;

    printf("Digite o nome da playlist: ");
    scanf("%s", newPlaylist->nome);
    fflush(stdin);

    lpl->id = (*playlistId)++;
    newPlaylist->musicas = makePlaylist(ll);
}

void printPlaylistMusics(lplaylists_no *p) {

    int id;
    printf("Digite o id da playlist: ");
    scanf("%d", &id);

    while (p->prox != NULL && p->id != id) {
        p = p->prox;
    }

    if (p->prox == NULL) {
        printf("Playlist não encontrada.\n");
        return;
    }

    playlist_no *head = p->prox->musicas;
    if (head == NULL)
        printf("\nList is Empty!!!");
    else {
        playlist_no *temp = head->prox;
        printf("\nList elements are: \n");
        while (temp->prox != head) {
            printf("%MUSICA: s\n", temp->prox->musica->titulo);
            temp = temp->prox;
        }
        printf("\nFim\n");
    }
}