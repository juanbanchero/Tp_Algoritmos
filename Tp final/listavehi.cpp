#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listavehi.h"
using namespace std;

void ListaVehiculoInsertarSiguiente (NodoListaSEVehiculo  *&n, Vehiculo x)
{
    NodoListaSEVehiculo *nuevo= new NodoListaSEVehiculo();
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

void ListaVehiculoBorrarSiguiente(NodoListaSEVehiculo  *n)
{
    NodoListaSEVehiculo  *aborrar = n->sgte;
    NodoListaSEVehiculo *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSEVehiculo *ListaVehiculoObtenerSiguiente(NodoListaSEVehiculo  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSEVehiculo *ObtenerUltimoVehiculo(NodoListaSEVehiculo * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}


NodoListaSEVehiculo* ListaVehiculoBuscarNodoAnterior(NodoListaSEVehiculo * raiz, NodoListaSEVehiculo * anterior_a)
{
    NodoListaSEVehiculo *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

/*
BorrarNodo: recibe por parámetro lista y el puntero a borrar
*/
void borrarNodoVehiculo(NodoListaSEVehiculo *& raiz, NodoListaSEVehiculo * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSEVehiculo *x = ListaVehiculoBuscarNodoAnterior(raiz,aborrar);
            ListaVehiculoBorrarSiguiente(x);
        }
    }
    return;
}


void ListaVehiculoInsertarAlFinal(NodoListaSEVehiculo *&lista, Vehiculo x)
{
    NodoListaSEVehiculo *aux;
    aux=ObtenerUltimoVehiculo(lista);
    if (aux)
    {
        ListaVehiculoInsertarSiguiente(aux,x);
    }
    else
    {
        ListaVehiculoInsertarSiguiente(lista,x);
    }
    return;
}

void ListaVehiculoBorrarLista(NodoListaSEVehiculo *&lista)
{
    NodoListaSEVehiculo *anterior;
    NodoListaSEVehiculo *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

void ListaVehiculoListar(NodoListaSEVehiculo *lista)
{
    while (lista)
    {
        cout << "Patente: " << lista->info.patente << endl;
        cout << "Marca  : " << lista->info.marca   << endl;
        cout << "Modelo : " << lista->info.modelo  << endl;
        cout << "Anio   : " << lista->info.anio    << endl;
        cout << "Tamanio: " << lista->info.tamanio << endl;
        lista = lista->sgte;
    }
}
