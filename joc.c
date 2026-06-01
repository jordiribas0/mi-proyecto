#include <stdio.h>
#include "ttablero.h"


int main(){
    ttablero tablero = {0};
    inicializar_tablero(&tablero);
    imprimir_tablero(tablero);
    
    while (!esta_resuelto(tablero)){
        realizar_jugada(&tablero);
        imprimir_tablero(tablero);
    }
    printf("\npuzzle resuelto!!!\n");
}