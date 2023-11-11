#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"
#include "../../include/linked_list.h"

void fscanfPolicial(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char nomeGuerra[MAX+1],
    char cidade[MAX+1],
    int &idade,
    char cargo[MAX+1],
    char senha[MAX+1]
);

void lerArquivoPoliciais(Celula *&policiais) {
    FILE *pArq;
    char *nome = (char *) calloc(MAX, sizeof(char));
    char CPF[CPF_SIZE+1];
    char nomeGuerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];

    pArq = fopen(PATH_POLICIAL, "r");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir policiais.txt\n");
        return;
    }

    Policial *policial;
    fscanfPolicial(pArq, nome, CPF, nomeGuerra, cidade, idade, cargo, senha);  
    while(feof(pArq) == 0) {
        policial = (Policial *) calloc(1, sizeof(Policial));
        strcpy(policial->nome, nome);
        strcpy(policial->CPF, CPF);
        strcpy(policial->nomeGuerra, nomeGuerra);
        strcpy(policial->cidade, cidade);
        policial->idade = idade;
        strcpy(policial->cargo, cargo);
        strcpy(policial->senha, senha);

        inserirFim(policiais, policial);
        fscanfPolicial(pArq, nome, CPF, nomeGuerra, cidade, idade, cargo, senha);  
    }
    free(nome);
}

void fscanfPolicial(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char nomeGuerra[MAX+1],
    char cidade[MAX+1],
    int &idade,
    char cargo[MAX+1],
    char senha[MAX+1]
) { 
    fscanf(pArq, " %[^\n]", nome);
    fscanf(pArq, " %s", CPF);
    fscanf(pArq, " %[^\n]", nomeGuerra);
    fscanf(pArq, " %[^\n]", cidade);
    fscanf(pArq, "%d", &idade);
    fscanf(pArq, " %[^\n]", cargo);
    fscanf(pArq, " %s", senha);
}
