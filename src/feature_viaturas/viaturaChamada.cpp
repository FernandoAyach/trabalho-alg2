#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"
#include "../../include/copom.h"

void menuChamada(char *&descricao, char *&localizacao, int &acaoPolicial);
void menuOcorrencia(int &op);

void viaturaChamada(Celula *pessoas, Celula *&viaturaAtual, Celula *chamada) {
    char *descricao = ((Chamada *)chamada->d)->descricao;
    char* localizacao = ((Chamada *)chamada->d)->localizacao;
    int acaoPolicial, op;

    menuChamada(descricao, localizacao, acaoPolicial);
    if(acaoPolicial == 2) return;

    do {
        menuOcorrencia(op);
        if(op == 1) {
            viaturaBuscarCpf(pessoas);
        } else if(op == 2) {
            viaturaSolicitarReforcos();
        } else if(op == 3) {
            ((Viatura *)viaturaAtual->d)->status = INDISPONIVEL;
            viaturaPrisao(pessoas, op);
        }
    } while(op != 4); 
}

void menuChamada(char *&descricao, char *&localizacao, int &acaoPolicial) {
    printf("\nSPM - Viatura Chamada Policial\n\n");
    printf("Descrição: ");
    printf("%s\n", descricao);
    printf("Localização: ");
    printf("%s\n", localizacao);
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

