#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/System/Clock.hpp>
#include <ctime>
#include "menu.h"
using namespace std;
using namespace sf;


Juego::Juego(): m_window(VideoMode(800,600),"TETRIS") {
	m_window.setFramerateLimit(60);	
	m_escena = new menu();
}

void Juego::Run(){
	while(m_window.isOpen()) {
		ProcesarEventos();
		Actualizar();
		dibujar();
		if (m_siguiente_escena) {
			delete m_escena;
			m_escena = m_siguiente_escena;
			m_siguiente_escena = nullptr;
		}
	}
}
void Juego::ProcesarEventos(){
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();
	}
	
}
void Juego::Actualizar()
{
	m_escena->Actualizar(*this);
	
}

void Juego::dibujar(){
	
	m_escena->Dibujar(m_window);
}
void Juego::SetEscena(escena *siguiente_escena)
{
	m_siguiente_escena = siguiente_escena;
}
