#include <stdio.h>
#include <stdlib.h>

#include "../../include/pessoa.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void viaturaPrisao(
    Celula *pessoas, int &x, Celula *chamada, Celula *viaturaAtual,
    Celula *&chamadasEmAndamento, Celula *viaturas,
    Celula *&chamadasFinalizadas
) {
    int n, op;
    char cpf[CPF_SIZE+1];
    
    if(x != 7) {
        printf("\nSPM - Viatura: Prisão em Andamento\n\n");
        printf("Indivíduo(s) conduzido(s) para DP: ");
        scanf("%d", &n);
        printf("CPFs:\n");

        Celula **presos = (Celula **) calloc(n, sizeof(Celula *));
        for(int i = 0; i < n; i++) {
            scanf(" %[^\n]", cpf);
            Celula *pessoa = buscarPessoa(pessoas, cpf);
            presos[i] = pessoa;
            ((Chamada *)chamada->d)->nPresos++;
        }
        ((Chamada *)chamada->d)->presos = presos;
    }

    do {
        printf("\nSPM - Viatura: Prisão em Andamento\n\n");
        printf("1 - Confirmar retorno da DP\n");
        printf("2 - Voltar para o Menu Principal\n");
        scanf("%d", &op);

        if(op == 1) {
            removerChamada(
                chamadasEmAndamento, ((Viatura *)viaturaAtual->d)->codigo, 
                viaturas, chamadasFinalizadas
            ); 
            ((Viatura *)viaturaAtual->d)->status = VOLTOU_DP;
        }
    } while(op != 1 && op != 2);
}

