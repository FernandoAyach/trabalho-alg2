#pragma once

#define MAX 40
#define CPF_SIZE 11

struct Pessoa {  
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char cidade[MAX+1];
    int passagensPolicia;
    char *nomesI[MAX];
};

void lerArquivoPessoas(Pessoa *&pessoas);

