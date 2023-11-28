#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/System/Clock.hpp>
#include <ctime>
using namespace std;
using namespace sf;


Juego::Juego(): m_window(VideoMode(800,600),"TETRIS") {
	m_window.setFramerateLimit(60);	
	t_pieza_t.loadFromFile("t.png");
	t_pieza_cuadrado.loadFromFile("cuadrado.png");
	t_pieza_i.loadFromFile("i.png");
	t_pieza_L.loadFromFile("L.png");
	t_pieza_Z.loadFromFile("Z.png");
	Sprite a(t_pieza_L);
	Sprite b(t_pieza_Z);
	a.setPosition(rand()%800,0);
	b.setPosition(rand()%400,0);
	piez.push_back(a);
	piez.push_back(b);
};

void Juego::Run(){
	tiempo = clock();
	while(m_window.isOpen()) {
		ProcesarEventos();
		Actualizar();
		dibujar();
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
	clock_t tiempo_final = clock();
	double duration_seconds = static_cast<double>(tiempo_final-tiempo) / CLOCKS_PER_SEC;
	if(duration_seconds>1)
	{	
		for(size_t i=0;i<piez.size();i++) {  
		piez[i].move(0,10);
		}
		tiempo = clock();
	}
	for(size_t i=0;i<piez.size();i++) {  ///cambiar cuando tengamos que detectar choques 
	Vector2f pos = piez[i].getPosition();
		if(pos.y<510)
		{
			
		}
	}
}

void Juego::dibujar(){
	m_window.clear(Color(100,100,100));
	for(size_t i=0;i<piez.size();i++) 
	{  
	
	piez[i].setScale(0.2,0.2);
	m_window.draw(piez[i]);
	}
	m_window.display();
}
