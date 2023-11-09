#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/linked_list.h"
#include "../../include/viatura.h"

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
        printf("Printou tipo policia\n");
        fprintf(pArq, "Descricao: %s\n", chamada->descricao);
        printf("Printou descricao\n");
        fprintf(pArq, "Localizacao: %s\n", chamada->localizacao);
        printf("Printou localizacao\n");

        Celula *viatura;
        for(int i = 0; i < chamada->viaturasNecessarias; i++) {
            viatura = buscarViatura(viaturas, chamada->codigoViatura[i]);
            printf("Pegou a viatura\n");
            for(int j = 0; j < ((Viatura *)viatura->d)->nPoliciais; j++) {
                fprintf(pArq, "Policial %s\n", ((Viatura *)viatura->d)->policiais[j]);
            }
            printf("Printou os policiais da viatura\n");
        }
        fprintf(pArq, "\n");
        
        chamadasFinalizadas = chamadasFinalizadas->prox;
    }

    printf("Ofício gerado!\n");
    printf("Chegou ao final\n");
    
    fclose(pArq);
}