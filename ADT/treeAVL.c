//
// Created by mind on 28/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "treeAVL.h"

struct treeAVLNode {
    struct musica *musica;
    int altura;
    struct treeAVLNode *esq;
    struct treeAVLNode *dir;
};

ArvAVL *createTreeAVL() {
  ArvAVL *root = (ArvAVL *) malloc(sizeof(ArvAVL));

  if (root != NULL) {
    *root = NULL;
  }

  return root;
}

void clearTreeNode(struct treeAVLNode *arvAVL) {
  if (arvAVL == NULL)
    return;
  clearTreeNode(arvAVL->esq);
  clearTreeNode(arvAVL->dir);
  free(arvAVL);
  arvAVL = NULL;
}

void clearTreeAVL(ArvAVL *root) {
  if (root == NULL)
    return;
  clearTreeNode(*root);//libera cada no
  free(root);//libera a root
}

int getNodeHigh(struct treeAVLNode *arvAVL) {
  if (arvAVL == NULL)
    return -1;
  else
    return arvAVL->altura;
}

int getBalancefactor(struct treeAVLNode *arvAVL) {
  return labs(getNodeHigh(arvAVL->esq) - getNodeHigh(arvAVL->dir));
}

int isHigher(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int isTreeAVLEmpty(ArvAVL *root) {
  if (root == NULL)
    return 1;
  if (*root == NULL)
    return 1;
  return 0;
}

int totalNO_ArvAVL(ArvAVL *root) {
  if (root == NULL)
    return 0;
  if (*root == NULL)
    return 0;
  int alt_esq = totalNO_ArvAVL(&((*root)->esq));
  int alt_dir = totalNO_ArvAVL(&((*root)->dir));
  return (alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return 0;
  if (*raiz == NULL)
    return 0;
  int alt_esq = altura_ArvAVL(&((*raiz)->esq));
  int alt_dir = altura_ArvAVL(&((*raiz)->dir));
  if (alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    //printf("%d\n",(*raiz)->info);
    //printf("No %d: %d\n",(*raiz)->info,getBalancefactor(*raiz));
    printf("No %d: %d\n", (*raiz)->musica->id, getNodeHigh(*raiz));
    preOrdem_ArvAVL(&((*raiz)->esq));
    preOrdem_ArvAVL(&((*raiz)->dir));
  }
}

void emOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    emOrdem_ArvAVL(&((*raiz)->esq));

    printf("Musica id %d\n", (*raiz)->musica->id);
    emOrdem_ArvAVL(&((*raiz)->dir));
  }
}

void posOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    posOrdem_ArvAVL(&((*raiz)->esq));
    posOrdem_ArvAVL(&((*raiz)->dir));
    printf("%d\n", (*raiz)->musica->id);
  }
}

struct musica *consulta_ArvAVL(ArvAVL *raiz, int valor) {
  if (raiz == NULL)
    return NULL;
  struct treeAVLNode *atual = *raiz;
  while (atual != NULL) {
    if (valor == atual->musica->id) {
      return atual->musica;
    }
    if (valor > atual->musica->id)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return NULL;
}

//=================================
void RotacaoLL(ArvAVL *A) {//LL
  printf("RotacaoLL\n");
  struct treeAVLNode *B;
  B = (*A)->esq;
  (*A)->esq = B->dir;
  B->dir = *A;
  (*A)->altura = isHigher(getNodeHigh((*A)->esq), getNodeHigh((*A)->dir)) + 1;
  B->altura = isHigher(getNodeHigh(B->esq), (*A)->altura) + 1;
  *A = B;
}

void RotacaoRR(ArvAVL *A) {//RR
  printf("RotacaoRR\n");
  struct treeAVLNode *B;
  B = (*A)->dir;
  (*A)->dir = B->esq;
  B->esq = (*A);
  (*A)->altura = isHigher(getNodeHigh((*A)->esq), getNodeHigh((*A)->dir)) + 1;
  B->altura = isHigher(getNodeHigh(B->dir), (*A)->altura) + 1;
  (*A) = B;
}

void RotacaoLR(ArvAVL *A) {//LR
  RotacaoRR(&(*A)->esq);
  RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A) {//RL
  RotacaoLL(&(*A)->dir);
  RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, struct musica *musica) {
  int res;
  if (*raiz == NULL) {
    struct treeAVLNode *arvAVLvo;
    arvAVLvo = (struct treeAVLNode *) malloc(sizeof(struct treeAVLNode));
    if (arvAVLvo == NULL)
      return 0;

    arvAVLvo->musica = musica;
    arvAVLvo->altura = 0;
    arvAVLvo->esq = NULL;
    arvAVLvo->dir = NULL;
    *raiz = arvAVLvo;
    return 1;
  }

  struct treeAVLNode *atual = *raiz;
  if (musica->id < atual->musica->id) {
    if ((res = insere_ArvAVL(&(atual->esq), musica)) == 1) {
      if (getBalancefactor(atual) >= 2) {
        if (musica->id < (*raiz)->esq->musica->id) {
          RotacaoLL(raiz);
        } else {
          RotacaoLR(raiz);
        }
      }
    }
  } else {
    if (musica->id > atual->musica->id) {
      if ((res = insere_ArvAVL(&(atual->dir), musica)) == 1) {
        if (getBalancefactor(atual) >= 2) {
          if ((*raiz)->dir->musica->id < musica->id) {
            RotacaoRR(raiz);
          } else {
            RotacaoRL(raiz);
          }
        }
      }
    } else {
      printf("Valor duplicado!!\n");
      return 0;
    }
  }

  atual->altura = isHigher(getNodeHigh(atual->esq), getNodeHigh(atual->dir)) + 1;

  return res;
}

ArvAVL procuraMearvAVLr(ArvAVL atual) {
  ArvAVL arvAVL1 = atual;
  ArvAVL arvAVL2 = atual->esq;
  while (arvAVL2 != NULL) {
    arvAVL1 = arvAVL2;
    arvAVL2 = arvAVL2->esq;
  }
  return arvAVL1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor) {
  if (*raiz == NULL) {// valor nao existe
    printf("valor nao existe!!\n");
    return 0;
  }

  int res;
  if (valor < (*raiz)->musica->id) {
    if ((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1) {
      if (getBalancefactor(*raiz) >= 2) {
        if (getNodeHigh((*raiz)->dir->esq) <= getNodeHigh((*raiz)->dir->dir))
          RotacaoRR(raiz);
        else
          RotacaoRL(raiz);
      }
    }
  }

  if ((*raiz)->musica->id < valor) {
    if ((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1) {
      if (getBalancefactor(*raiz) >= 2) {
        if (getNodeHigh((*raiz)->esq->dir) <= getNodeHigh((*raiz)->esq->esq))
          RotacaoLL(raiz);
        else
          RotacaoLR(raiz);
      }
    }
  }

  if ((*raiz)->musica->id == valor) {
    if (((*raiz)->esq == NULL || (*raiz)->dir == NULL)) {// arvAVL tem 1 filho ou nenhum
      struct treeAVLNode *oldNode = (*raiz);
      if ((*raiz)->esq != NULL)
        *raiz = (*raiz)->esq;
      else
        *raiz = (*raiz)->dir;
      free(oldNode);
    } else { // arvAVL tem 2 filhos
      struct treeAVLNode *temp = procuraMearvAVLr((*raiz)->dir);
      (*raiz)->musica = temp->musica;
      remove_ArvAVL(&(*raiz)->dir, (*raiz)->musica->id);
      if (getBalancefactor(*raiz) >= 2) {
        if (getNodeHigh((*raiz)->esq->dir) <= getNodeHigh((*raiz)->esq->esq))
          RotacaoLL(raiz);
        else
          RotacaoLR(raiz);
      }
    }
    if (*raiz != NULL)
      (*raiz)->altura = isHigher(getNodeHigh((*raiz)->esq), getNodeHigh((*raiz)->dir)) + 1;
    return 1;
  }

  (*raiz)->altura = isHigher(getNodeHigh((*raiz)->esq), getNodeHigh((*raiz)->dir)) + 1;

  return res;
}
