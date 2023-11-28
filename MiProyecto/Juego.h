#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Juego {
public:
	Juego();
	void Run();
	void Actualizar();
	void ProcesarEventos();
	void dibujar();
protected:
	RenderWindow m_window;
	Texture t_pieza_t;
	Texture t_pieza_cuadrado;
	Texture t_pieza_i;
	Texture t_pieza_L;
	Texture t_pieza_Z;
	vector <Sprite> piez;
	clock_t tiempo;
};

#endif

