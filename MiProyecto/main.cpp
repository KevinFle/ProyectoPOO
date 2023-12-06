#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "tablero.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;
int main(int argc, char *argv[]){
	Juego tetris;
	tetris.Run();
	return 0;
}

