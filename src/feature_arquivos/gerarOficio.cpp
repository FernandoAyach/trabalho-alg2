#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/linked_list.h"
#include "../../include/viatura.h"
#include "../../include/pessoa.h"

void gerarOficio(Celula *chamadasFinalizadas, Celula *viaturas) {
    FILE *pArq;
    pArq = fopen(PATH_OFICIO, "w");

    printf("Abriu arquivo\n");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir oficio_ocorrencias.txt\n");
        return;
    }

    Chamada *chamada;
    fprintf(pArq, "Ocorrências -\n");
    while(chamadasFinalizadas != NULL) {
        chamada = (Chamada *)chamadasFinalizadas->d;

        fprintf(pArq, "Tipo Policia: %s\n", chamada->tipoPolicia);
        fprintf(pArq, "Descricao: %s\n", chamada->descricao);
        fprintf(pArq, "Localizacao: %s\n", chamada->localizacao);

        Celula *viatura;
        fprintf(pArq, "Policiais:\n");
        for(int i = 0; i < chamada->viaturasNecessarias; i++) {
            viatura = buscarViatura(viaturas, chamada->codigoViatura[i]);
            for(int j = 0; j < ((Viatura *)viatura->d)->nPoliciais; j++) {
                fprintf(pArq, "- %s;\n", ((Viatura *)viatura->d)->policiais[j]);
            }
        }

        if(chamada->nPresos != 0) fprintf(pArq, "Presos:\n");
        for(int i = 0; i < chamada->nPresos; i++) {
            fprintf(
                pArq, "- %s, %s;\n", 
                ((Pessoa *)chamada->presos[i]->d)->nome, 
                ((Pessoa *)chamada->presos[i]->d)->CPF
            );
            printf(
                "- %s, %s;\n", 
                ((Pessoa *)chamada->presos[i]->d)->nome, 
                ((Pessoa *)chamada->presos[i]->d)->CPF
            );
        }
        fprintf(pArq, "\n");
        
        chamadasFinalizadas = chamadasFinalizadas->prox;
    }

    printf("Ofício gerado!\n");
    
    fclose(pArq);
}
