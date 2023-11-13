#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/policial.h"

void obterQuemTrabalhou(Celula *viaturas, Celula *policiais, Celula *&v, Celula *&p, int &n1, int &n2);
void ordenarViaturas(Celula *&v, int n);
void ordenarPoliciais(Celula *&v, int n);
void imprimirRelatorio(Celula *v, Celula *p);

void gerarRelatorio(Celula *viaturas, Celula *policiais) {
    Celula *v = NULL, *p = NULL;
    int n1 = 0, n2 = 0;
    obterQuemTrabalhou(viaturas, policiais, v, p, n1, n2);
    ordenarViaturas(v, n1);
    ordenarPoliciais(p, n2);
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

void ordenarViaturas(Celula *&v, int n) { // Selection Sort
    Celula *p = v, *q, *x;
    void *aux;

    while(p->prox != NULL) {
        x = p;
        q = p->prox;
        while(q != NULL) {
            if(strcmp(((Viatura *)q->d)->codigo, ((Viatura *)x->d)->codigo) < 0) x = q;
            q = q->prox;
        }

        if(x != p) {
            aux = x->d;
            x->d = p->d;
            p->d = aux; 
        }
        p = p->prox;
    }
}

void ordenarPoliciais(Celula *&v, int n) { // Selection Sort
    Celula *p = v, *q, *x;
    void *aux;

    while(p->prox != NULL) {
        x = p;
        q = p->prox;
        while(q != NULL) {
            if(strcmp(((Policial *)q->d)->nome, ((Policial *)x->d)->nome) < 0) x = q;
            q = q->prox;
        }

        if(x != p) {
            aux = x->d;
            x->d = p->d;
            p->d = aux; 
        }
        p = p->prox;
    }
}

void imprimirRelatorio(Celula *v, Celula *p) {
    FILE *pArq;
    pArq = fopen(PATH_RELATORIO, "w");

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
    
    fclose(pArq);
}
