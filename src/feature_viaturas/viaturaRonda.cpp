#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"

void menuRonda();

void viaturaRonda(int &back) {
    int op;

    do {
        menuRonda();
        scanf("%d", &op);
    } while(op != 1);

    back = 3;
}

void menuRonda() {
    printf("\nSPM - Viatura em modo Ronda\n\n");
    printf("Viatura direcionada para rondas, no aguardo de chamadas policiais.\n");
    printf("1 - Voltar para o menu principal\n");
}