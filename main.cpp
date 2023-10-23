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
    Celula *viaturas = NULL;
    Celula *policiais = NULL;
    Celula *pessoas = NULL;

    Celula *viaturasEmUso = NULL;
    Celula *policiaisDoDia = NULL;

    lerArquivos(viaturas, policiais, pessoas);

    do {
        menu();
        scanf("%d", &op);

        if(op == 1) {
            viaturaLogin(viaturas, policiais, viaturasEmUso, policiaisDoDia);
        }
        

    } while(op != 0);

    desalocar(viaturas);
    desalocar(policiais);
    desalocar(pessoas);
}

void menu() {
    printf("\nSPM - Funcionalidades\n\n");
    printf("1 - Viatura Login        2 - Viatura em uso\n");
    printf("3 - COPOM\n");
    printf("4 - Policial Militar\n");
    printf("5 - Oficial\n");
    printf("6 - Comandante Geral     0 - Encerrar Programa\n");
}

void lerArquivos(Celula *&viaturas, Celula *&policiais, Celula *&pessoas) {
    lerArquivoViaturas(viaturas);
    lerArquivoPoliciais(policiais);
    lerArquivoPessoas(pessoas);
    //imprimirViaturas(viatura);
    //imprimirPoliciais(policiais);
    //imprimirPessoas(pessoas);
}