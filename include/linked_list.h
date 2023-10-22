#pragma once
struct Celula {
    void *d;
    Celula *prox;
};

void inserirInicio(Celula *&lst, void *d);
void imprimirViaturas(Celula *lst);
