#pragma once
#include "linked_list.h"

#define MAX 40
#define CPF_SIZE 11
#define PATH_PESSOA "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_entrada\\pessoas.txt"

struct Pessoa {  
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char cidade[MAX+1];
    int passagensPolicia;
    char inadimplencias[MAX][MAX];
    int nInadimplencias;
};

void lerArquivoPessoas(Celula *&pessoas);
Celula *buscarPessoa(Celula *lst, char CPF[CPF_SIZE+1]);
