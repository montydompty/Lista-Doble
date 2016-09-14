/*Montoya Rangel luis Rodrigo
Definición de los métodos definidos en Nodo.h*/

#include "Nodo.h"

/*Método constructor, crea un nodo con un dato dado por el usuario, establece el anterior y
el siguiente nodo
@params: int, Nodo, Nodo
@result: Nodo*/ 
Nodo::Nodo(int Dato , Nodo* Ant , Nodo* Sig)
{
	this->Dato = Dato;
	this->Ant = Ant;
	this->Sig = Sig;	
}
/*Método constructor, crea un nodo con un dato dado por el usuario
@params: int
@result: Nodo*/
Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
	this->Ant = NULL;
	this->Sig = NULL;
}
/*Cambia el dato guardado en el nodo
@params: int
@result: Null*/
void Nodo::setDato(int Dato)
{
	this->Dato = Dato;
}
/*Establece cual sera el nodo anterior al actual
@params: Nodo
@result: Null*/
void Nodo::setAnt(Nodo* Ant)
{
	this->Ant = Ant;
}
/*Establece cual sera el nodo siguiente al actual
@params: Nodo
@result: Null*/
void Nodo::setSig(Nodo* Sig)
{
	this->Sig = Sig;
}
/*Obtiene el dato guardado en el nodo
@params: NULL
@result: int*/
int Nodo::getDato()
{
	return this->Dato;
}
/*obtiene el nodo anterior al actual
@params: NULL
@result: Nodo*/
Nodo* Nodo::getAnt()
{
	return this->Ant;
}
/*obtiene el nodo siguiente al actual
@params: NULL
@result: Nodo*/
Nodo* Nodo::getSig()
{
	return this->Sig;
}
