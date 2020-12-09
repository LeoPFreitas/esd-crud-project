//
// Created by mind on 11/11/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "strings.h"
#include "music.h"


/*  Função: cria uma nova música
 *  Params: Ponteiro para Int ID das músicas
 *  Return: uma nova música
 */
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


/* Função: Inseri uma música na struct de musicas
*  Params: Ponteiro para lista de músicas e Ponteiro de de INT do ID da música
*  Return: void
*/
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


/*  Função: Printa o tempo de uma música em HH:MM:SS
 *  Params: Ponteiro para música
 *  Return: void
 */
void *convertHHMMSSAndPrint(musica_no *musicaNo) {
    int sec, h, m, s;

    h = (musicaNo->musica->duracao) / 3600;
    m = (musicaNo->musica->duracao - (3600 * h)) / 60;
    s = (musicaNo->musica->duracao - (3600 * h) - (m * 60));

    printf("%d:%d:%d\n", h, m, s);
}


/*  Função: Printa todas as músicas dentro da lista de músicas
 *  Params: Ponteiro para lista de músicas
 *  Return: void
 */
void listAndPrintLL(musica_no *ll) {
    while (ll->prox != NULL) {
        printf("ID: %d TITULO: %s ARTISTAl: %s ALBUM: %s DURACAO: ", ll->prox->musica->id, ll->prox->musica->titulo,
               ll->prox->musica->artista, ll->prox->musica->album);
        convertHHMMSSAndPrint(ll->prox);
        ll = ll->prox;
    }
}


int isMusicLinkedListEmpty(musica_no *ll) {
    if (ll->prox != NULL) {
        return 1;
    }
    return 0;
}


/*  Função: Printa o menu principal
 *  Params: void
 *  Return: void
 */
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


/*  Função: Printa o menu de playlist
 *  Params: void
 *  Return: void
 */
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
