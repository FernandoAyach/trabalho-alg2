#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/fila.h"

void filtrarViaturas(Celula *lista, Celula *&preliminares, Chamada *chamada);
Viatura *obterViatura(Celula *preliminares);

void distribuirChamada(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas, Celula *&chamadasEmAndamento
) {
    Celula *preliminares = NULL, *finalistas = NULL, *aux, *c;
    int i;

    if(ichamadasP != NULL) c = desenfileirar(ichamadasP,fchamadasP);
    else c = desenfileirar(ichamadasNP,fchamadasNP);

    Chamada *chamada = (Chamada *)c->d;

    filtrarViaturas(viaturas, preliminares, chamada);
   
    if(preliminares == NULL) {
        printf("Sem viaturas desse tipo disponíveis!\n");
        return;
    }

    for(i = 0; i < chamada->viaturasNecessarias; i++) {
        Viatura *escolhida = obterViatura(preliminares);

        if(escolhida == NULL) {
            printf("Sem viaturas disponíveis!\n");
            return;
        }
        inserirInicio(finalistas, escolhida);  
        removerViatura(preliminares, escolhida->codigo);
    }

    if(i < chamada->viaturasNecessarias) {
        printf("Não foram encontradas viaturas suficentes!\n");
        desalocar(preliminares);
        desalocar(finalistas);
        return;
    }

    aux = finalistas;
    i = 0;
    chamada->codigoViatura = (char **) calloc(1, sizeof(char *));
    while(aux != NULL) {
        ((Viatura *)aux->d)->status = CHAMADA;
        chamada->codigoViatura[i] = (char *) calloc(1, sizeof(char));
        strcpy(chamada->codigoViatura[i], ((Viatura *)aux->d)->codigo);
        inserirInicio(chamadasEmAndamento, chamada);
        i++;
        aux = aux->prox;
    }

    desalocar(preliminares);
    desalocar(finalistas);
}

void filtrarViaturas(Celula *lista, Celula *&preliminares, Chamada *chamada) {
    while(lista != NULL) {
        if(
            ((Viatura *)lista->d)->status == LIVRE &&
            strcmp(chamada->tipoPolicia, ((Viatura *)lista->d)->tipo) == 0
        ) {
            inserirInicio(preliminares, ((Viatura *)lista->d));
        }
        lista = lista->prox;
    }
}

Viatura *obterViatura(Celula *preliminares) {
    Viatura *escolhida = (Viatura *)preliminares->d;

    while(preliminares != NULL) {
        if(
            ((Viatura *)preliminares->d)->nOcorrencias < escolhida->nOcorrencias
        ) {
            escolhida = ((Viatura *)preliminares->d);
        }
        preliminares = preliminares->prox;
    }
    return escolhida;
}
