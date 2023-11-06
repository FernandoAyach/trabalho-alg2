#include <stdio.h>

#include "../../include/viatura.h"
#include "../../include/linked_list.h"
#include "../../include/pessoa.h"

void menuBuscarCpf(char cpf[CPF_SIZE+1]);

void viaturaBuscarCpf(Celula *pessoas) {
    char cpf[CPF_SIZE+1];
    int op; 
    menuBuscarCpf(cpf);
    Celula *pessoa = buscarPessoa(pessoas, cpf);

    printf("\nSPM - Viatura: Pesquisar por CPF\n\n");

    do {
        if(pessoa != NULL) {
            printf("%s, ", ((Pessoa *)pessoa->d)->nome);
            printf("%s, ", ((Pessoa *)pessoa->d)->CPF);
            printf("%s\n", ((Pessoa *)pessoa->d)->cidade);
            printf("%d\n", ((Pessoa *)pessoa->d)->idade);

            printf("Passagens pela polícia: \n");
            for(int i = 0; i < ((Pessoa *)pessoa->d)->passagensPolicia; i++) {
                printf("%s\n", ((Pessoa *)pessoa->d)->passagens[i]);
            }

            printf("Inadimplências: \n");
            for(int i = 0; i < ((Pessoa *)pessoa->d)->nInadimplencias; i++) {
                printf("%s\n", ((Pessoa *)pessoa->d)->inadimplencias[i]);
            }
        } else {
            printf("Falha ao encontrar cidadão!\n");
        }

        printf("\n1 - Encerrar visualização\n");
        scanf("%d", &op);
    } while(op != 1);
}

void menuBuscarCpf(char cpf[CPF_SIZE+1]) {
    printf("\nSPM - Viatura: Pesquisar por CPF\n\n");
    printf("CPF: ");
    scanf(" %[^\n]", cpf);
}