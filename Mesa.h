#include "Jugador.h"
#include "Repartidor.h"
#include <string>
using std::string;
#pragma once

class Mesa
{
private:
	Repartidor* RepartidorMesa;
	Jugador* JugadorMesa;
	string NumeroMesa;
	string TipoMesa;

public:
	Mesa(string,string);
	~Mesa();
	void setRepartidor(Repartidor*);
	void setJugador(Jugador*);
	void setNumeroMesa(string);
	void setTipoMesa(string);
	string toString();
	Jugador* getJugador();
	Repartidor* getRepartidor();
	
};