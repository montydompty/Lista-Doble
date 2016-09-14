/*Montoya Rangel luis Rodrigo
Definición de los metodos definidos en lista.h*/

#include "Lista.h"

/*Método constructor, crea una lista vacia
@params: NULL
@result: Lista */
Lista::Lista() 
{
	this->H=NULL;
	this->T=NULL;
}
/*Método constructor, crea una lista con un dato dado por el usuario
@params: int
@result: Lista*/
Lista::Lista(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
}
/*Método que revisa si una lista esta vacia
@params: NULL
@result: bool*/
bool Lista::ListaVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}
/*Método que agrega un nodo al inicio de una lista con un dato dado por el usuario 
@params: int
@result: NULL*/
void Lista::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,NULL,this->H);
	if (ListaVacia())
	{
		aux->setSig(NULL);
		this->T = aux;
		this->H = aux;
		return;
	}
	this->H->setAnt(aux);
	this->H= aux;
	return;
}
/*Método que agrega un nodo al final de una lista con un dato dado por el usuario 
@params: int
@result: NULL*/
void Lista::AddFinal(int Dato){
	Nodo * aux = new Nodo(Dato);	
	if (ListaVacia())
	{
		this->H=aux;
		this->T=aux;
		return;
	}
	this->T->setSig(aux);
	aux->setAnt(this->T);
	this->T=aux;
	return;				
}
/*Método que agrega un nodo con un dato dado por el usuario despues de un dato de referencia
@params: int, int
@result: NULL*/
void Lista::AddRef(int Dato, int Ref){
	if (ListaVacia())
	{
		std::cout<<"No se encontro la referencia, lista vacia"<<std::endl;
		return;		
	}
	Nodo * aux = this->H;
	while(aux->getDato()!=Ref && aux!=this->T)
	{
		aux = aux->getSig();
	}
	if (aux->getDato()==Ref)
	{
		Nodo* temp1 = new Nodo(Dato,aux,aux->getSig());
		if(aux==this->T)
		{
			aux->setSig(temp1);
			this->T=temp1;
			return;
		}
		Nodo* temp2 = aux->getSig();
		temp2->setAnt(temp1);
		aux->setSig(temp1);
		return;
	}
	else
	{
		std::cout<<"No existe la referencia en la lista"<<std::endl;
		return;
	}
}
/*Método que remmueve el nodo que se encuentra al inicio de una lista, regresa el dato del nodo eliminado 
@params: NULL
@result: int*/
int Lista::RemoveInicio(){
	if(ListaVacia())
	{
		std::cout<<"Lista Vacia"<<std::endl;
		return NULL;
	}
	int Dato = this->H->getDato();
	if(this->H==this->T)
	{
		this->H=NULL;
		this->T=NULL;
	}
	else
	{
		Nodo* aux = this->H;
		this->H=aux->getSig();
		this->H->setAnt(NULL);
	}
	std::cout<<"El elemento "<<Dato<<" fue removido"<<std::endl;
	return Dato;
}
/*Método que remueve el nodo al final de una lista, regresa el dato del nodo eliminado 
@params: NULL
@result: int*/
int Lista::RemoveFinal(){
	if (ListaVacia())
	{
		std::cout<<"Lista Vacia"<<std::endl;
		return NULL;
	}
	int Dato=T->getDato();
	if (this->H==this->T)
	{
		this->H=NULL;
		this->T=NULL;
	}
	else
	{
		Nodo* aux = this->H;		
		while(aux->getSig()!=this->T)
		{
			aux = aux->getSig();
		}
		this->T=aux;
		this->T->setSig(NULL);
	}
	std::cout<<"El elemento "<<Dato<<" fue removido"<<std::endl;
	return Dato;
}
/*Método que busca un dato en la lista y regresa el nodo asociado
@params: int
@result: Nodo*/
Nodo * Lista::BuscarElemento(int Dato)
{ 
	if (ListaVacia())
	{
		std::cout<<"No se encontro el elemento, lista vacia"<<std::endl;
		return NULL;		
	}
	Nodo *aux = this->H;
	while(aux->getDato()!=Dato && aux!=this->T)
	{
		aux=aux->getSig();	
	}
	if(aux->getDato()!=Dato)
	{	
		std::cout<<"El elemento no se encuentra en la lista"<<std::endl;
		return NULL;
	}	
	std::cout<<"El dato "<<aux->getDato()<< " se encuentro en la lista"<<std::endl;
	return aux;	
}
/*Métpdo que remueve al nodo que tenga la referencia dada por el usuario de la lista
@params: int
@result: Nodo*/
Nodo * Lista::RemoveRef(int Ref)
{
	if (ListaVacia())
	{
		std::cout<<"No se encontro la referencia, lista vacia"<<std::endl;
		return NULL;		
	}
	Nodo * aux = this->H;
	while(aux->getDato()!=Ref && aux!=this->T)
	{
		aux = aux->getSig();
	}
	if(aux==this->H)
	{
		this->H=aux->getSig();
		this->H->setAnt(NULL);
		return aux;
	}
	Nodo * temp1 = this->H;
	while(temp1->getSig()!=aux)
	{
		temp1 = temp1->getSig();
	}
	if(aux==this->T && aux->getDato()==Ref)
	{
		temp1->setSig(NULL);
		this->T=temp1;
		std::cout<<"El elemento "<<Ref<<" fue removido"<<std::endl;
		return aux;
	}
	Nodo* temp2 = aux->getSig();
	if (aux->getDato()==Ref)
	{		
		temp1->setSig(aux->getSig());
		temp2->setAnt(temp1);
		std::cout<<"El elemento "<<Ref<<" fue removido"<<std::endl;
		return aux;
	}
	else
	{
		std::cout<<"La referencia buscada no existe"<<std::endl;
		return NULL;
	}
}
/*Método que vacia la lista borrando las referencias
@params: NULL
@result: NULL*/		
void Lista::VaciarLista()
{
	this->H=NULL;
	this->T=NULL;
	std::cout<<"La lista ha sido vaciada"<<std::endl;
	return;	
}
/*Método que muestra los nodos de la lista
@params: NULL
@result: NULL*/
void Lista::Show()
{
	if (ListaVacia())
	{
		std::cout<<"La lista esta vacia"<<std::endl;
		return;		
	}
	Nodo* aux = this->H;
	while(aux!=NULL)
	{
		std::cout<<aux->getDato()<<std::endl;
		aux=aux->getSig();
	}
	return;
}
