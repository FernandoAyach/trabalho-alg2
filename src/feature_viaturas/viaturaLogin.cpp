#include <stdio.h>
#include <stdlib.h>

#include "../../include/viatura.h"
#include "../../include/policial.h"

void menuTipoPolicia();
void menuDadosViatura(char *&codigo, int &quantPM);

void viaturaLogin(Viatura *&viaturaAtual) {
    int tipoPolicia, quantPM;
    char *codigo;

    menuTipoPolicia();
    scanf("%d", &tipoPolicia);

    menuDadosViatura(codigo, quantPM);

    bool numeroDePMsInvalido = tipoPolicia == 1 && (quantPM < 2 || quantPM > 4) || 
        tipoPolicia == 2 && (quantPM != 4);

    if(numeroDePMsInvalido) {
        printf("\nAutorização de embarque negada: número de PMs inválido\n");
        return;
    }

    char **nomePMs = (char **) calloc(quantPM, sizeof(char*));

    for(int i = 0; i < quantPM; i++) {
        nomePMs[i] = (char *) calloc(quantPM, sizeof(char));
        scanf(" %[^\n]", nomePMs[i]);
    }

    viaturaNeutro(nomePMs);
}

void menuTipoPolicia() {
    printf("\nSPM - Viatura Login\n\n");
    printf("Policia Regular - 1\n");
    printf("Policia Especializada - 2\n");
}

void menuDadosViatura(char *&codigo, int &quantPM) {
    printf("\nSPM - Viatura Login\n\n");
    printf("Código da viatura: ");
    scanf("%s", codigo);
    printf("Quantidade de PMs: ");
    scanf("%d", &quantPM);
}