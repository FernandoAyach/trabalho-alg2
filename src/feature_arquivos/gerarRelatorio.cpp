#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/policial.h"

void obterQuemTrabalhou(Celula *viaturas, Celula *policiais, Celula *&v, Celula *&p, int &n1, int &n2);
void ordenar(Celula *&lst, int n);
void imprimirRelatorio(Celula *v, Celula *p);

void gerarRelatorio(Celula *viaturas, Celula *policiais) {
    Celula *v = NULL, *p = NULL;
    int n1 = 0, n2 = 0;
    obterQuemTrabalhou(viaturas, policiais, v, p, n1, n2);

    ordenar(v, n1);
    ordenar(p, n2);

    imprimirRelatorio(v, p);
    desalocar(v);
    desalocar(p);
}

void obterQuemTrabalhou(Celula *viaturas, Celula *policiais, Celula *&v, Celula *&p, int &n1, int &n2) {
    while(viaturas != NULL) {
        if(
            ((Viatura *)viaturas->d)->status != NAO_APTO &&
            buscarViatura(v, ((Viatura *)viaturas->d)->codigo) == NULL
        ) {
            inserirFim(v, viaturas->d);
            printf("%s\n", ((Viatura *)viaturas->d)->codigo);
            n1++;
        }
        viaturas = viaturas->prox;
    }

    while(policiais != NULL) {
        if(
            ((Policial *)policiais->d)->trabalhou &&
            buscarPolicial(v, ((Policial *)policiais->d)->nomeGuerra) == NULL
        ) {
            inserirFim(p, policiais->d);
            printf("%s\n", ((Policial *)policiais->d)->nomeGuerra);
            n2++;
        }
        policiais = policiais->prox;
    }
}

void ordenar(Celula *&lst, int n) {
    
}

void imprimirRelatorio(Celula *v, Celula *p) {
    FILE *pArq;
    pArq = fopen(PATH_RELATORIO, "w");

    printf("Abriu arquivo\n");

    if(pArq == NULL) {
        printf("[ERRO-ARQUIVOS]: Erro ao abrir relatorio.txt\n");
        return;
    }

    fprintf(pArq, "PMS -\n");
    printf("PMS -\n");
    while(p != NULL) {
        fprintf(pArq, "%s %d\n", ((Policial *)p->d)->nome, ((Policial *)p->d)->idade);
        printf("%s %d\n", ((Policial *)p->d)->nome, ((Policial *)p->d)->idade);
        p = p->prox;
    }

    fprintf(pArq, "\nVIATURAS -\n");
    printf("\nVIATURAS -\n");
    while(v != NULL) {
        fprintf(pArq, "V%s\n", ((Viatura *)v->d)->codigo);
        printf("V%s\n", ((Viatura *)v->d)->codigo);
        v = v->prox;
    }
    
    printf("Relatório gerado!\n");
    printf("Chegou ao final\n");
    
    fclose(pArq);
}
