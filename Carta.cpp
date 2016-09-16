#include <sstream>
using std::stringstream;
#include "Carta.h"
#include <string>
using std::string;

Carta::Carta(string Simbolo,char Numero,string Color):Simbolo(Simbolo),Numero(Numero),Color(Color){

}

Carta::~Carta(){

}

string Carta::getSimbolo(){
	return this->Simbolo;
}

char Carta::getNumero(){
	return this->Numero;
}

string Carta::getColor(){
	return this->Color;
}

string Carta::toString(){
	stringstream ss;
	ss<<Simbolo<<Numero<<" ";
	return ss.str();
}