#include <stdio.h>
#include <stdlib.h>
#include "../../include/viatura.h"

void menuChamada(char *&descricao, char *&localizacao, int &acaoPolicial);
void menuOcorrencia(int &op);

void viaturaChamada(Celula *pessoas) {
    char *descricao = (char *) calloc(1, sizeof(char)), *localizacao = (char *) calloc(1, sizeof(char));
    int acaoPolicial, op;

    menuChamada(descricao, localizacao, acaoPolicial);
    if(acaoPolicial == 2) return;

   

    do {
        menuOcorrencia(op);
        if(op == 1) {
            viaturaBuscarCpf(pessoas);
        }
    } while(op != 4);
    
    
}

void menuChamada(char *&descricao, char *&localizacao, int &acaoPolicial) {
    printf("\nSPM - Viatura Chamada Policial\n\n");
    printf("Descrição: ");
    scanf(" %[^\n]", descricao);
    printf("Localização: ");
    scanf(" %[^\n]", localizacao);
    printf("Confirmada Ação Policial - 1    Ação Policial Dispensada - 2\n");
    scanf("%d", &acaoPolicial);
}

void menuOcorrencia(int &op) {
    printf("\nSPM - Viatura Ocorrência\n\n");
    printf("1 - Pesquisar por CPF\n");
    printf("2 - Solicitar Reforços\n");
    printf("3 - Prisão em Andamento\n");
    printf("4 - Encerrar Ocorrência\n");
    scanf("%d", &op);
}

