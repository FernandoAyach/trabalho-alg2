#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/linked_list.h"
#include "../../include/viatura.h"

void registrarBoletim(Chamada *chamada) {
    FILE *pArq;
    pArq = fopen(PATH_BOLETIM, "a");

    printf("Abriu arquivo\n");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir boletins.txt\n");
        return;
    }

    fprintf(pArq, "Boletim - Chamada %s %s\n", chamada->descricao, chamada->localizacao);
    fprintf(pArq, "- %s\n", chamada->boletim);
    fprintf(pArq, "\n");
    
    fclose(pArq);
}
