#include <stdio.h>
#include <stdlib.h>

#include "../../include/fila.h"
#include "../../include/copom.h"
#include "../../include/pessoa.h"

void imprimirChamada(Celula *reforco, Celula *viaturas);
Celula* obterReforco(Celula *lista);

void verificarReforcos(Celula *&ireforcos, Celula *&freforcos, Celula *viaturas) {
    Celula *reforco = desenfileirar(ireforcos, freforcos);
    printf("Desenfileirou o reforço\n");
    int op;
    if(reforco != NULL) printf("\nSPM - Pedidos de reforço:\n");
    while(reforco != NULL) {
        imprimirChamada(reforco, viaturas);
        printf("1 - Confirmar pedido   2 - Negar pedido\n");
        scanf("%d", &op);

        if(op == 1) {
            printf("Reforço aceito\n");
            Celula *viatura = obterReforco(viaturas);
            if(viatura != NULL) {
                printf("Achou viatura! %s\n", ((Viatura *)viatura->d)->codigo);
                ((Viatura *)viatura->d)->status = REFORCO;
                ((Chamada *)reforco->d)->reforco = viatura;
                printf("Reforco: %s\n", ((Viatura *)((Chamada *)reforco->d)->reforco->d)->codigo);
            } else {
                printf("Não achou viaturas para reforço\n");
            }

        } else {
            printf("Reforço não aceito\n");
        }
        reforco = desenfileirar(ireforcos, freforcos);
        printf("Desenfileirou o reforço\n");
    }
}

void imprimirChamada(Celula *reforco, Celula *viaturas) {
    Chamada *chamada = (Chamada *)reforco->d;

    printf("\nTipo Policia: %s\n", chamada->tipoPolicia);
    printf("Descricao: %s\n", chamada->descricao);
    printf("Localizacao: %s\n", chamada->localizacao);
    printf("Policiais:\n");
    Celula *viatura;
    for(int i = 0; i < chamada->viaturasNecessarias; i++) {
        viatura = buscarViatura(viaturas, chamada->codigoViatura[i]);
        for(int j = 0; j < ((Viatura *)viatura->d)->nPoliciais; j++) {
            printf(" - %s;\n", ((Viatura *)viatura->d)->policiais[j]);
        }
    }
    if(chamada->nPresos != 0) printf("Presos:\n");
    
    for(int i = 0; i < chamada->nPresos; i++) {
        printf(
            "- %s, %s;\n", 
            ((Pessoa *)chamada->presos[i]->d)->nome, 
            ((Pessoa *)chamada->presos[i]->d)->CPF
        );
    }
    printf("\n");
}

Celula* obterReforco(Celula *lista) {
    while(lista != NULL) {
        if(((Viatura *)lista->d)->status == LIVRE) return lista;
        lista = lista->prox;
    }
    return NULL;
}