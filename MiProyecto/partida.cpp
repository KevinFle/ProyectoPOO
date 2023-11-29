#include "partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "menu.h"
#include "tablero.h"

partida::partida() {
	f.loadFromFile("cuadrado.png");
	tiempo = clock();
	t=new tablero();
}


void partida::Actualizar(Juego &juego)
{
//	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
//		juego.SetEscena(new menu());
//	clock_t tiempo_final = clock();
//	double duration_seconds = static_cast<double>(tiempo_final-tiempo) / CLOCKS_PER_SEC;
//	if(duration_seconds>1)
//	{	
//		for(size_t i=0;i<piez.size();i++) {  
//			Vector2f pos = piez[i].getPosition();
//			if(pos.y<510)
//			{
//				piez[i].move(0,10);
//			}
//		}
//		tiempo = clock();
//	}
}

void partida::Dibujar(RenderWindow &window)
{
	window.clear(Color(20,20,20));
//	for(size_t i=0;i<piez.size();i++) 
//	{  
//	piez[i].setScale(0.2,0.2);
//	window.draw(piez[i]);
//	}
	t->ActualizarColor();
	window.draw(*t);
	window.display();
}
