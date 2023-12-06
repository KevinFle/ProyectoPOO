#include "menu.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>
#include "partida.h"
#include "Juego.h"
#include "InputText.h"
#include "MjPuntajes.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Texture.hpp>

menu::menu() {
	m_font.loadFromFile("Tetris.ttf");
	fondo.loadFromFile("fondo.jpg");
	s_fondo=Sprite(fondo);
	s_fondo.setPosition(0,0);
	s_fondo.setScale(0.5,0.7);
	s_fondo.setColor(Color(75,105,255));
	
	volumen.loadFromFile("volumen.png");
	mute.loadFromFile("mute.png");
	s_volumen=Sprite(volumen);
	s_volumen.setPosition(820,25);
	s_volumen.setScale(0.1,0.1);
	
	m_t1=Text("TETRIS",m_font);
	m_t1.setColor(Color(255,255,0));
	m_t1.setCharacterSize(80);
	FloatRect textRect = m_t1.getLocalBounds();
	m_t1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	
	
	m_t3=Text("Ingrese nombre:",m_font);
	m_t3.setColor(Color(150,150,150));
	m_t3.setCharacterSize(25);
	textRect = m_t3.getLocalBounds();
	m_t3.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	
	nombreJugador=new InputText(m_font,25,Color(255,255,0));
	nombreJugador->setMaxChars(10);
	nombreJugador->setSingleWord(true);
	textRect = nombreJugador->getLocalBounds();
	nombreJugador->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	
	m_t2=Text("<PRESIONE ESPACIO PARA INICIAR>",m_font);
	m_t2.setFillColor({170,170,170});
	m_t2.setCharacterSize(25);
	textRect = m_t2.getLocalBounds();
	m_t2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	
	puntaj =Text("Ver Mejores Puntajes",m_font);
	puntaj.setFillColor({170,170,170});
	puntaj.setCharacterSize(25);
	puntaj.setPosition(450,500);
	textRect = puntaj.getLocalBounds();
	puntaj.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	
}

void menu::Actualizar(Juego &juego)
{
	FloatRect p = puntaj.getGlobalBounds();
	Vector2i mousePosition = Mouse::getPosition();
	if (p.contains(static_cast<float>(mousePosition.x-200), static_cast<float>(mousePosition.y-120))) {
		// El mouse está sobre el texto
		puntaj.setFillColor(Color::Red); // Cambia el color del texto, por ejemplo
		if(Mouse::isButtonPressed(Mouse::Left))
			juego.SetEscena(new MjPuntajes());
	} else {
		// El mouse no está sobre el texto
		puntaj.setFillColor({170,170,170}); // Restaura el color del texto
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		string aux =nombre_ingresado;
		for(int i=nombre_ingresado.size();i<10;i++) 
		{  
			aux+=" ";
		}
		juego.SetEscena(new partida(aux));
	}
	
		if(mutee){
			s_volumen.setTexture(mute);
			juego.s_mute();
		}else{
			s_volumen.setTexture(volumen);
			juego.s_desmute();
		}
}
void menu::ProcesarEvento(Event &e)
{

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		nombre_ingresado = nombreJugador->getValue();
	} else nombreJugador->processEvent(e);
		
	
	Vector2i mousePosition = Mouse::getPosition();
	
	FloatRect v = s_volumen.getGlobalBounds();
	
	if(v.contains(static_cast<float>(mousePosition.x-220), static_cast<float>(mousePosition.y-100)))
	{
		if (e.type == Event::MouseButtonPressed)
		{
			if (e.mouseButton.button == Mouse::Left)
			{
				if(mutee)
				{
				mutee=0;
				}else {mutee=1;
				}
			}
	}
}
}
void menu::Dibujar(RenderWindow &window)
{
	m_t1.setPosition(window.getSize().x/2.0f,window.getSize().y/2.5f);
	
	m_t2.setPosition(window.getSize().x/2.0f,window.getSize().y/1.5f);
	
	m_t3.setPosition((window.getSize().x/2.0f)-110,window.getSize().y/1.8f);
	
	nombreJugador->setPosition(window.getSize().x/2.0f,(window.getSize().y/1.8f)-20);
	
	window.clear({20,20,20});
	window.draw(s_fondo);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(puntaj);
	nombreJugador->update();
	window.draw(*nombreJugador);
	window.draw(s_volumen);
	
	window.display();
}
