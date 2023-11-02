#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void menuNeutro(int &op);
Celula* obterChamada(Celula *viaturaAtual, Celula *chamadasEmAndamento);

void viaturaNeutro(Celula *&viaturaAtual, Celula *pessoas, Celula *chamadasEmAndamento) {
    int op;
    
    do {
        menuNeutro(op);
        if(op == 1) {
           Celula *chamada = obterChamada(viaturaAtual, chamadasEmAndamento);
            if(chamada != NULL) {
                ((Viatura *)viaturaAtual->d)->status = CHAMADA;
                ((Viatura *)viaturaAtual->d)->nOcorrencias++;
                viaturaChamada(pessoas, viaturaAtual, chamada, chamadasEmAndamento);
            } else {
                ((Viatura *)viaturaAtual->d)->status = LIVRE;
                viaturaRonda(op);
                if(op == 3) return;
            }
        }
    } while(op != 2);

    
    //desalocar policiais viatura
}

void menuNeutro(int &op) {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
    scanf("%d", &op);
}

Celula* obterChamada(Celula *viaturaAtual, Celula *chamadasEmAndamento) {
    while(chamadasEmAndamento != NULL) {
        for(int i = 0; i < ((Chamada *)chamadasEmAndamento->d)->viaturasNecessarias; i++) {
            if(
                strcmp(
                    ((Viatura *)viaturaAtual->d)->codigo, 
                    ((Chamada *)chamadasEmAndamento->d)->codigoViatura[i]
                ) == 0
            ) return chamadasEmAndamento;
        }
        chamadasEmAndamento = chamadasEmAndamento->prox;
    }
    return NULL;
}