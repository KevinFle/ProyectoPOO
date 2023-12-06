#include "tablero.h"
#include <cstdlib>
#include <ctime>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
using namespace std;

tablero::tablero(int x,int y){
	memset(board,0,sizeof(board));
	posx=x;
	posy=y;
	for(int i = 0; i < tamy; i++){
		for(int j = 0; j < tamx; j++){
			boardShapes[i][j]=RectangleShape(Vector2f(20,20));
			boardShapes[i][j].setPosition(j*20+posx,i*20+posy);
			boardShapes[i][j].setFillColor(Color(50,50,50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(Color(0,0,0));
		}
	}
	srand(time(0));
}

int tablero::getSiguientePieza(){
	return siguientePieza;
}

void tablero::calcularSiguientePieza()
{
	siguientePieza=rand()%7;
}


bool tablero::instalarPieza(){
	indNuevaPieza=siguientePieza;
	vector<vector<bool>> piez = pieza.consultarforma(indNuevaPieza);
	
	int sz = (int)piez.size();
	
	indY=0;
	indX=5-sz/2;
	
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if(piez[i][j]){
				if(board[i][j+indX]>0) return false;
				board[i][j+indX]=-1;
			}
		}
	}
	
	int color = 1+rand()%7;
	indColorNuevaPieza=color;
	
	switch(color){
	case 1: ColorNuevaPieza=Color(0,255,255);break;
	case 2: ColorNuevaPieza=Color(255,255,0);break;
	case 3: ColorNuevaPieza=Color(128,0,128);break;
	case 4: ColorNuevaPieza=Color(0,255,0);break;
	case 5: ColorNuevaPieza=Color(255,0,0);break;
	case 6: ColorNuevaPieza=Color(0,0,255);break;
	case 7: ColorNuevaPieza=Color(255,127,0);break;
	}
	calcularSiguientePieza();
	return true;
}

bool tablero::ActualizarTablero(){
	bool limit = 0;
	int aux;
	
	if(timer>=limitTimer){
		aux=0;
		for(int i = tamy-2; i>=0; i--){
			for(int j = 0; j < tamx; j++){
				if(board[i][j]==-1){
					if(board[i+1][j]<=0) aux++;
				}
			}
		}
		
		if(aux==4){
			indY++;
			for(int i = tamy-2; i>=0; i--){
				for(int j = 0; j < tamx; j++){
					if(board[i][j]==-1){
						board[i][j]=0;
						board[i+1][j]=-1;
					}
				}
			}			
		}else{
			for(int i = tamy-1; i>=0; i--){
				for(int j = 0; j < tamx; j++){
					if(board[i][j]==-1) board[i][j]=indColorNuevaPieza;
				}
			}
			limit = 1;	
		}
		
		timer=0;
	}
	
	timer++;
	return limit;
}

void tablero::ActualizarColor(){
	for(int i = 0; i < tamy; i++){
		for(int j = 0; j < tamx; j++){
			switch(board[i][j]){
			case 0: boardShapes[i][j].setFillColor(Color(50,50,50));break;
			case 1: boardShapes[i][j].setFillColor(Color(0,255,255));break;
			case 2: boardShapes[i][j].setFillColor(Color(255,255,0));break;
			case 3: boardShapes[i][j].setFillColor(Color(128,0,128));break;
			case 4: boardShapes[i][j].setFillColor(Color(0,255,0));break;
			case 5: boardShapes[i][j].setFillColor(Color(255,0,0));break;
			case 6: boardShapes[i][j].setFillColor(Color(0,0,255));break;
			case 7: boardShapes[i][j].setFillColor(Color(255,127,0));break;
			default:
				boardShapes[i][j].setFillColor(ColorNuevaPieza);
				break;
			}
		}
	}
}

void tablero::ActualizarLimiteDelTimer(int l){
	limitTimer=l;
}

void tablero::girarPieza(){
	pieza.RotarPieza(indNuevaPieza);
	vector<vector<bool>> piez = pieza.consultarforma(indNuevaPieza);
	
	int sz = (int)piez.size();
	
	for(int i = 0; i  < sz; i++){
		for(int j = 0; j < sz; j++){
			if(piez[i][j]){
				if(indY+i<0||indY+i>=tamy||indX+j<0||indX+j>=tamx||board[indY+i][indX+j]>0){
					pieza.DesRotarPieza(indNuevaPieza);
					return;
				}
			}
		}
	}
	
	for(int i = 0; i < tamy; i++){
		for(int j = 0; j < tamx; j++){
			if(board[i][j]==-1) board[i][j]=0;
		}
	}
	
	for(int i = 0; i  < sz; i++){
		for(int j = 0; j < sz; j++){
			if(piez[i][j]){
				board[i+indY][j+indX]=-1;
			}
		}
	}
}

void tablero::derecha(){
	int aux = 0;
	for(int i = 0; i < tamy; i++){ 
		for(int j = 0; j < tamx-1; j++){
			if(board[i][j]==-1){
				if(board[i][j+1]<=0){
					aux++; 
				}
			}
		}
	}
	
	if(aux==4){
		indX++;
		for(int i = 0; i < tamy; i++){
			for(int j = tamx-1; j >=0; j--){
				if(board[i][j]==-1) board[i][j]=0,board[i][j+1]=-1; 
			}
		}
	}
}

void tablero::izquierda(){
	int aux = 0;
	for(int i = 0; i < tamy; i++){
		for(int j = 1; j < tamx; j++){
			if(board[i][j]==-1){
				if(board[i][j-1]<=0){
					aux++;
				}
			}
		}
	}
	
	if(aux==4){
		indX--;
		for(int i = 0; i < tamy; i++){
			for(int j = 0; j <tamx; j++){
				if(board[i][j]==-1) board[i][j]=0,board[i][j-1]=-1; ///muevo la pieza un lugar abajo 
			}
		}
	}
}


int tablero::verificarLinea(){
	int aux=0,lines=0;
	
	for(int i = tamy-1; i >=0; i--){
		aux=0;
		for(int j = 0; j < tamx; j++){
			if(board[i][j]>0) aux++;
			if(lines>0) board[i+lines][j]=board[i][j],board[i][j]=0;
		}
		if(aux==tamx){
			for(int j = 0; j < tamx; j++) board[i][j]=0;
			lines++;
		}
	}
	
	return lines;
}

void tablero::borrarTablero(){
	memset(board,0,sizeof(board));
}
void tablero::draw(RenderTarget &rt,RenderStates rs) const{
	for(int i = 0; i < tamy; i++){
		for(int j = 0; j < tamx; j++){
			rt.draw(boardShapes[i][j],rs);
		}
	}
}

