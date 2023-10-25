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
Celula *buscarViatura(Celula *lst, char codigo[COD_VIATURA+1]);

void viaturaLogin(
    Celula *&viaturas, Celula *&policiais, Celula *pessoas,
    Celula *&viaturasEmUso, Celula *&policiaisDoDia
);
void viaturaNeutro(Celula *viaturasEmUso, Celula *policiaisDoDia, Celula *pessoas);
void viaturaRonda();
void viaturaChamada(Celula *pessoas);
void viaturaBuscarCpf(Celula *pessoas);
