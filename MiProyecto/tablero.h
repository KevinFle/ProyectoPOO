#ifndef TABLERO_H
#define TABLERO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstring>
#include "pieza.h"
#include <time.h>
using namespace sf;
using namespace std;
class tablero:public Drawable {
public:
	tablero();
	void ActualizarColor();
	void borrarTablero();
	virtual void draw(RenderTarget&rt,RenderStates rs)const override;
	bool instalarPieza();
private:
	int columna = 15;
	int fila = 25;
	int board[15][25];
	RectangleShape boardShapes[15][25];
	pieza piezas;
	int indNuevaPieza,indColorNuevaParte;
	Color ColorNuevaPieza;
	
};

#endif

