//
// Created by mind on 11/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "strings.h"
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

    printf("%d", *musicId);
    newMusic->id = (*musicId)++;

    return newMusic;
}

void insertOnHead(musica_no *ll, int *musicId) {
    struct musica_no *newMusicNode = malloc(sizeof(struct musica));

    struct musica *newMusic = createMusicNode(musicId);

    newMusicNode->musica = newMusic;

    newMusicNode->prox = ll->prox;
    newMusicNode->ant = ll;
    if (ll->prox != NULL) {
        ll->prox->ant = newMusicNode;
    }
    ll->prox = newMusicNode;
}

void *convertHHMMSSAndPrint(musica_no *musicaNo) {
    int sec, h, m, s;

    h = (musicaNo->musica->duracao) / 3600;
    m = (musicaNo->musica->duracao - (3600 * h)) / 60;
    s = (musicaNo->musica->duracao - (3600 * h) - (m * 60));

    printf("%d:%d:%d\n", h, m, s);
}

void listAndPrintLL(musica_no *ll) {
    while (ll->prox != NULL) {
        printf("ID: %d TITULO: %s ARTISTAl: %s ALBUM: %s DURACAO: ", ll->prox->musica->id, ll->prox->musica->titulo,
               ll->prox->musica->artista, ll->prox->musica->album);
        convertHHMMSSAndPrint(ll->prox);
        ll = ll->prox;
    }
}

// TODO implement nullable check function
int isMusicLinkedListEmpty(musica_no *ll) {
    if (ll->prox != NULL) {
        return 1;
    }
    return 0;
}

playlist_no* makePlaylistNo() {
    struct playlist_no *ll = malloc(sizeof(struct playlist_no));
    ll->prox = ll;
    return &ll;
}

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
    } while(temp != '\n');

    // create playlist
    struct playlist_no *playlistNo = malloc(sizeof(struct playlist_no));
    playlistNo->prox = playlistNo;

    for (int j = 0; j < 2; ++j) {
        insertMusicOnPlaylist(ll, v[j], playlistNo);
    }

    return playlistNo;
}

void makePrincipalMenu() {
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("|                                               MENU PINCIPAL                                                |\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("1 - Cadastrar nova música\n");
    printf("2 - Imprime todas as músicas da lista\n");
    printf("3 - Playlists\n");
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
    printf("4 - Remover música de todas as Playlist\n");
    printf("0 - Voltar para o Menu Principal\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
}
