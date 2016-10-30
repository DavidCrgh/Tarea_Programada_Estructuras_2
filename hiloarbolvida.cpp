#include "hiloarbolvida.h"

HiloArbolVida::HiloArbolVida(QObject* parent, ArbolVida *pArbolVida, ListaMundo* pMundo, Infierno* pInfierno, Paraiso* pParaiso)
{
    stop=false;
    pause=false;
    tiempo = 10;
    arbolVida = pArbolVida;
    mundo = pMundo;
    infierno = pInfierno;
    paraiso = pParaiso;

}

void HiloArbolVida::run(){
    int maximo= 10000000;
    srand(time(NULL));
    while(!stop){
        while(pause){
           msleep(100);
        }
        msleep(tiempo * 1000);
        int id= (1.0*rand()/RAND_MAX)*maximo;
        while(arbolVida->buscar(id, arbolVida->raiz)){
            id= (1.0*rand()/RAND_MAX)*maximo;
        }
        arbolVida->raiz= arbolVida->insertar(id, arbolVida->raiz);

        NodoArbolSplay* buscadoInfierno = infierno->arbolInfierno->buscar(id);
        if(buscadoInfierno != NULL){
            infierno->arbolInfierno->borrar(id);
            infierno->listaCondenados->borrar(buscadoInfierno->humano);
            paraiso->arbolParaiso->insertar(buscadoInfierno->humano);
            paraiso->listaParaiso->insertar(buscadoInfierno->humano->id, buscadoInfierno->humano->nombre, buscadoInfierno->humano->apellido,
                                            buscadoInfierno->humano->pais,buscadoInfierno->humano->creencia, buscadoInfierno->humano->profesion,
                                            buscadoInfierno->humano->correo);
        }

    }
}