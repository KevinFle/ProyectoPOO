#include "partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "menu.h"
#include "tablero.h"
#include <SFML/Graphics/Text.hpp>
#include "puntajes.h"
#include <cstring>
#include "GameOver.h"
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;

partida::partida(string nombreJug) 
{
	t=new tablero(50,50);
	fondo.loadFromFile("fondo.jpg");
	s_fondo=Sprite(fondo);
	s_fondo.setPosition(0,0);
	s_fondo.setScale(0.5,0.7);
	s_fondo.setColor(Color(75,105,255));
	
	piezai.loadFromFile("i.png");
	piezaj.loadFromFile("j.png");
	piezal.loadFromFile("l.png");
	piezas.loadFromFile("s.png");
	piezat.loadFromFile("t.png");
	piezacuadrado.loadFromFile("cuadrado.png");
	piezaz.loadFromFile("z.png");
	
	p_font.loadFromFile("Tetris.ttf");
	puntajes p;
	strcpy(puntajee.nombre,nombreJug.c_str());
	nomJugador = Text("Nombre Jugador:",p_font);
	nomJugador.setPosition(370,50);
	nomJugador.setCharacterSize(30);
	
	nombreJugador=nombreJug;
	p_nombreJugador= Text(nombreJugador,p_font);
	p_nombreJugador.setPosition(650,50);
	p_nombreJugador.setCharacterSize(30);
	p_nombreJugador.setColor(Color(255,255,0));
	
	puntosTitulo = Text("Score:",p_font);
	puntosTitulo.setColor(Color(162,0,255));
	puntosTitulo.setPosition(370,250);
	puntosTitulo.setCharacterSize(40);
	
	puntos = Text(to_string(score),p_font);
	puntos.setCharacterSize(50);
	puntos.setColor(Color(162,0,255));
	puntos.setPosition(550,245);
	
	ScoreTitulo = Text("Max Score:",p_font);
	ScoreTitulo.setCharacterSize(50);
	ScoreTitulo.setColor(Color(162,0,255));
	ScoreTitulo.setPosition(370,350);
	
	string aux= to_string(p.getMaxScore());
	puntajeMax=Text(aux,p_font);
	puntajeMax.setCharacterSize(50);
	puntajeMax.setColor(Color(162,0,255));
	puntajeMax.setPosition(700,350);
	
	level = Text(to_string(nivel),p_font);
	level.setCharacterSize(50);
	level.setColor(Color(162,0,255));
	level.setPosition(600,150);
	
	nivelTitulo = Text("NIVEL:",p_font);
	nivelTitulo.setCharacterSize(50);
	nivelTitulo.setColor(Color(162,0,255));
	nivelTitulo.setPosition(370,150);
	
	siguientePieza = Text("SIGUIENTE PIEZA",p_font);
	siguientePieza.setCharacterSize(30);
	siguientePieza.setColor(Color(162,0,255));
	siguientePieza.setPosition(370,500);
	
}

void partida::ProcesarEvento(Event &e)
{
	if(Keyboard::isKeyPressed(Keyboard::Left)&&!left){
		t->izquierda();
	}else if(!Keyboard::isKeyPressed(Keyboard::Left)){
		left=0;
	}else if(Keyboard::isKeyPressed(Keyboard::Left)&&left){
		left++;
		if(left==6){
			left=0;
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right)&&!right)
	{
		t->derecha();
		right=1;
	}else if(!Keyboard::isKeyPressed(Keyboard::Right))
	{
		right=0;
	}else if(Keyboard::isKeyPressed(Keyboard::Right)&&right){
		right++;
		if(right==6){ 
			right=0;
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		t->girarPieza();
		up=1;
	}else if(!Keyboard::isKeyPressed(Keyboard::Up))
	{
		up=0;
	}
	if(Keyboard::isKeyPressed(Keyboard::Down)){
		t->ActualizarLimiteDelTimer(5);
	}
	else
	{ 
		t->ActualizarLimiteDelTimer(limite);
	}
}

void partida::Actualizar(Juego &juego)
{
	
	if(t->ActualizarTablero()){
		if(!t->instalarPieza()){
			live=0;
			t->borrarTablero();
			juego.s_PauseMusic();
			juego.s_PlayGameOver();
			puntajee.puntos=score;
			juego.SetEscena(new GameOver(puntajee));
		}
		
		switch(t->getSiguientePieza()){
		case 0: 
			s_siguientePieza=Sprite(piezacuadrado); 
			break;
		case 1: 
			s_siguientePieza=Sprite(piezas); 
			break;
		case 2: 
			s_siguientePieza=Sprite(piezaz); 
			break;
		case 3: 
			s_siguientePieza=Sprite(piezal); 
			break;
		case 4: 
			s_siguientePieza=Sprite(piezaj); 
			break;
		case 5: 
			s_siguientePieza=Sprite(piezat);
			break;
		case 6: 
			s_siguientePieza=Sprite(piezai); 
			break;
		}
		s_siguientePieza.setScale(0.4,0.4);
		s_siguientePieza.setPosition(670,490);
	}
	t->ActualizarColor();
	int newScore = t->verificarLinea()*5;
	if(newScore>0)
	{
		if(limite>5&&aux==2)
		{
			aux=0;
			limite-=3;
			t->ActualizarLimiteDelTimer(limite);
			nivel++;
			level.setString(to_string(nivel));
		}
		juego.s_PlayLine();
		aux++;
	}
	score+=newScore;
	puntos.setString(to_string(score));
}

void partida::Dibujar(RenderWindow &window)
{
	window.clear(Color(20,20,20));
	window.draw(s_fondo);
	window.draw(*t);
	window.draw(p_nombreJugador);
	window.draw(puntosTitulo);
	window.draw(nomJugador);
	window.draw(puntos);
	window.draw(puntajeMax);
	window.draw(ScoreTitulo);
	window.draw(nivelTitulo);
	window.draw(level);
	window.draw(siguientePieza);
	window.draw(s_siguientePieza);
	window.display();
	
}
