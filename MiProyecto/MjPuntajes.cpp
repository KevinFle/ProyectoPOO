#include "MjPuntajes.h"
#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include "menu.h"
#include "puntajes.h"
#include <string>
#include <iostream>
using namespace std;
using namespace sf;

MjPuntajes::MjPuntajes() {
	puntajes p;
	puntajess = p.getPuntajes(); 
	cuadro.loadFromFile("mejorespuntajes.png");
	fondo.loadFromFile("fondo.jpg");
	
	s_cuadro = Sprite(cuadro);
	s_cuadro.setPosition(0,0);
	
	s_fondo = Sprite(fondo);
	s_fondo.setPosition(0,0);
	s_fondo.setScale(0.5,0.7);
	s_fondo.setColor(Color(75,105,255));
	
	m_font.loadFromFile("Tetris.ttf");
	regresar=Text("volver al menu",m_font);
	regresar.setPosition(700,275);
	regresar.setCharacterSize(25);
	
	nombre.setFont(m_font);
	nombre.setCharacterSize(30);
	nombre.setColor(Color(255,255,0));
	
	puntos.setFont(m_font);
	puntos.setCharacterSize(30);
	
	puntos.setColor(Color(255,255,0));
	
}

void MjPuntajes::Actualizar (Juego & juego) 
{
	FloatRect p = regresar.getGlobalBounds();
	Vector2i mousePosition = Mouse::getPosition();
	if (p.contains(static_cast<float>(mousePosition.x-200), static_cast<float>(mousePosition.y-120))) {///HAY UN ERROR DE POSICION DEL MOUSE Y LO CORRIJO CON NUMEROS
		// El mouse está sobre el texto
		regresar.setFillColor(Color::Red); // Cambia el color del texto, por ejemplo
		if(Mouse::isButtonPressed(Mouse::Left))
			juego.SetEscena(new menu());
	} else {
		// El mouse no está sobre el texto
		regresar.setFillColor({170,170,170}); // Restaura el color del texto
	}
	
}

void MjPuntajes::Dibujar (RenderWindow & win) {
	win.clear(Color(20,20,20));
	win.draw(s_fondo);
	win.draw(s_cuadro);
	win.draw(regresar);
	int nombreposx=320,posy=160,puntosposx=500;
	for(size_t i=0;i<puntajess.size();i++) 
	{  
		puntos.setPosition(puntosposx,posy);
		nombre.setPosition(nombreposx,posy);
		string n;
		for(int j=0;j<10;j++) 
		{  
			n.push_back(puntajess[i].nombre[j]);
		}
		nombre.setString(n);
		puntos.setString(to_string(puntajess[i].puntos));
		win.draw(nombre);
		win.draw(puntos);
		posy+=53;
	}
	win.display();
}

void MjPuntajes::ProcesarEvento (Event & e) {
	
}

