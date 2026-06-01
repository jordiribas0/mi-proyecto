#ifndef tablero_h
#define tablero_h

#include "tcasilla.h"

#define FALSE	0
#define TRUE	1

#define tablero_simple	's'
#define tablero_doble	'd'

#define min_size	2
#define max_size	6

typedef struct{
    char tipo;
    int mida;
    int fila_max, columna_max;
    tcasilla c[max_size][2*max_size];

}ttablero;

void inicializar_tablero(ttablero *tablero);
/*
-llama al azar para randomizarlo
-introduce tamaño y tipo de tablero a simple
-crea el puzle al azar pero completado
-mezcla el tablero

extra
-decidir el tipo de tablero a simple o doble
-
*/

void imprimir_tablero(ttablero tablero);

void realizar_jugada(ttablero *tablero);

int esta_resuelto(ttablero tablero);

int comprovar_rangos(char,char,int,int ,ttablero *tablero);


#endif
