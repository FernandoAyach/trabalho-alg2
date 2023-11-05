#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"

void lerArquivoViaturas(Celula *&viaturas) {
    FILE *pArq;
    char codigo[COD_VIATURA+1];
    char tipo[TIPO_VIATURA+1];

    pArq = fopen(PATH_VIATURA, "r");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir viaturas.txt\n");
        return;
    }

    fscanf(pArq, "%s", codigo);
    fscanf(pArq, "%s", tipo);
    while(feof(pArq) == 0) {
        Viatura *v = (Viatura *) calloc(1, sizeof(Viatura));
        strcpy(v->codigo, codigo);
        strcpy(v->tipo, tipo);
        inserirFim(viaturas, v);

        fscanf(pArq, "%s", codigo);
        fscanf(pArq, "%s", tipo);
    }
    
    fclose(pArq);
}

