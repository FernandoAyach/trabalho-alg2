#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/pessoa.h"
#include "../../include/linked_list.h"

int fscanfPessoa(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char cidade[MAX+1],
    int &passagensPolicia,
    char inadimplencias[MAX][MAX]
);

void lerArquivoPessoas(Celula *&pessoas) {
    FILE *pArq;
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char cidade[MAX+1];
    int passagensPolicia;
    char inadimplencias[MAX][MAX];
    int x;

    pArq = fopen(PATH_PESSOA, "r");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir pessoas.txt\n");
        return;
    }

    x = fscanfPessoa(pArq, nome, CPF, cidade, passagensPolicia, inadimplencias);  
    while(feof(pArq) == 0) {
        Pessoa *pessoa = (Pessoa *) calloc(1, sizeof(Pessoa));
        strcpy(pessoa->nome, nome);
        strcpy(pessoa->CPF, CPF);
        strcpy(pessoa->cidade, cidade);
        pessoa->passagensPolicia = passagensPolicia;
        pessoa->nInadimplencias = x;
        
        for(int i = 0; i < x; i++) {
            strcpy(pessoa->inadimplencias[i], inadimplencias[i]);
        }
        
        inserirInicio(pessoas, pessoa);
        x = fscanfPessoa(pArq, nome, CPF, cidade, passagensPolicia, inadimplencias);  
    }
}

int fscanfPessoa(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char cidade[MAX+1],
    int &passagensPolicia,
    char inadimplencias[MAX][MAX]
) { 
    int ni, k = 0;
    fscanf(pArq, " %[^\n]", nome);
    fscanf(pArq, " %s", CPF);
    fscanf(pArq, " %[^\n]", cidade);
    fscanf(pArq, "%d", &passagensPolicia);

    for(int j = 0; j < 2; j++) {
        fscanf(pArq, "%d", &ni);
       
        for(int i = 0; i < ni; i++) {
            fscanf(pArq, " %[^\n]", inadimplencias[k]);
            k++;
        }
    }
    return k;
}

