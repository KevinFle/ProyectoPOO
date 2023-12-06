#include "puntajes.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

puntajes::puntajes() {
	fstream archivo("puntajes.bin",ios::binary|ios::in);
	vector<puntaje> vaux;
	puntaje aux;
	while(archivo.read((char*)&aux,sizeof(aux)))
	{
		vaux.push_back(aux);
	}
	puntaje nulo;
	string nul="----------";
	strcpy(nulo.nombre,nul.c_str());
	nulo.puntos=0;
	if(vaux.size()<5)
	{
		for(int i=vaux.size();i<5;i++) 
		{  
			vaux.push_back(nulo);
		}
	}
	archivo.close();
	puntajesTop=vaux;
}

int puntajes::getMaxScore()
{
	puntaje aux=puntajesTop[0];
	return aux.puntos;
}
vector<puntaje> puntajes::getPuntajes()
{
	return puntajesTop;
}
bool comparar(const puntaje &a,const puntaje &b){
	return a.puntos>b.puntos;
}
bool puntajes::NewScore(puntaje &p){
	puntaje aux=puntajesTop[4];
	if(p.puntos>aux.puntos)
	{
		puntajesTop.push_back(p);
		sort(puntajesTop.begin(),puntajesTop.end(),comparar);
		fstream archivo("puntajes.bin",ios::binary|ios::out|ios::trunc);
		for(size_t i=0;i<5;i++) 
		{  
			archivo.write((char*)&puntajesTop[i],sizeof(puntajesTop[i]));
		}
		archivo.close();
		return true;
	}
	return false;
}

