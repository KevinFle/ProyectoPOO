#include "Sonidos.h"

Sonidos::Sonidos() {
	musica.openFromFile("musica.ogg");
	musica.setLoop(true);
	musica.setVolume(20);
	
	BufferSonidoLinea.loadFromFile("linea.ogg");
	BufferSonidoNuevoScore.loadFromFile("nuevoscore.ogg");
	BufferSonidoGameOver.loadFromFile("gameover.ogg");
	
	SonidoLinea.setBuffer(BufferSonidoLinea);
	SonidoNuevoScore.setBuffer(BufferSonidoNuevoScore);
	SonidoGameOver.setBuffer(BufferSonidoGameOver);
}

void Sonidos::PlayMusic(){
	musica.play();
}

void Sonidos::PauseMusic(){
	musica.pause();
}

void Sonidos::PlayLine(){
	SonidoLinea.play();
}

void Sonidos::PlayGameOver(){
	SonidoGameOver.play();
}

void Sonidos::PlayNewScore(){
	SonidoNuevoScore.play();
}

void Sonidos::mute(){
	SonidoGameOver.setVolume(0);
	SonidoLinea.setVolume(0);
	SonidoNuevoScore.setVolume(0);
	musica.setVolume(0);
}

void Sonidos::desmute(){
	SonidoGameOver.setVolume(20);
	SonidoLinea.setVolume(20);
	SonidoNuevoScore.setVolume(20);
	musica.setVolume(20);
}
