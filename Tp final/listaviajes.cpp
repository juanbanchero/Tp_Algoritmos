#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaviajes.h"
#include "listafecha.h"

using namespace std;

void ListaViajeInsertarSiguiente (NodoListaSEViaje  *&n, Viaje x)
{
    NodoListaSEViaje *nuevo= new NodoListaSEViaje();
    x.listaFecha=NULL;
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}


NodoListaSEViaje* BuscarPatente(NodoListaSEViaje * raiz, char patentebuscada[])
{
    NodoListaSEViaje *p=raiz;
    while (p && (strcmp(p->info.patente,patentebuscada)))
    {
        p = p->sgte;
    }
    return p;
}
