#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"
#include "../../include/copom.h"

void coletarChamadasDoPolicial(
    Celula *policial, Celula *chamadasFinalizadas, Celula *&chamadasDoPolicial, Celula *viaturas
);

void fazerBoletins(Celula *chamadasDoPolicial, Celula *viaturas);
void imprimirChamadaDoPolicial(Celula *chamadaDoPolicial, Celula *viaturas);

void telaPm(Celula *policial, Celula *chamadasFinalizadas, Celula *viaturas) {
    Celula *chamadasDoPolicial = NULL;

    coletarChamadasDoPolicial(policial, chamadasFinalizadas, chamadasDoPolicial, viaturas);

    if(chamadasDoPolicial == NULL) {
        printf("\nNão há chamadas finalizadas no nome de %s\n", ((Policial *)policial->d)->nome);
        return;
    }

    fazerBoletins(chamadasDoPolicial, viaturas);
}

void coletarChamadasDoPolicial(
    Celula *policial, Celula *chamadasFinalizadas, Celula *&chamadasDoPolicial, Celula *viaturas
) {
    Celula *aux = chamadasFinalizadas, *viatura;

    while(aux != NULL) {
        if(!((Chamada *)aux->d)->temBoletim) {
            for(int i = 0; i < ((Chamada *)aux->d)->viaturasNecessarias; i++) {
                viatura = buscarViatura(viaturas, ((Chamada *)aux->d)->codigoViatura[i]);
                for(int j = 0; j < ((Viatura *)viatura->d)->nPoliciais; j++) {
                    if(
                        strcmp(
                            ((Policial *)policial->d)->nomeGuerra, 
                            ((Viatura *)viatura->d)->policiais[j]
                        ) == 0
                    ) {
                        inserirFim(chamadasDoPolicial, aux);
                    }
                }
            }
        }
        aux = aux->prox;
    }
}

void fazerBoletins(Celula *chamadasDoPolicial, Celula *viaturas) {
    Celula *aux = chamadasDoPolicial;
    int op;

    while(aux != NULL) {
        aux = chamadasDoPolicial;
        imprimirChamadaDoPolicial(aux, viaturas);

        printf("1 - Gerar boletim    2 - Não gerar boletim   3 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
        while(op != 1 && op != 2 && op != 3) {
            printf("1 - Gerar boletim    2 - Não gerar boletim\n");
            scanf("%d", &op);
        }

        if(op == 3) return;
        
        if(op == 1) {
            ((Chamada *)aux->d)->temBoletim = true;
            printf("Boletim registrado\n");
        } 
        aux = aux->prox;
    }
    printf("Não há mais ocorrências no nome do policial\n");
    printf("1 - Voltar ao Menu Principal\n");
    scanf("%d", &op);
    while(op  != 1) {
        printf("Não há mais ocorrências no nome do policial\n");
        printf("1 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
    }
}

void imprimirChamadaDoPolicial(Celula *chamadaDoPolicial, Celula *viaturas) {
    Chamada *chamada = (Chamada *)chamadaDoPolicial->d;

    printf("Tipo Policia: %s\n", chamada->tipoPolicia);
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
    printf("\n");
}



