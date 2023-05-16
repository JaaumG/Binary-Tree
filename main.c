#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

void printArvore(Arvore raiz, int ramo){
    if(raiz!=NULL){
        switch (ramo) {
            case 0:
                printf("Raiz: ");
                break;
            case 1:
                printf("Esquerda: ");
                break;
            default:
                printf("Direita: ");
                break;
        }
        printf("%c\n", raiz->info);
        printArvore((raiz->esq), 1);
        printArvore((raiz->dir),2);
    }
}


int main() {

    Arvore C = iniciarArvore();
    inserir(&C, 'c');
    inserir(&C, 'd');
    inserir(&C, 'b');
    inserir(&C, 'a');
    inserir(&C, 'e');
    printArvore(C, 0);
    return 0;

}
