#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"
#include "../../include/copom.h"

void imprimirChamadaDoPolicial(Celula *chamadaDoPolicial, Celula *viaturas);
void excluirBoletins(Celula *chamadasFinalizadas, Celula *viaturas);

void telaOficial(Celula *chamadasFinalizadas, Celula *viaturas) {
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
    }
}

void excluirBoletins(Celula *chamadasFinalizadas, Celula *viaturas) {
    int op;

    while(chamadasFinalizadas != NULL) {
        if(((Chamada *)chamadasFinalizadas->d)->temBoletim) {
            imprimirChamadaDoPolicial(chamadasFinalizadas, viaturas);
            printf("1 - Excluir Boletim   2 - Não Excluir Boletim  3 - Voltar ao Menu Principal\n");
            scanf("%d", &op);
            while(op != 1 && op != 2 && op != 3) {
                printf("1 - Excluir Boletim   2 - Não Excluir Boletim   3 - Voltar ao Menu Principal\n");
                scanf("%d", &op);
            }

            if(op == 3) return;
            
            if(op == 1) {
                ((Chamada *)chamadasFinalizadas->d)->temBoletim = false;
                atualizarBoletins(chamadasFinalizadas, viaturas);
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
