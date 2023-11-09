#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/linked_list.h"
#include "../../include/policial.h"
#include "../../include/viatura.h"

void menuTipoPolicia();
void menuDadosViatura(char codigo[COD_VIATURA+1], int &quantPM);
void desalocarViatura(Celula *&viaturaAtual);

void viaturaLogin(
    Celula *&viaturas, Celula *&policiais, Celula *pessoas, Celula *&viaturaAtual,
    Celula *&chamadasEmAndamento, Celula *&ichamadasP, Celula *&fchamadasP,
    Celula *&ichamadasNP, Celula *&fchamadasNP, Celula *&chamadasFinalizadas,
    Celula *&ireforcos, Celula *&freforcos
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
    else {
        printf("Viatura não existe!\n");
        return;
    }
   
    char nomeGuerra[MAX];
    Celula *policial;
    ((Viatura *)viatura->d)->nPoliciais = quantPM;
    printf("Identificação dos PMS:\n");
    for(int i = 0; i < quantPM; i++) {
        scanf(" %[^\n]", nomeGuerra);
        policial = buscarPolicial(policiais, nomeGuerra);
        ((Policial *)policial->d)->trabalhou = true;
        ((Viatura *)viatura->d)->policiais[i] = (char *) calloc(1, sizeof(char));
        if(policial != NULL) strcpy(((Viatura *)viatura->d)->policiais[i], nomeGuerra); 
        else printf("Policial não existe!\n");
    }
    
    viaturaNeutro(
        viaturaAtual, pessoas, chamadasEmAndamento, viaturas, ichamadasP, fchamadasP,
        ichamadasNP, fchamadasNP, chamadasFinalizadas, ireforcos, freforcos
    );
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