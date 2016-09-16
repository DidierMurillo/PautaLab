#include "Jugador.h"
#include "Repartidor.h"
#include "Mesa.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

Mesa::Mesa(string NumeroMesa,string TipoMesa):NumeroMesa(NumeroMesa),TipoMesa(TipoMesa){

}

Mesa::~Mesa(){

}

void Mesa::setRepartidor(Repartidor* RepartidorMesa){
	this->RepartidorMesa=RepartidorMesa;
}

void Mesa::setJugador(Jugador* JugadorMesa){
	this->JugadorMesa=JugadorMesa;
}

void Mesa::setNumeroMesa(string NumeroMesa){
	this->NumeroMesa=NumeroMesa;
}

void Mesa::setTipoMesa(string TipoMesa){
	this->TipoMesa=TipoMesa;
}

string Mesa::toString(){
	stringstream ss;
	ss<<"TipoMesa: "<<TipoMesa<<" NumeroMesa: "<<NumeroMesa<<" "<<this->RepartidorMesa->toString()<<" "<<this->JugadorMesa->toString();
	return ss.str();
}

Repartidor* Mesa::getRepartidor(){
	return this->RepartidorMesa;
}

Jugador* Mesa::getJugador(){
	return this->JugadorMesa;
}