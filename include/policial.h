#pragma once

#define MAX 40
#define CPF_SIZE 11

struct Policial {
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char nomeGuerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
};