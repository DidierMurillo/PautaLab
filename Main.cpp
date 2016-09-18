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
	Mesa* TemporalMesa;
	Jugador* TemporalJugador;
	Repartidor* TemporalRepartidor;
	string Nombre,Edad,ID;
	int OpcionPrincipal,OpcionCreacion,OpcionTemporal,OpcionJugador,OpcionAdministrador,OpcionJuego;
	ListaPersonas.push_back(new Administrador("1","1","1","1","1","1"));
	ListaPersonas.push_back(new Repartidor("1","1","1","1",1,1));
	ListaPersonas.push_back(new Jugador("2","2","1","1","1",1));
	ListaMesa.push_back(new Mesa("2","2"));
	ListaMesa.at(0)->setRepartidor(dynamic_cast<Repartidor*>(ListaPersonas.at(1)));
	ListaMesa.at(0)->setJugador(dynamic_cast<Jugador*>(ListaPersonas.at(2)));

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
							cout<<"1-Crear Mesas\n2-Modificar Mesas\n3-Borrar Mesas\n4-Salir\nIngrese su opcion:";
							cin>>OpcionAdministrador;
							if (OpcionAdministrador==3)
							{
								for (int i = 0; i < ListaMesa.size(); ++i)
								{
									cout<<"Numero de mesa:"<<i<<ListaMesa.at(i)->toString()<<"\n";
								}
								cout<<"Ingrese el numero de la mesa que desea elimina:";
								cin>>OpcionTemporal;
								ListaMesa.erase(ListaMesa.begin()+OpcionTemporal);
								cout<<"La mesa a sido eliminada!\n";
							}else if(OpcionAdministrador==2){
								for (int i = 0; i < ListaMesa.size(); ++i)
								{
									cout<<"Numero de mesa:"<<i<<ListaMesa.at(i)->toString()<<"\n";
								}
								cout<<"Ingrese el numero de la mesa que desea Modificar:";
								cin>>OpcionTemporal;
								Mesa* TemporalM=ListaMesa.at(OpcionTemporal);
								cout<<"1-Modificar Numero Mesa\n2-Modficar Tipo Mesa\n3-Modificar Repartidor\n4-Modificar Jugador\nIngrese su opcion: ";
								int OpcionMesa;
								string Modificacion;
								cin>>OpcionMesa;
								if(OpcionMesa==1){
									cout<<"Ingrese el nuevo Numero de la mesa:";
									cin>>Modificacion;
									TemporalM->setNumeroMesa(Modificacion);
									cout<<"Se modifico exitosamente!\n";
								}else if(OpcionMesa==2){
									cout<<"1- Mesa V.I.P\n2-Mesa Clasica\n3-Mesa Viajero\nIngrese el tipo de mesa:";
									cin>>OpcionTemporal;
									if (OpcionTemporal==1)
									{
										Modificacion="Mesa V.I.P";
									}else if(OpcionTemporal==2){
										Modificacion="Mesa Claseca";
									}else if(OpcionTemporal==3){
										Modificacion="Mesa Viajero";
									}
									TemporalM->setNumeroMesa(Modificacion);
									cout<<"Se modifico exitosamente!\n";
								}else if(OpcionMesa==3){
									for (int i = 0; i < ListaPersonas.size(); ++i)
									{
										if (dynamic_cast<Repartidor*>(ListaPersonas.at(i))!=NULL)
										{
										TemporalRepartidor=dynamic_cast<Repartidor*>(ListaPersonas.at(i));
										cout<<"Numero Repartidor:"<<i<<TemporalRepartidor->toString()<<"\n";
										}
									}
									cout<<"Ingerese el numero de Repartdior a asignar a la mesa:";
									cin>>OpcionTemporal;
									TemporalM->setRepartidor(dynamic_cast<Repartidor*>(ListaPersonas.at(OpcionTemporal)));
									cout<<"Se modifico exitosamente!\n";
								}else if(OpcionMesa==4){
									for (int i = 0; i < ListaPersonas.size(); ++i)
									{
									if (dynamic_cast<Jugador*>(ListaPersonas.at(i))!=NULL)
									{
										TemporalJugador=dynamic_cast<Jugador*>(ListaPersonas.at(i));
										cout<<"Numero Jugador:"<<i<<TemporalJugador->toString()<<"\n";
									}
								}
								cout<<"Ingerese el numero de Jugador a asignar a la mesa:";
								cin>>OpcionTemporal;
								TemporalM->setJugador(dynamic_cast<Jugador*>(ListaPersonas.at(OpcionTemporal)));
								cout<<"Se modifico exitosamente!\n";
								}
							}else if(OpcionAdministrador==1){
								string TipoMesa,NumeroMesa;
								cout<<"Ingrese el numero de la mesa";
								cin>>NumeroMesa;
								cout<<"1- Mesa V.I.P\n2-Mesa Clasica\n3-Mesa Viajero\nIngrese el tipo de mesa:";
								cin>>OpcionTemporal;
								if (OpcionTemporal==1)
								{
									TipoMesa="Mesa V.I.P";
								}else if(OpcionTemporal==2){
									TipoMesa="Mesa Claseca";
								}else if(OpcionTemporal==3){
									TipoMesa="Mesa Viajero";
								}
								Mesa* TemporalM=new Mesa(NumeroMesa,TipoMesa);
								for (int i = 0; i < ListaPersonas.size(); ++i)
								{
									if (dynamic_cast<Repartidor*>(ListaPersonas.at(i))!=NULL)
									{
										TemporalRepartidor=dynamic_cast<Repartidor*>(ListaPersonas.at(i));
										cout<<"Numero Repartidor:"<<i<<TemporalRepartidor->toString()<<"\n";
									}
								}
								cout<<"Ingerese el numero de Repartdior a asignar a la mesa:";
								cin>>OpcionTemporal;
								TemporalM->setRepartidor(dynamic_cast<Repartidor*>(ListaPersonas.at(OpcionTemporal)));
								for (int i = 0; i < ListaPersonas.size(); ++i)
								{
									if (dynamic_cast<Jugador*>(ListaPersonas.at(i))!=NULL)
									{
										TemporalJugador=dynamic_cast<Jugador*>(ListaPersonas.at(i));
										cout<<"Numero Jugador:"<<i<<TemporalJugador->toString()<<"\n";
									}
								}
								cout<<"Ingerese el numero de Jugador a asignar a la mesa:";
								cin>>OpcionTemporal;
								TemporalM->setJugador(dynamic_cast<Jugador*>(ListaPersonas.at(OpcionTemporal)));
								
							}
						} while (OpcionAdministrador!=4);
					}else if(dynamic_cast<Jugador*>(ListaPersonas.at(i))!=NULL){
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
							if (OpcionJugador==1)
							{
								int Apuesta;
								cout<<"\nIngrese su apuesta para este juego:";
								cin>>Apuesta;
								for (int i = 0; i < 2; ++i)
									{
										TemporalJugador->setMano(TemporalMesa->getRepartidor()->Repartir());
										TemporalMesa->getRepartidor()->setMano(TemporalMesa->getRepartidor()->Repartir());
									}	
								
								do{
									cout<<"1-Ver Cartas\n2-Pedir Carta\n3-Mostrar Cartas\nIngrese su opcion:";
									cin>>OpcionJuego;
									if(OpcionJuego==1){
									cout<<TemporalJugador->verMano()<<"\n";
									cout<<TemporalMesa->getRepartidor()->verMano()<<"\n";
									}else if(OpcionJuego==2){
									TemporalJugador->setMano(TemporalMesa->getRepartidor()->Repartir());
										if(TemporalMesa->getRepartidor()->CalcularMano(0)<=15){
											TemporalMesa->getRepartidor()->setMano(TemporalMesa->getRepartidor()->Repartir());	
										}
									}else if(OpcionJuego==3){
										cout<<TemporalJugador->verMano()<<"\n";
										cout<<TemporalMesa->getRepartidor()->verMano()<<"\n";
										int Resul1,Resul2;
										Resul2=TemporalMesa->getRepartidor()->CalcularMano();
										Resul1=TemporalJugador->CalcularMano();
										cout<<Resul1<<"\n"<<Resul2<<"\n";
										if(Resul2<=Resul1&&Resul1<=21&&Resul2<=21){
											cout<<"Felicidaddes Haz Ganado este Juego!";
											TemporalJugador->setDinero(Apuesta*2);
										}else{
											cout<<"Haz Perdido este Juego!";
											TemporalJugador->setDinero(Apuesta*-1);
										}
									}
									TemporalMesa->getRepartidor()->setBaraja();
								}while(OpcionJuego!=3);		
							}else if(OpcionJugador==2){
								TemporalJugador->toString();
							} 
						} while (OpcionJugador!=3);
					}
				}
			}	

		}
	} while (OpcionPrincipal!=3);

}