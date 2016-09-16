#include <string>
#include <vector>
#include "Baraja.h"
#include "Persona.h"
using std::string;
using namespace std;
#pragma once



class Repartidor:public Persona
{
private:
	Baraja* BarajaPoker;
	Baraja* BarajaTexas;
	int ConteoJuegos;
	int MontoMaximo;
	string Dificultad;

public:
	Repartidor(string,string,string,string,int,int);
	~Repartidor();
	void setConteoJuegos(int);
	void setMontoMaximo(int);
	void setDificultad(string);	
	string toString();
};