#ifndef PUNTAJES_H
#define PUNTAJES_H
#include <vector>
#include "puntajes.h"
using namespace std;
struct puntaje{
	char nombre[10];
	int puntos;
};
class puntajes {
public:
	puntajes();
	int getMaxScore();
	bool NewScore(puntaje &p);
	vector<puntaje> getPuntajes();
private:
	vector<puntaje> puntajesTop;
};

#endif

