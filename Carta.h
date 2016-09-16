#include <string>
using std::string;
#pragma once

class Carta
{
private:
	string Simbolo;
	char Numero;
	string Color;

public:
	Carta(string,char,string);
	~Carta();
	string toString();
	char getNumero();
	string getSimbolo();
	string getColor();
};