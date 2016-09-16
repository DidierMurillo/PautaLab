#include "Jugador.h"
#include "Carta.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>
using namespace std;

Jugador::Jugador(string Nombre,string Edad,string ID,string Lugar,string Apodo,int Dinero):Persona(Nombre,Edad,ID),
Lugar(Lugar),Apodo(Apodo),Dinero(Dinero){

}

Jugador::~Jugador(){

}

void Jugador::setLugar(string Lugar){
	this->Lugar=Lugar;
}

void Jugador::setApodo(string Apodo){
	this->Apodo=Apodo;
}

void Jugador::setDinero(int Dinero){
	this->Dinero=Dinero;
}

string Jugador::toString(){
	stringstream ss;
	ss<<Persona::toString()<<"Lugar: "<<Lugar<<" Apodo:"<<Apodo<<" Total Dinero:"<<Dinero;
	return ss.str();
}