#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void menuUso(char codigo[COD_VIATURA]);
bool temChamadas(Celula *viaturaAtual, Celula *chamadasEmAndamento);

void viaturaEmUso(Celula *&viaturaAtual, Celula *pessoas, Celula *chamadasEmAndamento) {
    char codigo[COD_VIATURA];
    int op;
    
    menuUso(codigo);

    if(strcmp(codigo, ((Viatura *)viaturaAtual->d)->codigo) == 0) {
        if(temChamadas(viaturaAtual, chamadasEmAndamento)) {
            viaturaChamada(pessoas, viaturaAtual);
        } else {
            viaturaRonda(op);
        }
    } else {
        printf("Código não condiz com a viatura atual\n");
    }
}

void menuUso(char codigo[COD_VIATURA]) {
    printf("\nSPM - Viatura em Uso\n\n");
    printf("Identificador da Viatura: ");
    scanf("%s", codigo);
}