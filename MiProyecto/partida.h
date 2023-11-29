#ifndef PARTIDA_H
#define PARTIDA_H
#include "escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <ctime>

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "tablero.h"
using namespace std;
using namespace sf;

class partida : public escena {
public:
	partida();
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window)override;
private:
	Texture f;
	vector <Sprite> piez;
	clock_t tiempo;
	tablero *t;
};

#endif

