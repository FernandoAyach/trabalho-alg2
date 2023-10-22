#pragma once
#include "linked_list.h"

#define COD_VIATURA 3
#define TIPO_VIATURA 13
#define PATH_VIATURA "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_entrada\\viaturas.txt"

struct Viatura {
    char codigo[COD_VIATURA+1];
    char tipo[TIPO_VIATURA+1];
};

void lerArquivoViaturas(Celula *&viaturas);

void viaturaLogin(Viatura *&viaturaAtual);
void viaturaNeutro(char **nomePMs);
void viaturaRonda();
