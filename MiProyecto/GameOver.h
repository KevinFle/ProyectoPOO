#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "escena.h"
#include <SFML/Graphics/Text.hpp>
#include "puntajes.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameOver : public escena {
public:
	GameOver(puntaje p);
	void Actualizar (Juego & juego);
	void Dibujar (RenderWindow & win);
	void ProcesarEvento (Event & e);
private:
	Font m_font;
	Text Titulo,puntos,nombreJugador,logro,Volver;
	Texture fondo;
	Sprite s_fondo;
	bool aux=0;
};

#endif

