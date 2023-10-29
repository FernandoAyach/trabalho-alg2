#include <stdio.h>
#include <stdlib.h>

#include "../../include/linked_list.h"
#include "../../include/policial.h"
#include "../../include/viatura.h"

void menuTipoPolicia();
void menuDadosViatura(char codigo[COD_VIATURA+1], int &quantPM);

void viaturaLogin(
    Celula *&viaturas, Celula *&policiais, Celula *pessoas, Celula *&viaturaAtual,
    Celula *chamadasEmAndamento
) {
    int tipoPolicia, quantPM;
    char codigo[COD_VIATURA+1];

    menuTipoPolicia();
    scanf("%d", &tipoPolicia);

    menuDadosViatura(codigo, quantPM);
    bool invalido = (tipoPolicia == 1 && (quantPM < 2 || quantPM > 4)) || 
    (tipoPolicia == 2 && (quantPM != 4));
    while(invalido) {
        printf("\nAutorização de embarque negada: número de PMs inválido\n");
        menuDadosViatura(codigo, quantPM);
        invalido = (tipoPolicia == 1 && (quantPM < 2 || quantPM > 4)) || 
        (tipoPolicia == 2 && (quantPM != 4));
    }

    Celula *viatura = buscarViatura(viaturas, codigo);
    if(viatura != NULL) viaturaAtual = viatura;
    else printf("Viatura não existe!\n");
   
    char nomeGuerra[MAX];
    Celula *policial;
    ((Viatura *)viatura->d)->policiais = (char **) calloc(quantPM, sizeof(char *));
    printf("Identificação dos PMS:\n");
    for(int i = 0; i < quantPM; i++) {
        scanf(" %[^\n]", nomeGuerra);
        policial = buscarPolicial(policiais, nomeGuerra);

        if(policial != NULL) {
            ((Viatura *)viatura->d)->policiais[i] = (char *) calloc(quantPM, sizeof(char));
            ((Viatura *)viatura->d)->policiais[i] = ((Policial *)policial->d)->CPF; 
        } else {
            printf("Policial não existe!\n");
        }
    }
    
    viaturaNeutro(viaturaAtual, pessoas, chamadasEmAndamento);
}

void menuTipoPolicia() {
    printf("\nSPM - Viatura Login\n\n");
    printf("Policia Regular - 1\n");
    printf("Policia Especializada - 2\n");
}

void menuDadosViatura(char codigo[COD_VIATURA+1], int &quantPM) {
    printf("\nSPM - Viatura Login\n\n");
    printf("Código da viatura: ");
    scanf("%s", codigo);
    printf("Quantidade de PMs: ");
    scanf("%d", &quantPM);
}