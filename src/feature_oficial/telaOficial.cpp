#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"
#include "../../include/copom.h"

void imprimirChamadaComBoletim(Celula *chamadaDoPolicial, Celula *viaturas);
void excluirBoletins(Celula *chamadasFinalizadas, Celula *viaturas);

void telaOficial(Celula *chamadasFinalizadas, Celula *viaturas, Celula *policiais) {
    printf("\nSPM - Oficial\n");
    int op;

    printf("\n1 - Excluir boletins    2 - Gerar relatório oficial   3 - Voltar ao Menu Principal\n");
    scanf("%d", &op);
    while(op != 1 && op != 2 && op != 3) {
        printf("\n1 - Excluir boletins    2 - Gerar relatório oficial   3 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
    }

    if(op == 3) return;

    if(op == 1) {
        excluirBoletins(chamadasFinalizadas, viaturas);
    } else if(op == 2) {
        gerarRelatorio(viaturas, policiais);
    }
}

void excluirBoletins(Celula *chamadasFinalizadas, Celula *viaturas) {
    int op;

    while(chamadasFinalizadas != NULL) {
        if(((Chamada *)chamadasFinalizadas->d)->temBoletim) {
            imprimirChamadaComBoletim(chamadasFinalizadas, viaturas);
            printf("1 - Excluir Boletim   2 - Não Excluir Boletim  3 - Voltar ao Menu Principal\n");
            scanf("%d", &op);
            while(op != 1 && op != 2 && op != 3) {
                printf("1 - Excluir Boletim   2 - Não Excluir Boletim   3 - Voltar ao Menu Principal\n");
                scanf("%d", &op);
            }

            if(op == 3) return;
            
            if(op == 1) {
                ((Chamada *)chamadasFinalizadas->d)->temBoletim = false;
                free(((Chamada *)chamadasFinalizadas->d)->boletim);
                atualizarBoletins(chamadasFinalizadas);
                printf("\nBoletim excluído\n");
            } 
        }
        
        chamadasFinalizadas = chamadasFinalizadas->prox;
    }

    printf("\nNão há mais ocorrências a serem analisadas\n");
    printf("1 - Voltar ao Menu Principal\n");
    scanf("%d", &op);
    while(op  != 1) {
        printf("\nNão há mais ocorrências a serem analisadas\n");
        printf("1 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
    }
}

void imprimirChamadaComBoletim(Celula *chamadaDoPolicial, Celula *viaturas) {
    Chamada *chamada = (Chamada *)chamadaDoPolicial->d;

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
    printf("Boletim: %s\n", chamada->boletim);
    printf("\n");
}
