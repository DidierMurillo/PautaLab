#include <string>
#include <vector>
#include "Baraja.h"
#include "Repartidor.h"
using std::string;
using namespace std;
#include <sstream>
using std::stringstream;

Repartidor::Repartidor(string Nombre,string Edad,string ID,string Dificultad,int ConteoJuegos,int MontoMaximo):Persona(Nombre,Edad,ID),Dificultad(Dificultad)
,ConteoJuegos(ConteoJuegos),MontoMaximo(MontoMaximo){
	this->BarajaTexas=new Baraja();

}

Repartidor::~Repartidor(){

}

void Repartidor::setDificultad(string Dificultad){
	this->Dificultad=Dificultad;
}

void Repartidor::setConteoJuegos(int ConteoJuegos){
	this->ConteoJuegos=ConteoJuegos;
}

void Repartidor::setMontoMaximo(int MontoMaximo){
	this->MontoMaximo=MontoMaximo;
}

string Repartidor::toString(){
	stringstream ss;
	ss<<Persona::toString()<<"Dificultad:"<<Dificultad<<" Conteo de Juegos: "<<ConteoJuegos<<" Monto Maximo: "<<MontoMaximo;
	return ss.str();
}