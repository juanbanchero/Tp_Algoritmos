#ifndef LISTAVEHI_H_INCLUDED
#define LISTAVEHI_H_INCLUDED
struct Vehiculo
{
    char dni[10];
    char patente[7];
    char marca[15];
    char modelo[15];
    int anio;
    int tamanio;
};

struct NodoListaSEVehiculo
{
    Vehiculo info;             // Datos de el nodo
    NodoListaSEVehiculo*sgte;  // Puntero al siguiente nodo

};

void ListaVehiculoInsertarSiguiente (NodoListaSEVehiculo  *&n, Vehiculo x);
void ListaVehiculoBorrarSiguiente(NodoListaSEVehiculo  *n);
NodoListaSEVehiculo *ListaMateriaObtenerSiguiente(NodoListaSEVehiculo  *n);
NodoListaSEVehiculo *ObtenerUltimoMateria(NodoListaSEVehiculo * p);
NodoListaSEVehiculo* ListaMateriaBuscarNodoAnterior(NodoListaSEVehiculo * raiz, NodoListaSEVehiculo * anterior_a);
void borrarNodoVehiculo(NodoListaSEVehiculo *& raiz, NodoListaSEVehiculo * aborrar);
void ListaVehiculoInsertarAlFinal(NodoListaSEVehiculo *&lista, Vehiculo x);
void ListaVehiculoBorrarLista(NodoListaSEVehiculo *&lista);
void ListaVehiculoListar(NodoListaSEVehiculo *lista);
NodoListaSEVehiculo *ListaVehiculoObtenerSiguiente(NodoListaSEVehiculo  *n);



#endif // LISTAVEHI_H_INCLUDED
