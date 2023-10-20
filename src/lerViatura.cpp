#include <stdio.h>
#include <stdlib.h>

#include "../include/viatura.h"

void lerViatura(char *codigo, Viatura *&viatura) {
    FILE *fViaturas;
    int in;

    fViaturas = fopen("arquivos_entrada/viaturas.txt", "r");

    if(!fViaturas) {
        printf("Erro ao abrir arquivo de viaturas\n");
        return;
    }

    char *codigoArquivo;
    do {
        in = fscanf(fViaturas, "%s", codigoArquivo);
    } while(codigo != codigoArquivo && in != EOF);

    if(in != EOF) {
        
    } else {
        printf("Viatura não encontrada\n");
    }

    fclose(fViaturas);
}