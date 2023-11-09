#pragma once

#include "linked_list.h"
#include "viatura.h"

#define PATH_BOLETIM "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_saida\\boletins.txt"
#define PATH_OFICIO "D:\\Usuario\\Desktop\\Central\\Codes\\ufms\\alg2\\spm\\arquivos_saida\\oficio_ocorrencias.txt"

struct Chamada {
    char tipoPolicia[TIPO_VIATURA+1];
    bool prioritaria;
    int viaturasNecessarias;
    char *descricao;
    char *localizacao;
    char **codigoViatura;
    bool temBoletim = false;
    char *boletim;
    int nPresos = 0;
    Celula **presos;
};

void criarChamadaPolicial(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas
);

void distribuirChamada(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas, Celula *&chamadasEmAndamento
);

void removerChamada(
    Celula *&chamadasEmAndamento, 
    char codigo[COD_VIATURA],
    Celula *viaturas,
    Celula *&chamadasFinalizadas
);

void registrarBoletim(Chamada *chamada);
void atualizarBoletins(Celula *chamadasFinalizadas);
void gerarOficio(Celula *chamadasFinalizadas, Celula *viaturas);