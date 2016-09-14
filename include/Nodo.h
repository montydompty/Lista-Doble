/*Montoya Rangel luis Rodrigo
Clse nodo con atributos y métodos*/

#include <iostream>

class Nodo
{
private:
	//atributos
	int Dato;
	Nodo* Sig;
	Nodo* Ant;
public:
	//constructores
	Nodo(int Dato, Nodo* Ant, Nodo* Sig);
	Nodo(int Dato);
	//metodos
	void setDato(int Dato);
	void setSig(Nodo* Sig);
	void setAnt(Nodo* Ant);
	int getDato();
	Nodo* getSig();
	Nodo* getAnt();
};
