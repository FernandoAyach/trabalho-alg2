#include <stdlib.h>

#include "../../include/fila.h"

void enfileirar(Celula *&i, Celula *&f, void *d) {
    Celula *cn = (Celula *) calloc(1, sizeof(Celula));
    cn->d = d;

    if(i == NULL) {
        i = f = cn;
        return;
    }

    f->prox = cn;
    f = cn;
}

Celula* desenfileirar(Celula *&i, Celula *&f) {
    Celula *aux, *removido;

    if(i == NULL) return NULL;

    aux = i;
    removido = aux;
    i = i->prox;
    free(aux);
    
    if(i == NULL) {
        f = NULL;
    }
    return removido;
}