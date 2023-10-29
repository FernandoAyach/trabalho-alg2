#include <stdio.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/fila.h"

void distribuirChamada(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas, Celula *&chamadasEmAndamento
) {
    Celula *aux = viaturas;
    Celula *c = desenfileirar(ichamadasP,fchamadasP);
    Celula *preliminares = NULL;
    Chamada *chamada = (Chamada *)c->d;

    if(ichamadasP != NULL) {
        c = desenfileirar(ichamadasP,fchamadasP);
    } else {
        c = desenfileirar(ichamadasNP,fchamadasNP);
    }

    while(aux != NULL) {
        if(
            ((Viatura *)aux->d)->status == LIVRE &&
            strcmp(chamada->tipoPolicia, ((Viatura *)aux->d)->tipo) == 0
        ) {
            inserirInicio(preliminares, ((Viatura *)aux->d));
        }
        aux = aux->prox;
    }
    aux = preliminares;
    Viatura *escolhida = (Viatura *)preliminares->d;

    while(aux != NULL) {
        if(
            ((Viatura *)aux->d)->nOcorrencias < escolhida->nOcorrencias
        ) {
            escolhida = ((Viatura *)aux->d);
        }
        aux = aux->prox;
    }

    if(escolhida == NULL) {
        printf("Sem viaturas disponíveis!\n");
        return;
    }
    escolhida->status = CHAMADA;

    strcpy(chamada->codigoViatura, escolhida->codigo);
    inserirInicio(chamadasEmAndamento, chamada);
}
