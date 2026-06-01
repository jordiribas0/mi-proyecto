#include <stdlib.h>
#include <stdio.h>
#include "azar.h"
#include "ttablero.h"
#include "tcasilla.h"


void inicializar_tablero(ttablero *tablero) {

    int filas, columnas;

    inicializar_azar();

    while (tablero->mida < 2 || tablero->mida > 6){

        printf("Tamano tablero entre 2 y 6: ");
		scanf("%d%*c",&tablero->mida);
    }
    while (tablero->tipo!='s' && tablero->tipo!='d'){

        printf("\nTipo de tablero ([s]:Simple o [d]:Doble): ");
		scanf("%c%*c",&tablero->tipo);
    }

    tablero->fila_max=tablero->mida-1;
    if (tablero->tipo == 'd'){
        tablero->columna_max = tablero->mida*2-1;
    }
    else{
    tablero->columna_max = tablero->mida -1;
    }
    for(filas=0; filas < tablero->mida; filas++){
		for(columnas = 0; columnas < tablero->columna_max + 1; columnas++){
			
			tablero->c[filas][columnas].est = numero_al_azar(10);
			tablero->c[filas][columnas].sud = numero_al_azar(10);
			if (filas == 0){ 
                tablero->c[filas][columnas].nord = numero_al_azar(10);
            }
			else {
                tablero->c[filas][columnas].nord=tablero->c[filas-1][columnas].sud;
            }
			if (columnas == 0) {
                tablero->c[filas][columnas].oest = numero_al_azar(10);
            }
			else {
                tablero->c[filas][columnas].oest=tablero->c[filas][columnas-1].est;
            }
			tablero->c[filas][columnas].fila = filas;
			tablero->c[filas][columnas].columna = columnas;
		}
    }
    for(filas = 0;filas < tablero->mida; filas++){
		for(columnas = 0;columnas < tablero->mida; columnas++){
            	intercambiar_casillas(&tablero->c[numero_al_azar(tablero->mida)][numero_al_azar(tablero->columna_max + 1)],
                                    &tablero->c[numero_al_azar(tablero->mida)][numero_al_azar(tablero->columna_max + 1)]);
        }
    }
}
void imprimir_tablero(ttablero tablero) {
        int l, columnas, ct, inf = 0;

    printf("\n");
	for(ct = 0; ct < tablero.columna_max + 1; ct++) {
        printf("   %c",'A' + ct);
    }

    for( l = 0; l<tablero.mida*3; l++){	
		
		if(l%3==0){
			printf("\n +");
			for(ct = 0; ct < tablero.columna_max + 1; ct++){
            printf("---+");
            }
			printf("\n |");
		}
		else if( l % 3 == 1){
            printf("\n%d|",inf++);
        }
		else if(l % 3 == 2)	{
            printf("\n |");
        }

		for(columnas = 0; columnas < tablero.columna_max + 1; columnas++){
						
			if(l % 3 == 0){
            imprimir_casilla_nord(tablero.c[l / 3][columnas]);
            }
			if(l % 3 == 1){	
            imprimir_casilla_centre(tablero.c[l / 3][columnas]);
            }
			if(l % 3 == 2){
            imprimir_casilla_sud(tablero.c[l / 3][columnas]);
		    }	
	    }
    }
	printf("\n +");

	for(ct = 0; ct < tablero.columna_max + 1; ct++){	
        printf("---+");
    }
}
void realizar_jugada(ttablero *tablero) {
	
	char columna1,columna2;
	int fila1,fila2,c1,c2;
		
	do{
		printf("\nCasillas a intercambiar (ej: [A0B1]): ");
		scanf("%c%d%c%d",&columna1, &fila1, &columna2, &fila2);
			
	}while(comprovar_rangos(columna1, columna2, fila1, fila2, &*tablero));
	
	c1=(columna1 - 'A');
	c2=(columna2 - 'A');
	
	intercambiar_casillas(&tablero->c[fila1][c1],&tablero->c[fila2][c2]);	
}
int esta_resuelto(ttablero tablero) {
	
	int fila, columna;
	
	for(fila = 0; fila < tablero.mida; fila++)
		for(columna = 0; columna < tablero.columna_max + 1; columna++){

			if (fila != 0 && tablero.c[fila][columna].nord != tablero.c[fila-1][columna].sud){
                return 0;
            }
			if (columna != 0 && tablero.c[fila][columna].oest != tablero.c[fila][columna-1].est){
                return 0;
            }
		}
	return 1;	
}

int comprovar_rangos(char col1, char col2, int fil1, int fil2, ttablero *tablero){

    if (col1 == col2 && fil1 == fil2){
        return 1;
    }
    else if (col1 > ('A' + tablero->columna_max) || (col1 < 'A') 
    || (col2 > ('A' + tablero->columna_max)) || (col2 < 'A') || (fil1 < 0) 
    || (fil1>tablero->fila_max) || (fil2<0)|| (fil2>tablero->fila_max)){

        return 1;
    }
    
    
    return 0;
}
