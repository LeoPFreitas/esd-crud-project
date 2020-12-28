//
// Created by mind on 28/12/2020.
//

#ifndef PROJECT1_TREEAVL_H
#define PROJECT1_TREEAVL_H

#include "../mymusic/music.h"

typedef struct treeAVLNode* ArvAVL;

ArvAVL* createTreeAVL();

void clearTreeNode(struct treeAVLNode* arvAVL);

void clearTreeAVL(ArvAVL* root);

int getNodeHigh(struct treeAVLNode* arvAVL);

int getBalancefactor(struct treeAVLNode* arvAVL);

int isHigher(int x, int y);

int isTreeAVLEmpty(ArvAVL *root);

int totalNO_ArvAVL(ArvAVL *root);

int altura_ArvAVL(ArvAVL *raiz);

void preOrdem_ArvAVL(ArvAVL *raiz);

void emOrdem_ArvAVL(ArvAVL *raiz);

void posOrdem_ArvAVL(ArvAVL *raiz);

int consulta_ArvAVL(ArvAVL *raiz, int valor);

void RotacaoLL(ArvAVL *A);

void RotacaoRR(ArvAVL *A);

void RotacaoLR(ArvAVL *A);

void RotacaoRL(ArvAVL *A);

int insere_ArvAVL(ArvAVL *raiz, struct musica *musica);

struct treeAVLNode* procuraMearvAVLr(struct treeAVLNode* atual);

int remove_ArvAVL(ArvAVL *raiz, int valor);

#endif //PROJECT1_TREEAVL_H
