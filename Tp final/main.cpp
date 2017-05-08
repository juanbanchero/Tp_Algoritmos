#include <iostream>
#include <stdio.h> //Se agrega para poder usar archivos
#include <conio.h>
#include <cstring>
#include "listaChofer.h"
#include "listaviajes.h"

using namespace std;



/* ------------------------------------------------------------------------------------------- */
/* CARGARDATOSPRUEBA: Función que agrega 4 alumnos en un archivo (sobreescribe si ya existe)   */
/* para poder probar el programa rápidamente                                                   */
/* ------------------------------------------------------------------------------------------- */
void CargarChoferesPrueba()
{
    FILE *fChoferes;
    fChoferes=fopen("choferes.dat","wb");
    Chofer reg;
    if (fChoferes)
    {
        /*SE CARGAN 4 CHOFERES DE PRUEBA */
        strcpy(reg.apellido,"JUAN");
        strcpy(reg.nombre,"BANCHERO");
        strcpy(reg.dni,"41394977");
        strcpy(reg.contrato,"1");
        fwrite(&reg, sizeof(Chofer),1,fChoferes);

        strcpy(reg.apellido,"GIUSEPPE");
        strcpy(reg.nombre,"CIAVIRELLA");
        strcpy(reg.dni,"41335555");
        strcpy(reg.contrato,"2");
        fwrite(&reg, sizeof(Chofer),1,fChoferes);


        strcpy(reg.apellido,"RUBEN");
        strcpy(reg.nombre,"CASTAGNIARES");
        strcpy(reg.dni,"11982128");
        strcpy(reg.contrato,"25");
        fwrite(&reg, sizeof(Chofer),1,fChoferes);


        strcpy(reg.apellido,"JOSE");
        strcpy(reg.nombre,"PEREZ");
        strcpy(reg.dni,"43234122");
        strcpy(reg.contrato,"42");
        fwrite(&reg, sizeof(Chofer),1,fChoferes);

        fclose(fChoferes);
        cout << "El archivo choferes ha sido cargado correctamente" << endl;
    }
    else
        cout << "Error: no se ha podido crear el archivo de choferes" << endl;
    return;
}

/*--------------------------------------------------------------------------*/
void CargarVehiculosPrueba(void)
{
    FILE *fMicros;
    fMicros=fopen("micros.dat","wb");
    Vehiculo reg;
    if (fMicros)
    {
        strcpy(reg.patente,"ISD435");
        strcpy(reg.marca,"IVECO");
        strcpy(reg.dni,"41394977");
        strcpy(reg.modelo,"CURSOR");
        reg.anio=2016;
        reg.tamanio=1;
        fwrite(&reg, sizeof(Vehiculo),1,fMicros);

        strcpy(reg.patente,"AJG546");
        strcpy(reg.marca,"RENAULT");
        strcpy(reg.dni,"41394977");
        strcpy(reg.modelo,"RUTA");
        reg.anio=2015;
        reg.tamanio=2;
        fwrite(&reg, sizeof(Vehiculo),1,fMicros);

        strcpy(reg.patente,"FCK145");
        strcpy(reg.marca,"IVECO");
        strcpy(reg.dni,"41335555");
        strcpy(reg.modelo,"TRACKER");
        reg.anio=2013;
        reg.tamanio=3;
        fwrite(&reg, sizeof(Vehiculo),1,fMicros);

        strcpy(reg.patente,"ABC123");
        strcpy(reg.marca,"SCANIA");
        strcpy(reg.dni,"11982128");
        strcpy(reg.modelo,"R890");
        reg.anio=2010;
        reg.tamanio=4;
        fwrite(&reg, sizeof(Vehiculo),1,fMicros);

        strcpy(reg.patente,"GHF546");
        strcpy(reg.marca,"SCANIA");
        strcpy(reg.dni,"43234122");
        strcpy(reg.modelo,"R470");
        reg.anio=2002;
        reg.tamanio=1;
        fwrite(&reg, sizeof(Vehiculo),1,fMicros);


        fclose(fMicros);
        cout << "El archivo micros ha sido cargado correctamente" << endl;
    }
    else
        cout << "Error: no se ha podido crear el archivo de micros" << endl;
    return;
}

//----------------------------------------------------------------
void LevantarArchivos(NodoListaSEChofer *&listaChofer)
{
    FILE *fChoferes;
    Chofer reg;

    fChoferes=fopen("choferes.dat","rb");
    fread(&reg,sizeof(Chofer),1,fChoferes);
    while (!feof(fChoferes))
    {
        ListaChoferInsertarSiguiente(listaChofer,reg);
        fread(&reg,sizeof(Chofer),1,fChoferes);
    }
    fclose(fChoferes);

    /* levanta archivo de micros */
    FILE *fMicros;
    Vehiculo regv;
    NodoListaSEChofer *aux;

    fMicros=fopen("micros.dat","rb");
    fread(&regv,sizeof(Vehiculo),1,fMicros);
    while (!feof(fMicros))
    {
        aux= BuscarChoferPorDNI(listaChofer, regv.dni);
        if (aux)
        {
            ListaVehiculoInsertarSiguiente(aux->info.listaVehiculos,regv);
        }
        fread(&regv,sizeof(Vehiculo),1,fMicros);
    }
    fclose(fMicros);
    return;
}
/*--------------------------------------------------------------------------*/
char mostrarMenu()
{
    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Ingresar Nuevo Chofer" << endl;
    cout << "2 - Ingresar Nuevo Vehiculo" << endl;
    cout << "3 - Ingresar Nuevo Viaje" << endl;
    cout << "4 - Total de viajes por Chofer" << endl;
    cout << "5 - Pago a Choferes" << endl;
    cout << "esc - Salir" << endl;
    char opcion;
    do
    {
       opcion=getch();
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!=27));
    return opcion;
}
//----------------------------------------------------------------
void nuevoChofer(NodoListaSEChofer *&listaChoferes)
{
 Chofer reg;
 NodoListaSEChofer *aux;

 cout << "Ingrese el dni del chofer: ";
 cin >> reg.dni;

 aux= BuscarChoferPorDNI(listaChoferes, reg.dni);
 if (aux)
 {
  cout << "El dni ya ha sido ingresado, intente nuevamente" << endl;
 }
 else
 {
    cout << "Nombre: ";
    cin >> reg.nombre;
    cout << "Apellido: ";
    cin >> reg.apellido;
    cout << "Nro. contrato: ";
    cin >> reg.contrato;
    ListaChoferInsertarSiguiente(listaChoferes,reg);
    cout << "Se agrego el chofer exitosamente" << endl;
 }
}
//----------------------------------------------------------------
void nuevoMicro(NodoListaSEChofer *&listaChoferes)
{
 Vehiculo reg;
 NodoListaSEChofer *aux;
 char dni[11];

 cout << "Ingrese el dni del chofer: ";
 cin >> dni;

 aux= BuscarChoferPorDNI(listaChoferes,dni);
 if (aux)
 {
  cout << "Ingrese datos del micro: ";
  cout << "Patente: ";
  cin >> reg.patente;
  cout << "Marca: ";
  cin >> reg.marca;
  cout << "Modelo: ";
  cin >> reg.modelo;
  cout << "Anio: ";
  cin >> reg.anio;
  cout << "Tamanio (1 a 4): ";
  cin >> reg.tamanio;
  ListaVehiculoInsertarSiguiente(aux->info.listaVehiculos,reg);
  cout << "Se agrego el micro exitosamente" << endl;
 }
 else
 {
  cout << "No existe el dni de este chofer" << endl;
 }
}
//----------------------------------------------------------------
int BuscarCapacidadEnVector(int vectorTamanio[], int tamanio)
{
  return vectorTamanio[tamanio-1];
}
//----------------------------------------------------------------
void verViajesDelMicro(NodoListaSEViaje *&listaViajes, char patente[], char fechaPartida[],bool &encontre)
{
 NodoListaSEViaje *auxPatente;
 NodoListaSEFecha *auxFecha;
 NodoListaSEFecha *lfecha;

 encontre = false;
 auxPatente = BuscarPatente(listaViajes, patente);
 if (auxPatente)
 {
  lfecha = auxPatente->info.listaFecha;
  auxFecha = BuscarFecha(lfecha, fechaPartida);
  if (auxFecha)
  {
   encontre = true;
  }
 }
}
//----------------------------------------------------------------
void nuevoViaje(NodoListaSEChofer *&listaChoferes, NodoListaSEViaje *&listaViajes)
{
  Fecha reg;
  NodoListaSEChofer *lchofer;
  NodoListaSEVehiculo *lmicro;
  NodoListaSEFecha *lfecha;
  NodoListaSEViaje *lviaje;
  NodoListaSEViaje *aux;
  bool encontre;
  int capacidad;
  Viaje x;

  //el tp pedia que se utilizara un vector
  //cargo la capacidad de cada micro de acuerdo a su tamaño
  //pequeño = 12 plazas, mediano = 24, grande = 40, super = 60
  int vectorTamanio[4] ={12,24,40,60};

  cout <<"Ingrese datos del viaje";
  cout <<"Destino";
  cin >> reg.destino;
  cout <<"Cantidad de pasajeros";
  cin >> reg.cantpas;
  cout <<"Fecha Partida";
  cin >> reg.fechaPartida;
  cout <<"Hora Partida";
  cin >> reg.horaPartida;
  cout <<"Fecha Llegada";
  cin >> reg.fechaLlegada;
  cout <<"Hora Llegada";
  cin >> reg.horaLlegada;
  cout <<"Costo";
  cin >> reg.costo;
  lchofer = listaChoferes;
  //recorro a todos los choferes
  while (lchofer != NULL)
  {
    //recorro los micros de cada chofer
    lmicro = lchofer->info.listaVehiculos;
    while (lmicro != NULL)
    {
     //verifico si la capacidad del micro cubre la cantidad de pasajeros del viaje
     capacidad = BuscarCapacidadEnVector(vectorTamanio,lmicro->info.tamanio);
     if (reg.cantpas <= capacidad)
     {
       //Busco en la lista de viajes si la patente tiene viajes en la fecha solicitada
       verViajesDelMicro(listaViajes,lmicro->info.patente,reg.fechaPartida,encontre);
       if (not encontre)
       {
        cout <<"Patente disponible para hacer el viaje" << lmicro->info.patente << endl;
       }
     }
     lmicro= ListaVehiculoObtenerSiguiente(lmicro);
    }
   lchofer = ListaChoferObtenerSiguiente(lchofer);
  }
  cout << "Ingrese patente con la que desea hacer el viaje";
  cin >> x.patente;
  lfecha = listaViajes->info.listaFecha;
   aux = BuscarPatente(listaViajes,x.patente);

  if (aux)
  {
      strcpy(listaViajes->info.listaFecha,x.patente);
    lfecha=ListaFechaObtenerSiguiente(lfecha);
  }
// ACA TENES QUE BUSCAR A LA PATENTE EN LA LISTAVIAJES
//SI NO EXISTE, LA CARGAS Y LUEGO EN LA SUBLISTA CARGAS EL VIAJE
//SI EXISTE, CARGA EL VIAJE EN LA SUBLISTA
  }
//----------------------------------------------------------------------------------
void totalViajes()
{

}
void pago()
{

}
//----------------------------------------------------------------
int main()
{
   NodoListaSEChofer *listaChoferes;
   NodoListaSEViaje *listaViajes;

   char elegida;

   listaChoferes = NULL;
   listaViajes = NULL;
   CargarChoferesPrueba();
   CargarVehiculosPrueba();
   LevantarArchivos(listaChoferes);
   do
   {
     elegida = mostrarMenu();
     switch (elegida)
     {
      case '1': nuevoChofer(listaChoferes);
      break;

      case '2': nuevoMicro(listaChoferes);
      break;

      case '3': nuevoViaje(listaChoferes,listaViajes);
      break;

      case '4': totalViajes();
      break;

      case '5': pago();
      break;
     }
   }while (elegida !=27);

    return 0;
}
