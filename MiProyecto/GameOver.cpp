#include "GameOver.h"
#include <SFML/Graphics/Color.hpp>
#include "puntajes.h"
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include "Juego.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

GameOver::GameOver(puntaje p) {
	puntajes pa;
	fondo.loadFromFile("fondo.jpg");
	s_fondo=Sprite(fondo);
	s_fondo.setPosition(0,0);
	s_fondo.setScale(0.5,0.7);
	s_fondo.setColor(Color(75,105,255));
	
	m_font.loadFromFile("Tetris.ttf");
	Titulo=Text("Game Over",m_font);
	Titulo.setCharacterSize(80);
	Titulo.setPosition(200,150);
	
	puntos=Text(to_string(p.puntos),m_font);
	puntos.setCharacterSize(40);
	puntos.setPosition(620,350);
	puntos.setColor(Color(255,255,0));

	nombreJugador=Text(p.nombre,m_font);
	nombreJugador.setCharacterSize(40);
	nombreJugador.setPosition(170,350);
	nombreJugador.setColor(Color(255,255,0));
	
	vector<puntaje> paux;
	paux = pa.getPuntajes();
	
			
	if(pa.NewScore(p)){
		logro=Text("Tu puntaje esta en el Top!",m_font);
		aux=1;
	}else{
		logro=Text("No fue un puntaje Top",m_font);
		aux=0;
	}
	logro.setCharacterSize(40);
	logro.setPosition(200,450);
	logro.setColor(Color(255,255,0));
	
	Volver=Text("REGRESAR AL MENU",m_font);
	Volver.setCharacterSize(25);
	Volver.setPosition(300,530);
	
}

void GameOver::Actualizar (Juego & juego) {
	Color rgb= Color(rand()%255,rand()%255,rand()%255);
	Titulo.setColor(rgb);
	if(aux==1)
	{
		juego.s_PlayNewScore();
	}
	
	FloatRect p = Volver.getGlobalBounds();
	Vector2i mousePosition = Mouse::getPosition();
	if (p.contains(static_cast<float>(mousePosition.x-200), static_cast<float>(mousePosition.y-120))) {
		// El mouse está sobre el texto
		Volver.setFillColor(Color::Red); // Cambia el color del texto, por ejemplo
		if(Mouse::isButtonPressed(Mouse::Left)){
			juego.SetEscena(new menu());
			juego.s_PlayMusic();
		}
	} else {
		// El mouse no está sobre el texto
		Volver.setFillColor({170,170,170}); // Restaura el color del texto
	}
	
}

void GameOver::Dibujar (RenderWindow & win) {
	win.clear(Color(20,20,20));
	win.draw(s_fondo);
	win.draw(Titulo);
	win.draw(puntos);
	win.draw(nombreJugador);
	win.draw(logro);
	win.draw(Volver);
	win.display();
}

void GameOver::ProcesarEvento (Event & e) {
	
}

