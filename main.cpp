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
    Celula *chamadasFinalizadas = NULL;

    Celula *viaturaAtual = NULL;

    lerArquivos(viaturas, policiais, pessoas);

    do {
        menu();
        scanf("%d", &op);

        if(op == 1) {
            viaturaLogin(
                viaturas, policiais, pessoas, viaturaAtual, chamadasEmAndamento, 
                ichamadasP, fchamadasP,ichamadasNP, fchamadasNP,
                chamadasFinalizadas
            );
        } else if(op == 2) {
            distribuirChamada(
                ichamadasP, fchamadasP, ichamadasNP, fchamadasNP, viaturas, chamadasEmAndamento
            );
            viaturaEmUso(viaturaAtual, pessoas, chamadasEmAndamento, viaturas, chamadasFinalizadas);
        } else if(op == 3) {
            criarChamadaPolicial(ichamadasP,fchamadasP,ichamadasNP, fchamadasNP, viaturas);
            distribuirChamada(
                ichamadasP, fchamadasP, ichamadasNP, ichamadasNP, 
                viaturas, chamadasEmAndamento
            );
        } else if(op == 4) {
            Celula *policial = login(policiais);
            printf("%s\n", ((Policial *)policial->d)->nome);
            if(policial != NULL) telaPm(policial, chamadasFinalizadas, viaturas);
        } else if(op == 5) {
            Celula *policial = login(policiais);
            printf("%s\n", ((Policial *)policial->d)->nome);
            if(policial != NULL) telaOficial(chamadasFinalizadas, viaturas);
        } else if(op == 6) {
            Celula *policial = login(policiais);
            printf("%s\n", ((Policial *)policial->d)->nome);
            if(policial != NULL) telaComandante(chamadasFinalizadas, viaturas);
        }
    } while(op != 0);

    desalocar(viaturas);
    desalocar(policiais);
    desalocar(pessoas);
    desalocar(ichamadasP);
    desalocar(ichamadasNP);
    desalocar(chamadasEmAndamento);
    desalocar(chamadasFinalizadas);
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
    //imprimirViaturas(viaturas);
    lerArquivoPoliciais(policiais);
    //imprimirPoliciais(policiais);
    lerArquivoPessoas(pessoas);
    //imprimirPessoas(pessoas);
}