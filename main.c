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

Arvore criarNo(char info, Arvore esquerdo, Arvore direito){
    Arvore arvore = (Arvore) malloc(sizeof(Arvore));
	if(arvore!=NULL){
        arvore->info = info;
        arvore->esq = esquerdo;
        arvore->dir = direito;
        printf("No adicionado: %c\n", info);
        return arvore;
	}
	return false;
}




int main() {
    /*
	Arvore A = iniciarArvore();
    Arvore D = criarNo('d', iniciarArvore(), iniciarArvore());
    Arvore E = criarNo('e', iniciarArvore(), iniciarArvore());
    Arvore F = criarNo('f', iniciarArvore(), iniciarArvore());
    Arvore B = criarNo('b', iniciarArvore(), D);
    Arvore C = criarNo('c', E, F);
    A = criarNo('a', B, C);

    */
    //Exercicio:
    Arvore C = iniciarArvore();
    Arvore A = criarNo('a', iniciarArvore(), iniciarArvore());
    Arvore B = criarNo('b', A, iniciarArvore());
    Arvore E = criarNo('e', iniciarArvore(), iniciarArvore());
    Arvore D = criarNo('d', iniciarArvore(), E);
    C = criarNo('c', B, D);

    return 0;
}
