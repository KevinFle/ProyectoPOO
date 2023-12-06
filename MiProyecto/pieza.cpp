#include "pieza.h"
#include <vector>
using namespace std;

pieza::pieza() {
	forma={{{1,1}, ///forma cuadrado
			{1,1}},
		
		{{0,0,0,0,0},
		{0,0,1,0,0}, /// forma s
		{0,0,1,1,0},
		{0,0,0,1,0},
		{0,0,0,0,0}},
		
		{{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,1,1,0}, /// forma z
		{0,0,1,0,0},
		{0,0,0,0,0}},
			
		{{0,0,0,0,0},
		{0,0,1,1,0},
		{0,0,1,0,0}, /// L
		{0,0,1,0,0},
		{0,0,0,0,0}},
			
		{{0,0,0,0,0},
		{0,1,1,0,0},
		{0,0,1,0,0}, ///L AL REVES
		{0,0,1,0,0},	
		{0,0,0,0,0}},
			
		{{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,1,0}, ///forma T
		{0,0,1,0,0},	
		{0,0,0,0,0}},
			
		{{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},  /// forma I
		{0,0,1,0}}};
}

vector<vector<bool>> pieza::consultarforma(int ind){
	return forma[ind];
}

void pieza::RotarPieza(int ind){
	vector<vector<bool>> aux=forma[ind];
	int indI=0,indJ=0;
	int size=(int)forma[ind].size();
	for(int i=0;i<size;i++)
	{
		for(int j=size-1;j>=0;j--){
			forma[ind][indI][indJ]=aux[j][i];
			indJ++;
		}
		indI++;
		indJ=0;
	}
}

void pieza::DesRotarPieza(int ind){
	vector<vector<bool>> aux=forma[ind];
	int indI=0,indJ=0;
	int size=(int)forma[ind].size();
	for(int i=size-1;i>=0;i--)
	{
		for(int j=0;j<size;j++){
			forma[ind][indI][indJ]=aux[j][i];
			indJ++;
		}
		indI++;
		indJ=0;
	}
}
