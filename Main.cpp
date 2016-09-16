#include "Baraja.h"
#include "Carta.h"
#include "Persona.h"
#include "Repartidor.h"
#include "Jugador.h"
#include "Mesa.h"
#include "Baraja.h"
#include "Administrador.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using std::string;

int main(){
	vector<Persona*> ListaPersonas;
	vector<Mesa*> ListaMesa;
	string Nombre,Edad,ID;
	int OpcionPrincipal,OpcionCreacion,OpcionTemporal,OpcionJugador,OpcionAdministrador,OpcionJuego;

	do
	{
		cout<<"---------Bienvenido---------\n";
		cout<<"1-Crear Persona\n2-Ingresar al Casino\n3-Salir\n:";
		cin>>OpcionPrincipal;
		if (OpcionPrincipal==1)
		{
			do
			{	
				cout<<"---------Bienvenido a la creacion de Personal y Jugadores---------\n";
				cout<<"1-Crear Administrador\n2-Crear Repartidor\n3-Crear Jugador\n4-Salir\n:";
				cin>>OpcionCreacion;
				if(OpcionCreacion==1){
					string Experiencia,Rango,Sueldo;
					cout<<"Ingrese su Nombre:";
					cin>>Nombre;
					cout<<"Ingrese su edad:";
					cin>>Edad;
					cout<<"Ingrese su Numero de Identidad:";
					cin>>ID;
					cout<<"Ingrese su Expiriencia Laboral (en años): ";
					cin>>Experiencia;
					cout<<"1-Gerente Tiempo Completo\n2-Gerente Medio-Tiempo\n3-Gerente General\nIngrese su rango de Administrador:";
					cin>>Rango;
					cout<<"Ingrese el sueldo a propuesto a ganar:";
					cin>>Sueldo;
					ListaPersonas.push_back(new Administrador(Nombre,Edad,ID,Rango,Experiencia,Sueldo));
				}else if(OpcionCreacion==2){
					string Dificultad;
					int MontoMaximo;
					cout<<"Ingrese su Nombre:";
					cin>>Nombre;
					cout<<"Ingrese su edad:";
					cin>>Edad;
					cout<<"Ingrese su Numero de Identidad:";
					cin>>ID;
					cout<<"1-Dificil\n2-Intermedia\n3-Facil\nIngrese la Dificultad del repartidor:";
					cin>>OpcionTemporal;
					if(OpcionTemporal==1){
						Dificultad="Dificil";
					}else if(OpcionTemporal==2){
						Dificultad="Intermedia";
					}else if(OpcionTemporal==3){
						Dificultad="Facil";
					}else{
						Dificultad="Desconocida";
					}
					cout<<"Ingrese el monto de dinero que se le asignara al repartidor:";
					cin>>MontoMaximo;
					ListaPersonas.push_back(new Repartidor(Nombre,Edad,ID,Dificultad,0,MontoMaximo));
				}else if(OpcionCreacion==3){
					string Lugar,Apodo;
					int Dinero;
					cout<<"Ingrese su Nombre:";
					cin>>Nombre;
					cout<<"Ingrese su edad:";
					cin>>Edad;
					cout<<"Ingrese su Numero de Identidad:";
					cin>>ID;
					cout<<"Ingrese su Lugar de procedencia:";
					cin>>Lugar;
					cout<<"Ingrese su apodo de Jugador:";
					cin>>Apodo;
					cout<<"Ingrese su monto de dinero para apuestas:";
					cin>>Dinero;
					ListaPersonas.push_back(new Jugador(Nombre,Edad,ID,Lugar,Apodo,Dinero));

				}
			} while(OpcionCreacion!=4);	
		}else if(OpcionPrincipal==2){
			cout<<"Ingrese su Nombre:";
			cin>>Nombre;
			cout<<"Ingrese su Numero de Identidad:";
			cin>>ID;
			Persona* TemporalPersona;
			for (int i = 0; i <ListaPersonas.size() ; ++i)
			{
				if(Nombre==ListaPersonas.at(i)->getNombre()&&ID==ListaPersonas.at(i)->getID()){
					TemporalPersona=ListaPersonas.at(i);
					if (dynamic_cast<Administrador*>(ListaPersonas.at(i))!=NULL)
					{
						do
						{
							cout<<"1-Modificar Personas\n2-Eliminar Personas\n3-Crear Mesas\n4-Modificar Mesas\n5-Borrar Mesas\n6-Salir\nIngrese su opcion:";
							cin>>OpcionAdministrador;
							if (OpcionAdministrador==1)
							{
								for (int i = 0; i < ListaPersonas.size(); ++i)
								{
									cout<<ListaPersonas.at(i)->toString()<<"\n";
								}		
								cout<<"Ingrese el numero de la persona que desea modificar:";
								cin>>OpcionTemporal;

							}else if(OpcionAdministrador==2){
								
							}
						} while (OpcionAdministrador!=6);
					}else if(dynamic_cast<Jugador*>(ListaPersonas.at(i))!=NULL){
						Mesa* TemporalMesa;
						Jugador* TemporalJugador;
						TemporalJugador=dynamic_cast<Jugador*>(TemporalPersona);
						for (int i = 0; i <ListaMesa.size() ; ++i)
						{
							if(TemporalJugador->getNombre()==ListaMesa.at(i)->getJugador()->getNombre()){
								TemporalMesa=ListaMesa.at(i);
							}
						}
						do
						{
							cout<<"1-Empezar un nuevo juego de BlackJack\n2-Ver Dinero\n3-Salir";
							cin>>OpcionJugador;
							do
							{
								int Apuesta;
								cout<<"Ingrese su apuesta para este juego:";
								cin>>Apuesta;
								for (int i = 0; i < 2; ++i)
									{
										TemporalJugador->setMano(TemporalMesa->getRepartidor()->Repartir());
										TemporalMesa->getRepartidor()->setMano(TemporalMesa->getRepartidor()->Repartir());
									}	
								TemporalMesa->getRepartidor()->setMano(TemporalMesa->getRepartidor()->Repartir());	
								cout<<"1-Ver Cartas\n2-Pedir Carta\n3-Mostrar Cartas\nIngrese su opcion:";
								cin>>OpcionJuego;
								if(OpcionJuego==1){
									cout<<TemporalJugador->verMano();
								}else if(OpcionJuego==2){
									TemporalJugador->setMano(TemporalMesa->getRepartidor()->Repartir());
								}else if(OpcionJuego==3){
									cout<<TemporalJugador->verMano()<<"\n";
									cout<<TemporalMesa->getRepartidor()->verMano();

								}
							} while (OpcionJuego!=4);
						} while (OpcionJugador!=3);
					}
				}
			}	

		}
	} while (OpcionPrincipal!=3);

}