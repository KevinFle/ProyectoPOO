#ifndef MENU_H
#define MENU_H
#include "escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;
class menu : public escena {
public:
	menu();
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window) override;
private:
	Font m_font;
	Text m_t1, m_t2;
};

#endif

