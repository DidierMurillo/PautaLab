#include "Carta.h"
#include "Baraja.h"
#include <string>
#include <vector>
using std::string;
using namespace std;

Baraja::Baraja(){
	string Simbolo;
	char Numero;
	string Color;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 14; ++j)
		{
			if (i==0)
			{
				Simbolo="♠";
				Color="Negro";
			}else if (i==1)
			{
				Simbolo="♥";
				Color="Rojo";
			}else if (i==2)
			{
				Simbolo="♦";
				Color="Rojo";
			}else if (i==3)
			{
				Simbolo="♣";
				Color="Negro";
			}

			if (j==11)
			{
				Numero='J';
			}else if (j==12)
			{
				Numero='Q';
			}else if (j==13)
			{
				Numero='K';
			}else if (j==1)
			{
				Numero='A';
			}else{
				Numero=j;
			}
			this->baraja.push_back(new Carta(Simbolo,Numero,Color));
		}
	}
}

Baraja::~Baraja(){

}


  
