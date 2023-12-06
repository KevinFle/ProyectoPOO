#ifndef MJPUNTAJES_H
#define MJPUNTAJES_H
#include "escena.h"
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Juego.h"
#include "puntajes.h"
using namespace std;
using namespace sf;

class MjPuntajes : public escena {
public:
	MjPuntajes();
	void Actualizar (Juego & juego);
	void Dibujar (RenderWindow & win);
	void ProcesarEvento (Event & e);
private:
	Texture cuadro,fondo;
	Sprite s_cuadro,s_fondo;
	Text regresar,nombre,puntos;
	Font m_font;
	vector<puntaje> puntajess;
};

#endif

