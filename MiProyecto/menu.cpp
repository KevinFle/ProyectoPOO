#include "menu.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>
#include "partida.h"
#include "Juego.h"

menu::menu() {
	m_font.loadFromFile("Tetris.ttf");
	m_t1.setFont(m_font);
	m_t2.setFont(m_font);
	m_t1.setString("TETRIS");
	m_t1.setColor(Color(255,255,0));
	m_t1.setPosition(250,200);
	m_t1.setCharacterSize(80);
	m_t2.setString("<PRESIONE ESPACIO PARA INICIAR");
	m_t2.setFillColor({150,150,150});
	m_t2.setPosition(175,350);
	m_t2.setCharacterSize(25);
}

void menu::Actualizar(Juego &juego)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
		juego.SetEscena(new partida);
}

void menu::Dibujar(RenderWindow &window)
{
	window.clear({20,20,20});
	window.draw(m_t1);
	window.draw(m_t2);
	window.display();
}
