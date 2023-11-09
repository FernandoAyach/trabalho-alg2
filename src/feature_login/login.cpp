#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/policial.h"

void descriptografar(char senha[MAX], char sdi[MAX]);

Celula* login(Celula *policiais, const char cargo[]) {
    char nomeGuerra[MAX], senha[MAX], sdi[MAX];

    printf("Digite o nome de guerra: ");
    scanf(" %[^\n]", nomeGuerra);
    printf("Digite sua senha: ");
    scanf(" %[^\n]", senha);
    Celula *policial = buscarPolicial(policiais, nomeGuerra);

    if(policial == NULL) {
        printf("Este policial não existe!\n");
        return policial;
    }

    if(!(strcmp(cargo, PM) == 0 || strcmp(((Policial*)policial->d)->cargo, cargo) == 0)) {
        printf("Este policial não tem autorização para esta função!\n");
        return NULL;
    }

    descriptografar(((Policial*)policial->d)->senha, sdi);
    if(strcmp(senha, sdi) == 0) {
        printf("Login realizado com sucesso!\n");
        return policial;
    }

    printf("Senha errada!\n");
    return NULL;
}

void descriptografar(char senha[MAX], char sdi[MAX]) {
    char sd[MAX];
    strcpy(sd, senha); 
    int len = strlen(senha), k = 0;
    //k0u9t5hj98e

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

