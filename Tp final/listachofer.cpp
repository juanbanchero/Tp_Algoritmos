#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listachofer.h"
#include "listavehi.h"

using namespace std;

void ListaChoferInsertarSiguiente (NodoListaSEChofer  *&n, Chofer x)
{
    NodoListaSEChofer *nuevo= new NodoListaSEChofer();
    x.listaVehiculos=NULL;
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

void ListaChoferBorrarLista(NodoListaSEChofer *&lista)
{
    NodoListaSEChofer *anterior;
    NodoListaSEChofer *paux;
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
            ListaVehiculoBorrarLista(paux->info.listaVehiculos);
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}


void ListaChoferBorrarSiguiente(NodoListaSEChofer  *n)
{
    NodoListaSEChofer  *aborrar = n->sgte;
    NodoListaSEChofer  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    ListaVehiculoBorrarLista(aborrar->info.listaVehiculos);
    delete aborrar;
    return;
}

NodoListaSEChofer *ListaChoferObtenerSiguiente(NodoListaSEChofer  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSEChofer *ObtenerUltimoChofer(NodoListaSEChofer * p)
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

NodoListaSEChofer* BuscarChoferPorDNI(NodoListaSEChofer * raiz, char dnibuscado[])
{
    NodoListaSEChofer *p=raiz;
    while (p && (strcmp(p->info.dni,dnibuscado)))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaSEChofer* ListaChoferBuscarNodoAnterior(NodoListaSEChofer * raiz, NodoListaSEChofer * anterior_a)
{
    NodoListaSEChofer *p =NULL;
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
void borrarNodoChofer(NodoListaSEChofer *& raiz, NodoListaSEChofer * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            ListaVehiculoBorrarLista(aborrar->info.listaVehiculos);
            delete aborrar;
        }
        else
        {
            NodoListaSEChofer *x = ListaChoferBuscarNodoAnterior(raiz,aborrar);
            ListaChoferBorrarSiguiente(x);
        }
    }
    return;
}

void ListaChoferInsertarAlFinal(NodoListaSEChofer *&lista, Chofer x)
{
    NodoListaSEChofer *aux;
    aux=ObtenerUltimoChofer(lista);
    if (aux)
    {
        ListaChoferInsertarSiguiente(aux,x);
    }
    else
    {
        ListaChoferInsertarSiguiente(lista,x);
    }
    return;
}


void ListaChoferListar(NodoListaSEChofer *lista)
{
    while (lista)
    {
        cout << "======== DATOS DEL CHOFER " << lista->info.apellido << "========" << endl;
        cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "N.contrato: " << lista->info.contrato << endl;
        cout << "Listado de vehiculos: " << endl;
        if (lista->info.listaVehiculos)
        {
                ListaVehiculoListar(lista->info.listaVehiculos);
        }
        else
            cout << "El chofer no posee micros." << endl  << endl;
        lista = lista->sgte;
    }
}
