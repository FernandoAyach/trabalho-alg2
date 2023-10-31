#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/fila.h"
#include "../../include/viatura.h"

void chamadaTipoPolicia(int &op, Chamada *chamada);
void chamadaPrioridade(int &op, Chamada *chamada);
void construirChamada(Chamada *chamada, char *descricao, char *localizacao);

void criarChamadaPolicial(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas
) {
    int op;
    char *descricao = (char *) calloc(1, sizeof(char));
    char *localizacao = (char *) calloc(1, sizeof(char));
    Chamada *chamada = (Chamada *) calloc(1, sizeof(Chamada));

    chamadaTipoPolicia(op, chamada);
    chamadaPrioridade(op, chamada);
    construirChamada(chamada, descricao, localizacao);

    if(chamada->prioritaria) enfileirar(ichamadasP, fchamadasP, chamada);
    else enfileirar(ichamadasNP, fchamadasNP, chamada);
}

void chamadaTipoPolicia(int &op, Chamada *chamada) {
    do {
        printf("\nSPM - COPOM\n\n");
        printf("Policia Normal - 1        Especializada - 2\n");
        scanf("%d", &op);
    } while(op != 1 && op != 2);

    if(op == 1) strcpy(chamada->tipoPolicia, TIPO_REGULAR);
    else strcpy(chamada->tipoPolicia, TIPO_ESPECIALIZADA);
}

void chamadaPrioridade(int &op, Chamada *chamada) {
    if(op == 1) {
        do {
            printf("Prioritária - 1        Não Prioritária - 2\n");
            scanf("%d", &op);
        } while(op != 1 && op != 2);

        if(op == 1) chamada->prioritaria = true;
        else chamada->prioritaria = false;
    } else {
        chamada->prioritaria = true;
    }
}

void construirChamada(Chamada *chamada, char *descricao, char *localizacao) {
    printf("Viaturas necessárias: ");
    scanf("%d", &chamada->viaturasNecessarias);
    printf("Descrição: ");
    scanf(" %[^\n]", descricao);
    printf("Localização: ");
    scanf(" %[^\n]", localizacao);
    chamada->descricao = descricao;
    chamada->localizacao = localizacao;
}