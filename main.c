#include <stdlib.h>
#include <stdio.h>
#include "mymusic/music.h"
#include "playlist/playlist.h"

int main() {

    // create linked list with null head
    struct musica_no *ll = malloc(sizeof(musica_no));
    struct playlist_no *Pll = malloc(sizeof(playlist_no));
    struct lplaylists_no *playlistsll = malloc(sizeof(lplaylists_no));

    Pll->prox = Pll;
    playlistsll->id = -1;

    int musicId = 0;
    int idMusicToAddPlaylist = 0;

    int *pMusicId = &musicId;
    int *pPlaylistId = &idMusicToAddPlaylist;

    int optionSelected = 0;
    int optionPlaylist = 0;


    while (1) {
        makePrincipalMenu();
        printf("Selecione uma opção: \n");
        fflush(stdin);
        scanf("%d", &optionSelected);
        switch (optionSelected) {
            case 1:
                printf("CADASTRAR NOVA MÚSICA \n");
                insertOnHead(ll, pMusicId);
                break;
            case 2:
                printf("IMPRIMIR TODAS AS MÚSICAS\n");
                listAndPrintLL(ll);
                break;
            case 3:
                makePlaylistMenu();
                printf("Selecione uma opção: \n");
                fflush(stdin);
                scanf("%d", &optionPlaylist);
                switch (optionPlaylist) {
                    case 1:
                        printf("CRIAR NOVA PLAYLIST\n");
                        insertOnPLaylistHead(ll, pPlaylistId, playlistsll);
                        break;
                    case 2:
                        // TODO
                        printf("SHUFFLE PLAYLIST\n");
                        break;
                    case 3:
                        printf("IMPRIME PLAYLIST\n");
                        printPlaylistMusics(playlistsll);
                        break;
                    case 4:
                        // TODO
                        printf("REMOVER MÚSICA DE TODAS AS PLAYLIST\n");
                        removeMusicFromPLaylists(playlistsll);
                        break;
                    case 0:
                        // TODO
                        printf("Voltando para o menu principal..\n");
                        break;
                    default:
                        printf("Comando inválido!\n");
                        break;
                }
                break;
            case 0:
                printf("Saíndo do programa\n");
                exit(0);
            default:
                printf("Comando inválido!\n");
                break;
        }
    }

}
