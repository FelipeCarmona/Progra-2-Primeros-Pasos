/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoOrdenadoDeEnterosInt.h
 * Author: Luis
 *
 * Created on 11 de agosto de 2016, 01:26 PM
 */

#ifndef CONJUNTOORDENADODEENTEROSINT_H
#define CONJUNTOORDENADODEENTEROSINT_H
#include <string>
using namespace std;
class ConjuntoOrdenadoDeEnterosInt {
    //Representar un conjunto ordenado de enteros
public:
    //EFE: contruye un nuevo conjunto de enteros vacío
    ConjuntoOrdenadoDeEnterosInt();
    //EFE: construye una copia identica e independiente de ¨orig¨
    ConjuntoOrdenadoDeEnterosInt(const ConjuntoOrdenadoDeEnterosInt& orig);
    
    ~ConjuntoOrdenadoDeEnterosInt();
    //MOD:*this
    //EFE: si x no pertenece *this, entonces lo agrega preservando el orden y
    // retorna true, en caso contrario, no tiene efecto y retorna false
    bool insertarOrd(int x);
    
    //MOD: *this
    //EFE: si x pertenece *this, entonces lo elimina preservando el orden y
    // lo retorna, de lo contrario no tiene efecto y retorna false
    bool eliminar(int x);
    
    //EFE: retorna true si x pertenece *this o false en caso contrario
    bool buscar(int x)const;
    
    //EFE:retorna un nuevo cojunto ordenado que representa la union de *this con b
    ConjuntoOrdenadoDeEnterosInt& operator+(const ConjuntoOrdenadoDeEnterosInt& b) const;
    
    //EFE:retorna un nuevo cojunto ordenado que representa la interseccion de *this con b
    ConjuntoOrdenadoDeEnterosInt& operator*(const ConjuntoOrdenadoDeEnterosInt& b) const;
    
    //EFE:retorna un nuevo cojunto ordenado que representa la diferencia de *this con b
    ConjuntoOrdenadoDeEnterosInt& operator-(const ConjuntoOrdenadoDeEnterosInt& b) const;
    
    //EFE:retorna un nuevo cojunto ordenado que representa la diferencia simetrica de *this con b
    ConjuntoOrdenadoDeEnterosInt& operator/(const ConjuntoOrdenadoDeEnterosInt& b) const;
    
    //EFE: retornar una hilera que representa al conjunto que esta resiviendo la operancion
    string aHil();
    
private:
   //int vctInt[100]; arreglo asignado automaticamente
    struct NodInt{//Estructura Empotrada
        int dato;
        NodInt* siguiente;
        //NodInt* anterior;
        NodInt(int x):dato(x),siguiente(0){};
    };
    NodInt* inicio;
    //NodInt* tail;
};

#endif /* CONJUNTOORDENADODEENTEROSINT_H */

