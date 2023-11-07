#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"
#include "../../include/copom.h"

void imprimirChamadaDoPolicial(Celula *chamadaDoPolicial, Celula *viaturas);
void excluirBoletins(Celula *chamadasFinalizadas, Celula *viaturas);

void telaComandante(Celula *chamadasFinalizadas, Celula *viaturas) {
    printf("\nSPM - Comandante Geral\n");
    int op;

    printf("\n1 - Gerar Ofício de ocorrências  2 - Voltar ao Menu Principal\n");
    scanf("%d", &op);
    while(op != 1 && op != 2) {
        printf("\n1 - Gerar Ofício de ocorrências  2 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
    }

    if(op == 1) {
        gerarOficio(chamadasFinalizadas, viaturas);
        
        printf("\n1 - Voltar ao Menu Principal\n");
        scanf("%d", &op);
        while(op != 1) {
            printf("\n1 - Voltar ao Menu Principal\n");
            scanf("%d", &op);
        }
    }

}

