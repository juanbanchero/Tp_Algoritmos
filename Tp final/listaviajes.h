#ifndef LISTAVIAJES_H_INCLUDED
#define LISTAVIAJES_H_INCLUDED
#include "listafecha.h"

struct Viaje
{
    char patente[6];
    NodoListaSEFecha *listaFecha;
};

struct NodoListaSEViaje
{
    Viaje info;             // Datos de el nodo
    NodoListaSEViaje *sgte;  // Puntero al siguiente nodo

};

void ListaViajeInsertarSiguiente (NodoListaSEViaje  *&n, Viaje x);
NodoListaSEViaje* BuscarPatente(NodoListaSEViaje * raiz, char patentebuscada[]);
//void ListaChoferBorrarSiguiente(NodoListaSEChofer  *n);
//NodoListaSEChofer *ListaChoferObtenerSiguiente(NodoListaSEChofer  *n);
//NodoListaSEChofer *ObtenerUltimoChofer(NodoListaSEChofer * p);

//NodoListaSEChofer* ListaChoferBuscarNodoAnterior(NodoListaSEChofer * raiz, NodoListaSEChofer * anterior_a);
//void borrarNodoChofer(NodoListaSEChofer *& raiz, NodoListaSEChofer * aborrar);
//void ListaChoferInsertarAlFinal(NodoListaSEChofer *&lista, Chofer x);
//void ListaChoferborrarLista(NodoListaSEChofer *&lista);
//void ListaChoferListar(NodoListaSEChofer *lista);


#endif // LISTAVIAJES_H_INCLUDED
