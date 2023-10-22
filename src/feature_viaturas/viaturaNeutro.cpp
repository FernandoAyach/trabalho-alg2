#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"

void menuNeutro();

void viaturaNeutro(char **nomePMs) {
    int op;
    menuNeutro();
    scanf("%d", &op);

    if(op == 2) return;
    
    viaturaRonda();
}

void menuNeutro() {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
}