#pragma once
#include "linked_list.h"

#define MAX 40
#define CPF_SIZE 11
#define PATH_PESSOA "arquivos_entrada\\pessoas.txt"

struct Pessoa {  
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char cidade[MAX+1];
    int idade;
    int passagensPolicia;
    char passagens[MAX][MAX];
    int nInadimplencias;
    char inadimplencias[MAX][MAX];
};

void lerArquivoPessoas(Celula *&pessoas);
Celula *buscarPessoa(Celula *lst, char CPF[CPF_SIZE+1]);
