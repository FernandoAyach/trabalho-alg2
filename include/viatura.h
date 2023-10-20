#pragma once

#define COD_VIATURA 3
#define TIPO_VIATURA 13

struct Viatura {
    char codigo[COD_VIATURA+1];
    char tipo[TIPO_VIATURA+1];
};

void viaturaLogin(Viatura *&viaturaAtual);
void viaturaNeutro(char **nomePMs);
void viaturaRonda();
