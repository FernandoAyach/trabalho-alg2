#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"

void menuNeutro();

void viaturaNeutro(Celula *viaturasEmUso, Celula *policiaisDoDia, Celula *pessoas) {
    int op;
    menuNeutro();

    scanf("%d", &op);

    if(op == 1) {
        viaturaChamada(pessoas);
    } 
}

void menuNeutro() {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
}