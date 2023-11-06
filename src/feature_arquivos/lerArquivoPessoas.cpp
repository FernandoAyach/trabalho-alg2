#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/pessoa.h"
#include "../../include/linked_list.h"

void fscanfPessoa(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char cidade[MAX+1],
    int &idade,
    int &passagensPolicia,
    char passagens[MAX][MAX],
    int &nInadimplencias,
    char inadimplencias[MAX][MAX]
);

void lerArquivoPessoas(Celula *&pessoas) {
    FILE *pArq;
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char cidade[MAX+1];
    int idade;
    int passagensPolicia;
    char passagens[MAX][MAX];
    int nInadimplencias;
    char inadimplencias[MAX][MAX];

    pArq = fopen(PATH_PESSOA, "r");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir pessoas.txt\n");
        return;
    }

    fscanfPessoa(
        pArq, nome, CPF, cidade, idade, passagensPolicia, passagens, nInadimplencias, inadimplencias
    );  
    while(feof(pArq) == 0) {
        Pessoa *pessoa = (Pessoa *) calloc(1, sizeof(Pessoa));
        strcpy(pessoa->nome, nome);
        strcpy(pessoa->CPF, CPF);
        strcpy(pessoa->cidade, cidade);
        pessoa->idade = idade;
        pessoa->passagensPolicia = passagensPolicia;
        pessoa->nInadimplencias = nInadimplencias;
        
        for(int i = 0; i < passagensPolicia; i++) {
            strcpy(pessoa->passagens[i], passagens[i]);
        }

        for(int i = 0; i < nInadimplencias; i++) {
            strcpy(pessoa->inadimplencias[i], inadimplencias[i]);
        }
        
        inserirFim(pessoas, pessoa);
        fscanfPessoa(
            pArq, nome, CPF, cidade, idade, passagensPolicia, passagens, nInadimplencias, inadimplencias
        );   
    }
}

void fscanfPessoa(
    FILE *pArq,
    char nome[MAX+1],
    char CPF[CPF_SIZE+1],
    char cidade[MAX+1],
    int &idade,
    int &passagensPolicia,
    char passagens[MAX][MAX],
    int &nInadimplencias,
    char inadimplencias[MAX][MAX]
) { 
    fscanf(pArq, " %[^\n]", nome);
    fscanf(pArq, " %s", CPF);
    fscanf(pArq, " %[^\n]", cidade);
    fscanf(pArq, "%d", &idade);
    fscanf(pArq, "%d", &passagensPolicia);

    for(int i = 0; i < passagensPolicia; i++) {
        fscanf(pArq, " %[^\n]", passagens[i]);
    }

    fscanf(pArq, "%d", &nInadimplencias);

    for(int i = 0; i < nInadimplencias; i++) {
        fscanf(pArq, " %[^\n]", inadimplencias[i]);
    }
}

