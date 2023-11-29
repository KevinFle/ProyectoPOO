#ifndef PIEZA_H
#define PIEZA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
using namespace std;
using namespace sf;
	
class pieza {
public:
	pieza();
//	void Dibujar(RenderWindow &window);
//	bool CollideWith(const pieza &p) const;
	vector<vector<bool>> consultarforma(int ind);
	void RotarPieza(int ind);
	void DesRotarPieza(int ind);
private:
	vector<vector<vector<bool>>> forma;
};

#endif

