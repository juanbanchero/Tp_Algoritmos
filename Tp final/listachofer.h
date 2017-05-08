#ifndef LISTACHOFER_H_INCLUDED
#define LISTACHOFER_H_INCLUDED
#include "listavehi.h"

struct Chofer
{
    char nombre[42];
    char apellido[42];
    char dni[10];
    char contrato[5];
    NodoListaSEVehiculo *listaVehiculos;

};

struct NodoListaSEChofer
{
    Chofer info;             // Datos de el nodo
    NodoListaSEChofer*sgte;  // Puntero al siguiente nodo

};

void ListaChoferInsertarSiguiente (NodoListaSEChofer  *&n, Chofer x);
void ListaChoferBorrarSiguiente(NodoListaSEChofer  *n);
NodoListaSEChofer *ListaChoferObtenerSiguiente(NodoListaSEChofer  *n);
NodoListaSEChofer *ObtenerUltimoChofer(NodoListaSEChofer * p);
NodoListaSEChofer* BuscarChoferPorDNI(NodoListaSEChofer * raiz, char dnibuscado[]);
NodoListaSEChofer* ListaChoferBuscarNodoAnterior(NodoListaSEChofer * raiz, NodoListaSEChofer * anterior_a);
void borrarNodoChofer(NodoListaSEChofer *& raiz, NodoListaSEChofer * aborrar);
void ListaChoferInsertarAlFinal(NodoListaSEChofer *&lista, Chofer x);
void ListaChoferborrarLista(NodoListaSEChofer *&lista);
void ListaChoferListar(NodoListaSEChofer *lista);



#endif // LISTACHOFER_H_INCLUDED
