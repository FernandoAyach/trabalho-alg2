#include <stdio.h>
#include <stdlib.h>

#include "include/viatura.h"
#include "include/policial.h"
#include "include/pessoa.h"
#include "include/linked_list.h"

void menu();
void lerArquivos(Celula *&viatura, Celula *&policiais, Celula *&pessoas);

int main() {
    int op;
    Celula *viatura = NULL;
    Celula *policiais = NULL;
    Celula *pessoas = NULL;

    lerArquivos(viatura, policiais, pessoas);
    //imprimirViaturas(viatura);

    do {
        menu();
        scanf("%d", &op);

        if(op == 1) {
            //viaturaLogin((Viatura *)viatura);
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

void lerArquivos(Celula *&viatura, Celula *&policiais, Celula *&pessoas) {
    lerArquivoViaturas(viatura);
    //lerArquivoPoliciais(policiais);
    //lerArquivoPessoas(pessoas);
}