#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"

void menuNeutro(int &op);

void viaturaNeutro(Celula *viaturasEmUso, Celula *policiaisDoDia, Celula *pessoas) {
    int op;
    
    do {
        menuNeutro(op);
        if(op == 1) viaturaChamada(pessoas);
    } while(op != 2);
    
}

void menuNeutro(int &op) {
    printf("\nSPM - Viatura Estado Neutro\n\n");
    printf("1 - Apto para atender ocorrência\n");
    printf("2 - Cancelar Embarcação\n");
    scanf("%d", &op);
}