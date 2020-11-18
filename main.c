#include <stdlib.h>
#include "mymusic/music.h"

int main() {

    // create linked list with null head
    struct musica_no *ll = malloc(sizeof(musica_no));
    int musicId = 0;
    int *p = &musicId;

     insertOnHead(ll, p);
     insertOnHead(ll, p);

     listAndPrintLL(ll);

    return 0;

}
