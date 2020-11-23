#include <stdlib.h>
#include <stdio.h>
#include "mymusic/music.h"

int main() {

    // create linked list with null head
    struct musica_no *ll = malloc(sizeof(musica_no));
    struct playlist_no *Pll = malloc(sizeof(playlist_no));

    int musicId = 0, optionSelected = 0, optionPlaylist = 0, idMusicToAddPlaylist = 0;
    int *p = &musicId;


    insertOnHead(ll, p);
    insertOnHead(ll, p);

    playlist_no *pp = makePlaylist(ll);
    printf("lalala");

//    while (1) {
//        makePrincipalMenu();
//        printf("Selecione uma opção: \n");
//        fflush(stdin);
//        scanf("%d", &optionSelected);
//        switch (optionSelected) {
//            case 1:
//                printf("CADASTRAR NOVA MÚSICA \n");
//                insertOnHead(ll, p);
//                break;
//            case 2:
//                printf("IMPRIMIR TODAS AS MÚSICAS\n");
//                listAndPrintLL(ll);
//                break;
//            case 3:
//                makePlaylistMenu();
//                printf("Selecione uma opção: \n");
//                fflush(stdin);
//                scanf("%d", &optionPlaylist);
//                switch (optionPlaylist) {
//                    case 1:
//                        printf("CRIAR NOVA PLAYLIST\n");
//                        printf("Digite os ID das músicas separado por espaço: ");
//                        break;
//                    case 2:
//                        printf("SHUFFLE PLAYLIST\n");
//                        break;
//                    case 3:
//                        printf("IMPRIME PLAYLIST\n");
//                        break;
//                    case 4:
//                        printf("REMOVER MÚSICA DE TODAS AS PLAYLIST\n");
//                        break;
//                    case 0:
//                        printf("Voltando para o menu principal..\n");
//                        break;
//                    default:
//                        printf("Comando inválido!\n");
//                        break;
//                }
//                break;
//            case 0:
//                printf("Saíndo do programa\n");
//                exit(0);
//            default:
//                printf("Comando inválido!\n");
//                break;
//        }
//    }

}
