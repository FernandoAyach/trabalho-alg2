#include <stdio.h>
#include <stdlib.h>

#include "include/viatura.h"
#include "include/policial.h"

void menu();

int main() {
    int op;
    Viatura *viatura = NULL;
    Policial *policiais = NULL;

    do {
        menu();
        scanf("%d", &op);

        if(op == 1) {
            viaturaLogin(viatura);
        }
        

    } while(op != 0);
}

void menu() {
    printf("\nSPM - Funcionalidades\n\n");
    printf("1 - Viatura Login        2 - Viatura em uso\n");
    printf("3 - COPOM\n");
    printf("4 - Policial Militar\n");
    printf("5 - Oficial\n");
    printf("6 - Comandante Geral     0 - Encerrar Programa\n");
}