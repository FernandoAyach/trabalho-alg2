#pragma once
#include "linked_list.h"

#define MAX 40
#define CPF_SIZE 11
#define PATH_POLICIAL "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_entrada\\policiais.txt"

struct Policial {
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char nomeGuerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
};

void lerArquivoPoliciais(Celula *&policiais);

Celula *buscarPolicial(Celula *lst, char nomeGuerra[MAX+1]);