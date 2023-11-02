#pragma once

struct Celula {
    void *d;
    Celula *prox;
};

void inserirInicio(Celula *&lst, void *d);
void inserirFim(Celula *&lst, void *d);
void desalocar(Celula *&lst);
void imprimirViaturas(Celula *lst);
void imprimirPoliciais(Celula *lst);
void imprimirPessoas(Celula *lst);
