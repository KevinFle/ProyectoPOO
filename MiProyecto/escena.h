#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Juego;
class escena {
public:
	escena();
	virtual void Actualizar(Juego &juego)=0;
	virtual void Dibujar(RenderWindow &win)=0;
	
private:
};

#endif

