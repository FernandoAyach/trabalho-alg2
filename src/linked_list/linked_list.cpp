#include <stdlib.h>
#include <stdio.h>
#include "../../include/viatura.h"
#include "../../include/policial.h"
#include "../../include/pessoa.h"
#include "../../include/linked_list.h"

void inserirInicio(Celula *&lst, void *d) {
    Celula *n = (Celula *) calloc(1, sizeof(Celula));
    n->d = d;

    n->prox = lst;
    lst = n;
}

void imprimirViaturas(Celula *lst) {
    while(lst != NULL) {
        printf("Viatura %s %s\n", ((Viatura *)lst->d)->codigo, ((Viatura *)lst->d)->tipo);
        lst = lst->prox;
    }
}

void imprimirPoliciais(Celula *lst) {
    while(lst != NULL) {
        printf("Policial %s %s\n", ((Policial *)lst->d)->nome, ((Policial *)lst->d)->nomeGuerra);
        lst = lst->prox;
    }
}

void imprimirPessoas(Celula *lst) {
    while(lst != NULL) {
        printf("Pessoa %s %d\n", ((Pessoa *)lst->d)->nome, ((Pessoa *)lst->d)->passagensPolicia);
        lst = lst->prox;
    }
}

void desalocar(Celula *&lst) {
    Celula *aux;
    while(lst != NULL) {
        aux = lst;
        free(aux);
        lst = lst->prox;
    }
}