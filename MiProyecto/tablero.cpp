#include "tablero.h"
#include <cstring>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ctime>
#include <cstdlib>
using namespace std;

tablero::tablero() {
	memset(board,0,sizeof(board));
	for(int i=0;i<columna;i++) 
	{  
		for(int j=0;j<fila;j++) 
		{  
			boardShapes[i][j]=RectangleShape(Vector2f(20,20));
			boardShapes[i][j].setPosition(i*20+50,j*20+50);
			boardShapes[i][j].setFillColor(Color(50,50,50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(Color(0,0,0));
		}
	}
}
bool tablero::instalarPieza(){
	srand(time(NULL));
	indNuevaPieza=rand()%7;
	vector<vector<bool>> piez=piezas.consultarforma(indNuevaPieza);
	int size=(int)piez.size();
	for(int i=0;i<size;i++) 
	{  
		for(int j=0;j<size;j++) 
		{  
			if(piez[i][j])
			{
				if(board[i][j]>0){
					return false;
				}
				board[i][j]=-1;
			}
		}
	}
	int color = 1+rand()&7;
	indColorNuevaParte=color;
	switch(color){
		case 0:	ColorNuevaPieza= Color(50,50,50);break;
		case 1: ColorNuevaPieza= Color(255,166,0);break;
		case 2: ColorNuevaPieza= Color(245,152,245);break;
		case 3: ColorNuevaPieza= Color(51,204,153);break;
		case 4: ColorNuevaPieza= Color(255,110,110);break;
		case 5: ColorNuevaPieza= Color(255,264,77);break;
		case 6: ColorNuevaPieza= Color(166,166,255);break;
		case 7: ColorNuevaPieza= Color(138,194,247);break;
	}
	return true;
}
void tablero::ActualizarColor()
{
	for(int i=0;i<columna;i++) {
		for(int j=0;j<fila;j++) {
			switch(board[i][j]){
			case 0: boardShapes[i][j].setFillColor(Color(50,50,50));break;
			case 1: boardShapes[i][j].setFillColor(Color(255,166,0));break;
			case 2: boardShapes[i][j].setFillColor(Color(245,152,245));break;
			case 3: boardShapes[i][j].setFillColor(Color(51,204,153));break;
			case 4: boardShapes[i][j].setFillColor(Color(255,110,110));break;
			case 5: boardShapes[i][j].setFillColor(Color(255,264,77));break;
			case 6: boardShapes[i][j].setFillColor(Color(166,166,255));break;
			case 7: boardShapes[i][j].setFillColor(Color(138,194,247));break;
			default:boardShapes[i][j].setFillColor(ColorNuevaPieza);break;
			}
		}
	}
}
void tablero::borrarTablero(){
	
}
void tablero::draw(RenderTarget &rt,RenderStates rs)const{
	for(int i=0;i<columna;i++) {  
		for(int j=0;j<fila;j++) { 
			rt.draw(boardShapes[i][j],rs);
		}
	}
}
