#pragma once
#include "linked_list.h"

#define MAX 40
#define CPF_SIZE 11
#define PATH_POLICIAL "arquivos_entrada\\policiais.txt"
#define PATH_RELATORIO "arquivos_saida\\relatorio.txt"
#define OFICIAL "Oficial"
#define COMANDANTE "Comandante Geral"
#define PM "PM"

struct Policial {
    char nome[MAX+1];
    char CPF[CPF_SIZE+1];
    char nomeGuerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
    bool trabalhou = false;
};

void lerArquivoPoliciais(Celula *&policiais);
Celula *buscarPolicial(Celula *lst, char nomeGuerra[MAX+1]);
Celula* login(Celula *policiais, const char cargo[]);
void telaPm(Celula *policial, Celula *chamadasFinalizadas, Celula *viaturas);
void telaOficial(Celula *chamadasFinalizadas, Celula *viaturas, Celula *policiais);
void telaComandante(Celula *chamadasFinalizadas, Celula *viaturas);
void gerarRelatorio(Celula *viaturas, Celula *policiais);