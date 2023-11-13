#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void menuNeutro(int &op);
Celula* obterChamada(Celula *viaturaAtual, Celula *chamadasEmAndamento);
void desalocarViatura(Celula *&viaturaAtual);
Celula* obterChamadaDoReforco(Celula *viaturaAtual, Celula *chamadasEmAndamento);

void viaturaNeutro(
    Celula *&viaturaAtual, Celula *pessoas, Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&ichamadasP, Celula *&fchamadasP, Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *&chamadasFinalizadas, Celula *&ireforcos, Celula *&freforcos
) {
    int op;
    
    do {
        menuNeutro(op);
        if(op == 1) {
            if(((Viatura *)viaturaAtual->d)->status == REFORCO) {
                Celula *chamada = obterChamadaDoReforco(viaturaAtual, chamadasEmAndamento);
                viaturaChamada(
                    pessoas, viaturaAtual, chamada, chamadasEmAndamento, viaturas, chamadasFinalizadas,
                    ireforcos, freforcos
                );
                return;
            }

            ((Viatura *)viaturaAtual->d)->status = LIVRE;
            imprimirChamadas(chamadasEmAndamento);
            distribuirChamada(
                ichamadasP, fchamadasP, ichamadasNP, fchamadasNP, viaturas, chamadasEmAndamento
            );
           
            Celula *chamada = obterChamada(viaturaAtual, chamadasEmAndamento);
            if(chamada != NULL) {
                ((Viatura *)viaturaAtual->d)->status = CHAMADA;
                viaturaChamada(
                    pessoas, viaturaAtual, chamada, chamadasEmAndamento, viaturas, chamadasFinalizadas,
                    ireforcos, freforcos
                );
                return;
            }
            
            ((Viatura *)viaturaAtual->d)->status = LIVRE;
            viaturaRonda(op);
            if(op == 3) return;
        }
    } while(op != 2);
}

void menuNeutro(int &op) {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
    scanf("%d", &op);
}

Celula* obterChamada(Celula *viaturaAtual, Celula *chamadasEmAndamento) {
    Celula *aux = chamadasEmAndamento;
    while(aux != NULL) {
        for(int i = 0; i < ((Chamada *)aux->d)->viaturasNecessarias; i++) {
            if(
                strcmp(
                    ((Viatura *)viaturaAtual->d)->codigo, 
                    ((Chamada *)aux->d)->codigoViatura[i]
                ) == 0
                && ((Chamada *)aux->d)->prioritaria
            ) return aux;
        }
        aux = aux->prox;
    }
    aux = chamadasEmAndamento;
    while(aux != NULL) {
        for(int i = 0; i < ((Chamada *)aux->d)->viaturasNecessarias; i++) {
            if(
                strcmp(
                    ((Viatura *)viaturaAtual->d)->codigo, 
                    ((Chamada *)aux->d)->codigoViatura[i]
                ) == 0
            ) return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
