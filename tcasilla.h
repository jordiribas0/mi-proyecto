#ifndef casilla_h
#define casilla_h

#define buida -1
#define pos_buida -1

typedef struct{
    int nord, sud, est, oest;
    int fila, columna;
} tcasilla;

/*
imprimir les caselles del joc.
*/
void imprimir_casilla_nord(tcasilla cas);

void imprimir_casilla_centre(tcasilla cas);

void imprimir_casilla_sud(tcasilla cas);

void intercambiar_casillas(tcasilla *cas1, tcasilla *cas2);
/*
per poder intercanviar les caselles.
*/


#endif