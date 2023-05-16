#include <stdio.h>
#include <stdlib.h>

struct arv{
	char info;
	struct arv * esq;
	struct arv * dir;
};

typedef struct arv * Arvore;

Arvore iniciarArvore(){
    return NULL;
}

void inserir(Arvore * raiz, char info){
    if((*raiz) == NULL){
        (*raiz) = (Arvore) malloc(sizeof(Arvore));
        (*raiz)->esq = iniciarArvore();
        (*raiz)->dir = iniciarArvore();
        (*raiz)->info = info;
    }else{
        if (info > (*raiz)->info){
            inserir(&(*raiz)->dir, info);
        }else {
            inserir(&(*raiz)->esq, info);
        }
    }

}

int tamanhoArvore(Arvore raiz){
    if(raiz == NULL) {
        return -1;
    }else {
        int esq = tamanhoArvore(raiz->esq)+1;
        int dir = tamanhoArvore(raiz->dir)+1;
        return esq>dir? esq:dir;
    }
}


void printPosOrdem(Arvore raiz){
    if(raiz!=NULL){
        printPosOrdem((raiz->esq));
        printPosOrdem((raiz->dir));
        printf("%c\n", raiz->info);
    }
}

void printPreOrdem(Arvore raiz){
    if(raiz!=NULL){
        printf("%c\n", raiz->info);
        printPreOrdem((raiz->esq));
        printPreOrdem((raiz->dir));
    }
}

void printOrdemSimetrica(Arvore raiz){
    if(raiz!=NULL){
        printOrdemSimetrica((raiz->esq));
        printf("%c\n", raiz->info);
        printOrdemSimetrica((raiz->dir));
    }
}

int main() {

    Arvore C = iniciarArvore();
    inserir(&C, 'c');
    inserir(&C, 'b');
    inserir(&C, 'd');
    inserir(&C, 'a');
    inserir(&C, 'e');
    printOrdemSimetrica(C);
    printPosOrdem(C);
    printPreOrdem(C);

    printf("%d", tamanhoArvore(C));
    return 0;

}
