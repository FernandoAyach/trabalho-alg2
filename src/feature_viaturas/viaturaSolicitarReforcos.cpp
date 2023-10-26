#include <stdio.h>

#include "../../include/viatura.h"

void viaturaSolicitarReforcos() {
    int op; 

    do {
        printf("\nSPM - Viatura: Solicitar Reforços\n\n");
        printf("1 - Confirmar Solicitação de Reforços\n");
        printf("2 - Cancelar\n");
        scanf("%d", &op);

        if(op == 1) {
            //encaminhar pedido de reforço pro COPOM
            return;
        }
    } while(op != 2);
}