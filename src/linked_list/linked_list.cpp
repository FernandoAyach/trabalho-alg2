#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "../../include/viatura.h"
#include "../../include/policial.h"
#include "../../include/pessoa.h"
#include "../../include/linked_list.h"
#include "../../include/copom.h"

void inserirInicio(Celula *&lst, void *d) {
    Celula *n = (Celula *) calloc(1, sizeof(Celula));
    n->d = d;
    n->prox = lst;
    lst = n;
}

void inserirFim(Celula *&lst, void *d) {
    Celula *n = (Celula *) calloc(1, sizeof(Celula)), *q = lst;
    n->d = d;

    if(q == NULL) {
        lst = n;
        return;
    }
    
    while(q->prox != NULL) q = q->prox;

    q->prox = n;
}

void removerViatura(Celula *&lst, char codigo[COD_VIATURA+1]) {
    Celula *p = NULL, *q = lst;
    
    while(q != NULL && strcmp(((Viatura *)q->d)->codigo, codigo) != 0) {
        q = q->prox;
    }

    if(q != NULL) {
        if(p == NULL) {
            lst = lst->prox;
            free(q);
        } else {
            p->prox = q->prox;
            free(q);
        }
    }
}

void removerChamada(Celula *&lst, char codigo[COD_VIATURA+1], Celula *viaturas) {
    Celula *p = NULL, *q = lst;
    Chamada *chamada;
    int i;

    while(q != NULL) {
        chamada = ((Chamada *)q->d);
        i = 0; 
        while(
            i < chamada->viaturasNecessarias && strcmp(chamada->codigoViatura[i], codigo) != 0
        ) {
            i++;
        }

        if(i < chamada->viaturasNecessarias) break;
        p = q;
        q = q->prox;
    }
    printf("Achou a chamada\n");
    printf("Chamada a ser deletada %s\n", chamada->descricao);

    if(q != NULL) {
        Celula *viatura;
        for(int i = 0; i < chamada->viaturasNecessarias; i++) {
            viatura = buscarViatura(viaturas, chamada->codigoViatura[i]);
            ((Viatura *)viatura->d)->status = LIVRE;
            printf("Viatura envolvida: %s\n",  ((Viatura *)viatura->d)->codigo);
        }

        registrarOcorrencia(chamada, viaturas);

        if(p != NULL) {
            p->prox = q->prox;
            free(q);
            printf("Deletou no meio\n");
        }else {
            lst = q->prox;
            free(q);
            printf("Deletou no começo\n");
        }
        printf("Deletou\n");
        
        //imprimirChamadas(lst);
    } else {
        printf("Não há chamadas para esta viatura!\n");
    }
}

Celula *buscarViatura(Celula *lst, char codigo[COD_VIATURA+1]) {
    while(lst != NULL && strcmp(((Viatura *)lst->d)->codigo, codigo) != 0) {
        lst = lst->prox;
    }
    return lst;
}

Celula *buscarPolicial(Celula *lst, char nomeGuerra[MAX+1]) {
    while(lst != NULL && strcmp(((Policial *)lst->d)->nomeGuerra, nomeGuerra) != 0) {
        lst = lst->prox;
    }
    return lst;
}

Celula *buscarPessoa(Celula *lst, char CPF[CPF_SIZE+1]) {
    while(lst != NULL && strcmp(((Pessoa *)lst->d)->CPF, CPF) != 0) {
        lst = lst->prox;
    }
    return lst;
}

void imprimirViaturas(Celula *lst) {
    while(lst != NULL) {
        printf("Viatura %s\n", ((Viatura *)lst->d)->tipo);
        lst = lst->prox;
    }
}

void imprimirPoliciais(Celula *lst) {
    while(lst != NULL) {
        printf("Policial %s\n", ((Policial *)lst->d)->nomeGuerra);
        lst = lst->prox;
    }
}

void imprimirPessoas(Celula *lst) {
    while(lst != NULL) {
        printf("Pessoa %s %d\n", ((Pessoa *)lst->d)->nome, ((Pessoa *)lst->d)->passagensPolicia);
        lst = lst->prox;
    }
}

void imprimirChamadas(Celula *lst) {
    while(lst != NULL) {
        printf("Chamada %s %d\n", ((Chamada *)lst->d)->descricao, ((Chamada *)lst->d)->viaturasNecessarias);
        lst = lst->prox;
    }
}

void desalocar(Celula *&lst) {
    Celula *aux;
    while(lst != NULL) {
        aux = lst;
        lst = lst->prox;
        free(aux);
    }
}