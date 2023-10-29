#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/copom.h"
#include "../../include/fila.h"

void criarChamadaPolicial(
    Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP,
    Celula *viaturas
) {
    Chamada *chamada = (Chamada *) calloc(1, sizeof(Chamada));
    int op;
    char *descricao = (char *) calloc(1, sizeof(char)), *localizacao = (char *) calloc(1, sizeof(char));

    do {
        printf("\nSPM - COPOM\n\n");
        printf("Policia Normal - 1        Especializada - 2\n");
        scanf("%d", &op);
    } while(op != 1 && op != 2);

    if(op == 1) strcpy(chamada->tipoPolicia, "regular");
    else strcpy(chamada->tipoPolicia, "especializada");

    if(op == 1) {
        do {
            printf("Prioritária - 1        Não Prioritária - 2\n");
            scanf("%d", &op);
        } while(op != 1 && op != 2);

        if(op == 1) chamada->prioritaria = true;
        else chamada->prioritaria = false;
    } else {
        chamada->prioritaria = true;
    }

    printf("Viaturas necessárias: ");
    scanf("%d", &chamada->viaturasNecessarias);
    printf("Descrição: ");
    scanf(" %[^\n]", descricao);
    printf("Localização: ");
    scanf(" %[^\n]", localizacao);
    chamada->descricao = descricao;
    chamada->localizacao = localizacao;

    if(chamada->prioritaria) enfileirar(ichamadasP, fchamadasP, chamada);
    else enfileirar(ichamadasNP, fchamadasNP, chamada);
}