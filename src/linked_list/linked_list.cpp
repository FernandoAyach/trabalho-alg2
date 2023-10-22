#include <stdlib.h>
#include <stdio.h>
#include "../../include/viatura.h"
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