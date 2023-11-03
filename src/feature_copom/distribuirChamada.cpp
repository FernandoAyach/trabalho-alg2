#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/fila.h"
#include "../../include/viatura.h"

void filtrarViaturas(Celula *lista, Celula *&preliminares, Chamada *chamada);
Viatura *obterViatura(Celula *preliminares);

void distribuirChamada(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas, Celula *&chamadasEmAndamento
) {
    Celula *preliminares = NULL, *finalistas = NULL, *aux, *c;
    int i;

    if(ichamadasP != NULL) c = ichamadasP;
    else c = ichamadasNP;

    if(c == NULL) {
        printf("Não há chamadas\n");
        return;
    }

    Chamada *chamada = (Chamada *)c->d;

    filtrarViaturas(viaturas, preliminares, chamada);
   
    if(preliminares == NULL) {
        printf("\nSem viaturas desse tipo disponíveis!\n");
        return;
    }

    for(i = 0; i < chamada->viaturasNecessarias && preliminares != NULL; i++) {
        Viatura *escolhida = obterViatura(preliminares);

        if(escolhida == NULL) {
            printf("\nSem viaturas disponíveis!\n");
            return;
        }
        inserirFim(finalistas, escolhida); 

        removerViatura(preliminares, escolhida->codigo);
    }

    if(i < chamada->viaturasNecessarias) {
        printf("\nNão foram encontradas viaturas suficientes!\n");
        desalocar(preliminares);
        desalocar(finalistas);
        return;
    }

    aux = finalistas;
    i = 0;
    chamada->codigoViatura = (char **) calloc(1, sizeof(char *));
    while(aux != NULL) {
        printf("%s\n", ((Viatura *)aux->d)->codigo);
        chamada->codigoViatura[i] = (char *) calloc(1, sizeof(char));
        strcpy(chamada->codigoViatura[i], ((Viatura *)aux->d)->codigo);
        i++;
        aux = aux->prox;
    }
    inserirFim(chamadasEmAndamento, chamada);

    if(ichamadasP != NULL) desenfileirar(ichamadasP, fchamadasP);
    else desenfileirar(ichamadasNP, fchamadasNP);
    
    desalocar(finalistas);
}

void filtrarViaturas(Celula *lista, Celula *&preliminares, Chamada *chamada) {
    while(lista != NULL) {
        if(
            ((Viatura *)lista->d)->status == LIVRE &&
            strcmp(chamada->tipoPolicia, ((Viatura *)lista->d)->tipo) == 0
        ) {
            inserirFim(preliminares, ((Viatura *)lista->d));
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
