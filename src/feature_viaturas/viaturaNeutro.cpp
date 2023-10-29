#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void menuNeutro(int &op);
bool temChamadas(Celula *viaturaAtual, Celula *chamadasEmAndamento);

void viaturaNeutro(Celula *&viaturaAtual, Celula *pessoas, Celula *chamadasEmAndamento) {
    int op;
    
    do {
        menuNeutro(op);
        if(op == 1) {
            if(temChamadas(viaturaAtual, chamadasEmAndamento)) {
                ((Viatura *)viaturaAtual->d)->status = CHAMADA;
                ((Viatura *)viaturaAtual->d)->nOcorrencias++;
                viaturaChamada(pessoas, viaturaAtual);
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

bool temChamadas(Celula *viaturaAtual, Celula *chamadasEmAndamento) {
    while(chamadasEmAndamento != NULL) {
        if(
            strcmp(
                ((Viatura *)viaturaAtual->d)->codigo, 
                ((Chamada *)chamadasEmAndamento->d)->codigoViatura
            ) == 0
        ) return true;
    }
    return false;
}