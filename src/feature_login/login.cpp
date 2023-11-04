#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"

void descriptografar(char senha[MAX], char sdi[MAX]);

void login(Celula *policiais) {
    char nomeGuerra[MAX], senha[MAX], sdi[MAX];

    printf("Digite o nome de guerra: ");
    scanf(" %[^\n]", nomeGuerra);
    printf("Digite sua senha: ");
    scanf(" %[^\n]", senha);
    Celula *policial = buscarPolicial(policiais, nomeGuerra);

    if(policial == NULL) {
        printf("Este policial não existe!\n");
        return;
    }

    descriptografar(((Policial*)policial->d)->senha, sdi);
    if(strcmp(senha, sdi) == 0) {
        printf("Login realizado com sucesso!\n");
        return;
    }

    printf("Senha errada!\n");
}

void descriptografar(char senha[MAX], char sdi[MAX]) {
    char sd[MAX];
    strcpy(sd, senha); 
    int len = strlen(senha), k = 0;
    //gnutx5cwdhz

    for(int i = 0; i < len; i++) {
        if(sd[i] >= 'A' && sd[i] <= 'Z') {
            sd[i] = ((((sd[i]) - 'A') - 3 + 26) % 26) + 'A';
        } else if(sd[i] >= 'a' && sd[i] <= 'z') {
            sd[i] = (((sd[i] - 'a') - 3 + 26) % 26) + 'a';
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        sdi[k] = sd[i];
        k++;
    }
    printf("%s\n", sdi);
}

