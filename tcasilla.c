#include <stdio.h>
#include "colores.h"
#include "tcasilla.h"

void imprimir_casilla_nord(tcasilla cas) {

    printf("/");
    printf_color(cas.nord);
    printf("%d", cas.nord);
    printf_reset_color();
     printf("\\|");
}
void imprimir_casilla_centre(tcasilla cas){

    printf_color(cas.oest);
    printf("%d", cas.oest);
    printf_reset_color();
    printf("x");
    printf_color(cas.est);
    printf("%d", cas.est);
    printf_reset_color();
    printf("|");

}
void imprimir_casilla_sud(tcasilla cas){

    printf("\\");
    printf_color(cas.sud);
    printf("%d", cas.sud);
    printf_reset_color();
    printf("/|");
}
void intercambiar_casillas(tcasilla *cas1, tcasilla *cas2){

    tcasilla aux;
    aux = *cas2;
    *cas2 = *cas1;
    *cas1 = aux;

}