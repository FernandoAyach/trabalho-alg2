#pragma once

#include "linked_list.h"

#define COD_VIATURA 3
#define MAX_POLICIAIS 4
#define TIPO_VIATURA 13
#define PATH_VIATURA "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_entrada\\viaturas.txt"
#define TIPO_REGULAR "regular"
#define TIPO_ESPECIALIZADA "especializada"

enum Status {NAO_APTO, LIVRE, INDISPONIVEL, CHAMADA};

struct Viatura {
    char codigo[COD_VIATURA+1];
    char tipo[TIPO_VIATURA+1];
    int nPoliciais = 0;
    char *policiais[MAX_POLICIAIS];
    int nOcorrencias = 0;
    Status status = NAO_APTO;
};

Celula *buscarViatura(Celula *lst, char codigo[COD_VIATURA+1]);
void removerViatura(Celula *&lst, char codigo[COD_VIATURA+1]);

void lerArquivoViaturas(Celula *&viaturas);
void viaturaLogin(
    Celula *&viaturas, Celula *&policiais, Celula *pessoas, 
    Celula *&viaturaAtual, Celula *&chamadasEmAndamento,
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *&chamadasFinalizadas
);
void viaturaNeutro(
    Celula *&viaturaAtual, Celula *pessoas, Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *&chamadasFinalizadas
);
void viaturaRonda(int &op);
void viaturaChamada(
    Celula *pessoas, Celula *&viaturaAtual, Celula *chamada, 
    Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&chamadasFinalizadas
);
void viaturaBuscarCpf(Celula *pessoas);
void viaturaSolicitarReforcos();
void viaturaPrisao(Celula *pessoas, int &x, Celula *chamada, Celula *viaturaAtual);
void viaturaEmUso(
    Celula *&viaturaAtual, Celula *pessoas, Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&chamadasFinalizadas
);
