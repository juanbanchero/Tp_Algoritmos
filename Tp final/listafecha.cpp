#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listafecha.h"
using namespace std;

void ListaFechaInsertarSiguiente (NodoListaSEFecha  *&n, Fecha x)
{
    NodoListaSEFecha *nuevo= new NodoListaSEFecha();
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

NodoListaSEFecha* BuscarFecha(NodoListaSEFecha * raiz, char fechabuscada[])
{
    NodoListaSEFecha *p=raiz;
    while (p && (strcmp(p->info.fechaPartida,fechabuscada)))
    {
        p = p->sgte;
    }
    return p;
}
