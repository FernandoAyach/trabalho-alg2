#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"

void menuNeutro();

void viaturaNeutro(Celula *viaturasEmUso, Celula *policiaisDoDia) {
    int op;
    menuNeutro();

    imprimirViaturas(viaturasEmUso);
    imprimirPoliciais(policiaisDoDia);

    scanf("%d", &op);

    if(op == 2) return;
    
    //viaturaRonda();
}

void menuNeutro() {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
}