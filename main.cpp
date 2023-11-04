#include <stdio.h>
#include <stdlib.h>

#include "include/viatura.h"
#include "include/policial.h"
#include "include/pessoa.h"
#include "include/copom.h"
#include "include/linked_list.h"
#include "include/fila.h"

void menu();
void lerArquivos(Celula *&viatura, Celula *&policiais, Celula *&pessoas);

int main() {
    int op;
    Celula *viaturas = NULL;
    Celula *policiais = NULL;
    Celula *pessoas = NULL;

    Celula *ichamadasP = NULL, *fchamadasP = NULL, *ichamadasNP = NULL, *fchamadasNP = NULL;
    Celula *chamadasEmAndamento = NULL;

    Celula *viaturaAtual = NULL;

    lerArquivos(viaturas, policiais, pessoas);

    do {
        menu();
        scanf("%d", &op);

        if(op == 1) {
            viaturaLogin(
                viaturas, policiais, pessoas, viaturaAtual, chamadasEmAndamento, 
                ichamadasP, fchamadasP,ichamadasNP, fchamadasNP
            );
        } else if(op == 2) {
            distribuirChamada(
                ichamadasP, fchamadasP, ichamadasNP, fchamadasNP, viaturas, chamadasEmAndamento
            );
            viaturaEmUso(viaturaAtual, pessoas, chamadasEmAndamento, viaturas);
        } else if(op == 3) {
            criarChamadaPolicial(ichamadasP,fchamadasP,ichamadasNP, fchamadasNP, viaturas);
            distribuirChamada(
                ichamadasP, fchamadasP, ichamadasNP, ichamadasNP, 
                viaturas, chamadasEmAndamento
            );
        }
    } while(op != 0);

    desalocar(viaturas);
    desalocar(policiais);
    desalocar(pessoas);
    desalocar(ichamadasP);
    desalocar(ichamadasNP);
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
    //imprimirViaturas(viaturas);
    //imprimirPoliciais(policiais);
    //imprimirPessoas(pessoas);
}