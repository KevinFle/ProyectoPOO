#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "escena.h"
using namespace sf;

class Juego {
public:
	Juego();
	void Run();
	void Actualizar();
	void ProcesarEventos();
	void dibujar();
	void SetEscena(escena *siguiente_escena);
protected:
	RenderWindow m_window;
	escena *m_escena;
	escena *m_siguiente_escena=nullptr;
	
};

#endif

