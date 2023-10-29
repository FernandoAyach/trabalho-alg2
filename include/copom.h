#pragma once

#include "linked_list.h"
#include  "viatura.h"

struct Chamada {
    char tipoPolicia[TIPO_VIATURA];
    bool prioritaria;
    int viaturasNecessarias;
    char *descricao;
    char *localizacao;
    char codigoViatura[COD_VIATURA];
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