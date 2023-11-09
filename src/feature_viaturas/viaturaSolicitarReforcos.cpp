#include <stdio.h>

#include "../../include/viatura.h"
#include "../../include/fila.h"

void viaturaSolicitarReforcos(Celula *&ireforcos, Celula *&freforcos, Celula *chamada) {
    int op; 

    do {
        printf("\nSPM - Viatura: Solicitar Reforços\n\n");
        printf("1 - Confirmar Solicitação de Reforços\n");
        printf("2 - Cancelar\n");
        scanf("%d", &op);

        if(op == 1) {
            enfileirar(ireforcos, freforcos, chamada->d);
            return;
        }
    } while(op != 2);
}