#ifndef SONIDOS_H
#define SONIDOS_H
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
using namespace std;
using namespace sf;

class Sonidos {
public:
	Sonidos();
	void PlayMusic();
	void PauseMusic();
	void PlayLine();
	void PlayGameOver();
	void PlayNewScore();
	void mute();
	void desmute();
private:
	Music musica;
	Sound SonidoLinea;
	Sound SonidoNuevoScore;
	Sound SonidoGameOver;
	SoundBuffer BufferSonidoLinea;
	SoundBuffer BufferSonidoNuevoScore;
	SoundBuffer BufferSonidoGameOver;
};

#endif

