#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "escena.h"
#include "Sonidos.h"
using namespace sf;

class Juego {
public:
	Juego();
	void Run();
	void Actualizar();
	void ProcesarEventos();
	void dibujar();
	void SetEscena(escena *siguiente_escena);
	void s_PlayMusic();
	void s_PauseMusic();
	void s_PlayLine();
	void s_PlayGameOver();
	void s_PlayNewScore();
	void s_mute();
	void s_desmute();
protected:
	RenderWindow m_window;
	escena *m_escena;
	escena *m_siguiente_escena=nullptr;
	Sonidos sonido;
};

#endif

