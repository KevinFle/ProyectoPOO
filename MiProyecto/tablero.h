#ifndef TABLERO_H
#define TABLERO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstring>
#include "pieza.h"
#include <time.h>
using namespace sf;
using namespace std;

class tablero : public Drawable {
private:
	pieza pieza;
	
	int indNuevaPieza,indColorNuevaPieza;
	Color ColorNuevaPieza;
	
	int indX,indY;
	int posx,posy;
	int timer=0;
	int limitTimer=30;
	int tamy=25;
	int tamx=15;
	int siguientePieza;
	int board[25][15];
	RectangleShape boardShapes[25][15];
public:
	tablero(int x,int y);
	bool instalarPieza();
	void calcularSiguientePieza();
	int getSiguientePieza();
	bool ActualizarTablero();
	void ActualizarColor();
	void ActualizarLimiteDelTimer(int l);
	void girarPieza();
	void derecha();
	void izquierda();
	int verificarLinea();
	void borrarTablero();
	virtual void draw(RenderTarget&,RenderStates) const;
};

#endif

