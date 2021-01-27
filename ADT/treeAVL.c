//
// Created by mind on 28/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "treeAVL.h"

/*
 * Struct de um nó arvore musicas
 * */
struct treeAVLNode {
    struct musica *musica;
    int altura;
    struct treeAVLNode *esq;
    struct treeAVLNode *dir;
};

/*
 * Objetivo: Cria arvore AVL.
 * Params: void.
 * Return: retorna ponteiro Arvore AVL.
 * */
ArvAVL *createTreeAVL() {
  ArvAVL *root = (ArvAVL *) malloc(sizeof(ArvAVL));

  if (root != NULL) {
    *root = NULL;
  }

  return root;
}

/*
 * Objetivo: Da free em um nó arvore. Limpa o nó da esquerda e depois o da direita e por ultimo free na raiz.
 * Params: ponteiro para nó de treeAVLNode.
 * Return: void.
 * */
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

/*
 * Objetivo: Pegar a altura do nó.
 * Params: ponteiro para nó de treeAVLNode.
 * Return: Int altura do nó arvore
 * */
int getNodeHigh(struct treeAVLNode *arvAVL) {
  if (arvAVL == NULL)
    return -1;
  else
    return arvAVL->altura;
}

/*
 *  Objetivo: Verifica se a arvore esta balanceada. Faz a diferença entre a altura do lado esquerdo com o lado direito.
 *  Params: ponteiro para nó de treeAVLNode.
 *  Return: Int altura do nó arvore
 * */
int getBalancefactor(struct treeAVLNode *arvAVL) {
  return labs(getNodeHigh(arvAVL->esq) - getNodeHigh(arvAVL->dir));
}

/*
 *  Objetivo: Compara dois inteiros e retornar o maior.
 *  Params: x: int y: int
 *  Return: int
 * */
int isHigher(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}
/*
 * Objetivo: Verifica se a arvore esta null
 * Params: ponteiro de ArvAVL
 * Return: 1 se for null e 0 se n for null.
 * */
int isTreeAVLEmpty(ArvAVL *root) {
  if (root == NULL)
    return 1;
  if (*root == NULL)
    return 1;
  return 0;
}

/*
 * Objetivo: Returna total de nós da arvore
 * Params: ponteiro para ArvAVL
 * Return o numero de nos do SAE + SAD
 * */
int totalNO_ArvAVL(ArvAVL *root) {
  if (root == NULL)
    return 0;
  if (*root == NULL)
    return 0;
  int alt_esq = totalNO_ArvAVL(&((*root)->esq));
  int alt_dir = totalNO_ArvAVL(&((*root)->dir));
  return (alt_esq + alt_dir + 1);
}

/*
 * Objetivo: Verifica qual lado é mais alto e retorna ele + 1
 * Params: ponteiro para ArvAVL
 * Return: lado mais alto + 1
 * */
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

/*
 * Trata raiz, percorre SAE, percorre SAD
 * */
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

/*
 * Percorre SAE, trata raiz, percorre SAD
 * */
void emOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    emOrdem_ArvAVL(&((*raiz)->esq));

    printf("Musica id %d\n", (*raiz)->musica->id);
    emOrdem_ArvAVL(&((*raiz)->dir));
  }
}

/*
 * Percorre SAE, percorre SAD, trata raiz
 * */
void posOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    posOrdem_ArvAVL(&((*raiz)->esq));
    posOrdem_ArvAVL(&((*raiz)->dir));
    printf("%d\n", (*raiz)->musica->id);
  }
}
/*
 * Objetivo: encotrar a musica.
 * Params: ponteiro para ArvAVL e o valor do id ser encontrado.
 * Return: Null caso nao encontre ou retorna a musica.
 * */
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

/* Objetivo: Rotação simples a Direita. Balancear a arvore para direita.
 * Params: ponteiro de ArvAVL
 * Return: void
 * */
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

/*
 * Rotação simples a Esquerda. Balancear a arvore para direita.
 * Params: ponteiro de ArvAVL
 * Return: void
 * */
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

/*
 * Rotação dupla Direita. Quando os fatores estiverem com sinais diferentes.
 * Params: ponteiro de ArvAVL
 * Return: void
 * */
void RotacaoLR(ArvAVL *A) {//LR
  RotacaoRR(&(*A)->esq);
  RotacaoLL(A);
}

/*
 * Rotação dupla Esqueda. Quando os fatores estiverem com sinais diferentes.
 * Params: ponteiro de ArvAVL
 * Return: void
 * */
void RotacaoRL(ArvAVL *A) {//RL
  RotacaoLL(&(*A)->dir);
  RotacaoRR(A);
}


/*
 * Objetivo: Insere um nó de musica na arvoreAVL e rebalanceia após inserção
 * Params: ponteiro de ArvAVL e ponteiro de musica
 * Return: 0 se não inseriu e 1 se inseriu.
 * */
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

/*
 * Objetivo: encotrar a folha a esquerda.
 * Params: ponteiro de ArvAVL
 * Return: Nó de ArvAVL
 * */
ArvAVL procuraAVLr(ArvAVL atual) {
  ArvAVL arvAVL1 = atual;
  ArvAVL arvAVL2 = atual->esq;
  while (arvAVL2 != NULL) {
    arvAVL1 = arvAVL2;
    arvAVL2 = arvAVL2->esq;
  }
  return arvAVL1;
}

/*
 * Objetivo: Remover musica
 * Params: ponteiro de ArvAVL e int do id da musica
 * Return: 0 se não encontrou ou 1 se removeu.
 * */
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
      struct treeAVLNode *temp = procuraAVLr((*raiz)->dir);
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
