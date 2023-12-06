#ifndef PARTIDA_H
#define PARTIDA_H
#include "escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <ctime>

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "tablero.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include "MjPuntajes.h"
#include "puntajes.h"
using namespace std;
using namespace sf;
class partida : public escena {
public:
	partida(string nombreJug);
	void Actualizar(Juego &juego) override;
	void Dibujar(RenderWindow &window)override;
	void ProcesarEvento(Event &e)override;
	void CargarPuntaje(puntajes pun);
private:
	tablero *t;
	string nombreJugador;
	Text p_nombreJugador,puntosTitulo,puntajeMax,nomJugador,puntos,ScoreTitulo,level,nivelTitulo,siguientePieza;
	Font p_font;
	Sonidos sonido;
	Texture fondo,piezai,piezal,piezat,piezaz,piezas,piezaj,piezacuadrado;
	Sprite s_fondo,s_siguientePieza;
	puntaje puntajee;
	int right=0;
	int left=0;
	int up=0;
	int score = 0;
	int maxScore = 0;
	int limite=30;
	int nivel=1;
	bool live = 1;
	int aux=0;
};

#endif

