#ifndef MENU_H
#define MENU_H
#include "escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "InputText.h"
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;
class menu : public escena {
public:
	menu();
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window) override;
	void ProcesarEvento(Event &e)override;
private:
	Font m_font;
	Text m_t1, m_t2,m_t3,puntaj;
	InputText *nombreJugador;
	string nombre_ingresado;
	Texture volumen,mute,fondo;
	Sprite s_volumen,s_fondo;
	bool mutee=false;
};

#endif

