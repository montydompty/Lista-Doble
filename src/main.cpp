/*Montoya Rangel luis Rodrigo
Método principal de la lista*/

#include "Lista.h"

int main()
{
	/*Main que utiliza el constructor de lista para crear una lista vacia y probar su funcionamineto*/
	Lista l = Lista();
	l.AddInicio(1);
	l.AddInicio(2);
	l.AddFinal(4);
	l.AddRef(5,2);
	l.BuscarElemento(15);
	l.AddInicio(9);
	l.RemoveInicio();
	l.RemoveFinal();
	l.RemoveRef(2);
	l.BuscarElemento(1);
	l.Show();
	l.VaciarLista();
	l.Show();	
	return 0;
}
