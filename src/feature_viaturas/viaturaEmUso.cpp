#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void menuUso(char codigo[COD_VIATURA]);
Celula* obterChamada(Celula *viaturaAtual, Celula *chamadasEmAndamento);

void viaturaEmUso(
    Celula *&viaturaAtual, Celula *pessoas, Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&chamadasFinalizadas
) {
    char codigo[COD_VIATURA];
    int op;
    
    menuUso(codigo);

    if(viaturaAtual == NULL) {
        printf("Essa viatura não está em uso!\n");
        return;
    }

    if(strcmp(codigo, ((Viatura *)viaturaAtual->d)->codigo) == 0) {

        if(((Viatura *)viaturaAtual->d)->status == INDISPONIVEL) {
            op = 7;
            viaturaPrisao(pessoas, op);
            return;
        }

        Celula *chamada = obterChamada(viaturaAtual, chamadasEmAndamento);
        if(chamada != NULL) {
            ((Viatura *)viaturaAtual->d)->status = CHAMADA;
            viaturaChamada(
                pessoas, viaturaAtual, chamada, chamadasEmAndamento, viaturas, chamadasFinalizadas
            );
            return;
        }

        viaturaRonda(op);

    } else {
        printf("Código não condiz com a viatura atual\n");
    }
}

void menuUso(char codigo[COD_VIATURA]) {
    printf("\nSPM - Viatura em Uso\n\n");
    printf("Identificador da Viatura: ");
    scanf("%s", codigo);
}