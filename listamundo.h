#ifndef LISTAMUNDO_H
#define LISTAMUNDO_H
#include <string>
#include <string.h>
#include <ctime>
#include <QDebug>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "nodohumano.h"
#include "arbolavl.h"
#include "config.h"
#include "avltest.h"
#include "funcioneshijos.h"

struct Pais;
struct ListaMundo;
struct NodoArbolMundo;
struct ArbolMundo;
struct ArbolApellidos;
struct Continente;

void enviarCorreo(const char* ejecucion);
std::vector<Continente*> ordenarContinentes(std::vector<Continente*> arregloContinentes);
QString determinarCorreoHumano(QString continente);
QString imprimirNodo(NodoHumano* persona);
QString imprimirHumano(NodoHumano* persona);
NodoHumano* buscarAuxiliar(NodoHumano *inicio,NodoHumano *fin,int id);
void insertion_sort (Pais* arregloPaises[], int largo);
std::vector<NodoHumano*> ordenarPecadores(std::vector<NodoHumano*> arregloPecadores, int pLargo);
std::vector<NodoHumano*> ordenarSalvados(std::vector<NodoHumano*> arregloSalvados, int pLargo);
int sumaPecadosHumano(NodoHumano* persona);
NodoHumano* desplazarPuntero(NodoHumano* persona, int cantidad, bool direccion);
int determinarPotenciaCercana(int numero);


struct Continente{

    QString nombreContinente;
    int pecadosTotales;

    Continente(QString pNombreContinente,int pPecadosTotales){
        nombreContinente=pNombreContinente;
        pecadosTotales=pPecadosTotales;
    }


};

struct NodoArbolMundo{
    int id;
    NodoHumano* humano;
    NodoArbolMundo* derecha;
    NodoArbolMundo* izquierda;

    NodoArbolMundo(int pId, NodoHumano* pHumano){
        id = pId;
        humano = pHumano;
        derecha = NULL;
        izquierda = NULL;
    }
};

struct ArbolMundo{
    NodoArbolMundo* raiz;

    ArbolMundo(){
        raiz=NULL;
    }
    NodoArbolMundo* insertarArbolMundo(NodoHumano *humano, NodoArbolMundo* raiz);
    int cantidadNodos(NodoArbolMundo* raiz);
};

struct Pais{
    QString nombrePais;
    int pecadosTotales;

    Pais(QString pNombrePais,int pPecadosTotales){
        nombrePais=pNombrePais;
        pecadosTotales=pPecadosTotales;
    }
};

struct ListaMundo{
    NodoHumano* primerHumano;
    node* arbolMundo;
    node* arregloArbolesApellido[1000];

    ListaMundo(){
        primerHumano = NULL;
        arbolMundo = NULL;
        for(int i = 0; i < 1000; i++){
            arregloArbolesApellido[i] = NULL;
        }
    }
    int cantidadHumanos();
    //void sumarPecados();
    void insertar(int id,QString nombre,QString apellido,QString pais, QString creencia,
                          QString profesion,QString correo);
    void insertar(NodoHumano* pHumano);
    void borrar(NodoHumano* borrado);
    bool existeId(int id);
    NodoHumano* buscar(int id);
    NodoHumano* buscar(int id, node* raiz);
    QString imprimirListaMundo(QString* listaNombrePecados);
    void otorgarPecados();
    QString paisesPecadores(QString* paises,bool top);
    void reemplazarHumano(int id, node* raiz);
    void generarArbol();
    int largoLista();
    int contarNacionales(QString pPais);
    std::vector<NodoHumano*> generarHeapCondenados(QString pPais);
    NodoHumano* mitadLista();
    QString listaCondenadosSalvadosOrdenada(bool cualLista);
    void asignarHijos(NodoHumano* candidato, int indiceApellido);
    void insertarNodoHumano(NodoHumano* humano);
    std::vector <Continente*> mapaCalor();
    QString imprimirOrdenPecados(long long pecadosHumanidad);
    long long sumarPecadosHumanidad();
    ListaMundo* filtrarApellidos(node* arbolApellido, ListaMundo* lista);
    ListaMundo* filtrarLista(QString filtro);
    std::vector<NodoHumano*> filtroApellidoPais(QString apellido,QString pais);
    void insertarAlInicio(NodoHumano* humano);
};
#endif // LISTAMUNDO_H
