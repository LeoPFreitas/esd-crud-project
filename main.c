#include <stdlib.h>
#include <stdio.h>
#include "mymusic/music.h"
#include "playlist/playlist.h"
#include "ADT/treeAVL.h"

int main() {
  // create a void tree avl and assign a pointer to it
  ArvAVL *arvAVL = createTreeAVL();

  // No cabeça da struct de playlists
  struct lplaylists_no *playlistsll = malloc(sizeof(lplaylists_no));
  playlistsll->id = -1;
  playlistsll->prox = NULL;

  int musicId = 0;

  int *pMusicId = &musicId;

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
        insertOnTree(arvAVL, pMusicId);
        break;
      case 2:
        printf("IMPRIMIR TODAS AS MÚSICAS\n");
        printAllMusics(arvAVL);
        break;
      case 3:
        printf("REMOVER MÚSICA\n");
        removeMusicFromPlaylists(playlistsll, arvAVL);
        break;
      case 4:
        makePlaylistMenu();
        printf("Selecione uma opção: \n");
        fflush(stdin);
        scanf("%d", &optionPlaylist);
        switch (optionPlaylist) {
          case 1:
            printf("CRIAR NOVA PLAYLIST\n");
            createPlaylistWithMusics(arvAVL, playlistsll);
            break;
          case 2:
            // TODO ??
            printf("SHUFFLE PLAYLIST:\n");
            shufflePlaylist(playlistsll);
            break;
          case 3:
            printf("IMPRIME PLAYLIST\n");
            printPLaylist(playlistsll);
            break;
          case 0:
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
