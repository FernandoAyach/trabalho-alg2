#include <stdlib.h>
#include <stdio.h>
#include <cstring>

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

Celula *buscarViatura(Celula *lst, char codigo[COD_VIATURA+1]) {
    while(lst != NULL && strcmp(((Viatura *)lst->d)->codigo, codigo) != 0) {
        lst = lst->prox;
    }
    return lst;
}

Celula *buscarPolicial(Celula *lst, char nomeGuerra[MAX+1]) {
    while(lst != NULL && strcmp(((Policial *)lst->d)->nomeGuerra, nomeGuerra) != 0) {
        lst = lst->prox;
    }
    return lst;
}

void imprimirViaturas(Celula *lst) {
    while(lst != NULL) {
        printf("Viatura %s\n", ((Viatura *)lst->d)->codigo);
        lst = lst->prox;
    }
}

void imprimirPoliciais(Celula *lst) {
    while(lst != NULL) {
        printf("Policial %s\n", ((Policial *)lst->d)->nomeGuerra);
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