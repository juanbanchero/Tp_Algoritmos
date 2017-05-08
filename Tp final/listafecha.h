#ifndef LISTAFECHA_H_INCLUDED
#define LISTAFECHA_H_INCLUDED

struct Fecha
{
    char fechaPartida[6];
    char horaPartida[4];
    char fechaLlegada[6];
    char horaLlegada[4];
    char destino;
    int cantpas;
    float costo;
};

struct NodoListaSEFecha
{
    Fecha info;             // Datos de el nodo
    NodoListaSEFecha*sgte;  // Puntero al siguiente nodo

};

void ListaFechaInsertarSiguiente (NodoListaSEFecha  *&n, Fecha x);
NodoListaSEFecha* BuscarFecha(NodoListaSEFecha * raiz, char fechabuscada[]);
//void ListaVehiculoBorrarSiguiente(NodoListaSEVehiculo  *n);
//NodoListaSEVehiculo *ListaMateriaObtenerSiguiente(NodoListaSEVehiculo  *n);
//NodoListaSEVehiculo *ObtenerUltimoMateria(NodoListaSEVehiculo * p);
//NodoListaSEVehiculo* ListaMateriaBuscarNodoAnterior(NodoListaSEVehiculo * raiz, NodoListaSEVehiculo * anterior_a);
//void borrarNodoVehiculo(NodoListaSEVehiculo *& raiz, NodoListaSEVehiculo * aborrar);
//void ListaVehiculoInsertarAlFinal(NodoListaSEVehiculo *&lista, Vehiculo x);
//void ListaVehiculoBorrarLista(NodoListaSEVehiculo *&lista);
//void ListaVehiculoListar(NodoListaSEVehiculo *lista);



#endif // LISTAFECHA_H_INCLUDED
