/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoOrdenadoDeEnterosInt.cpp
 * Author: Luis
 * 
 * Created on 11 de agosto de 2016, 01:26 PM
 */

#include "ConjuntoOrdenadoDeEnterosInt.h"

ConjuntoOrdenadoDeEnterosInt::ConjuntoOrdenadoDeEnterosInt():inicio(0) {
}

ConjuntoOrdenadoDeEnterosInt::ConjuntoOrdenadoDeEnterosInt(const ConjuntoOrdenadoDeEnterosInt& orig) {
    NodInt* p = orig.inicio;//Va guardar la direccion de inicio
    if (p==0)
        inicio=0;
    else {
        inicio = new NodInt(orig.inicio->dato);
        p = p->siguiente;
        NodInt* ultimo = inicio;
        while(p!=0){
            ultimo->siguiente = new NodInt(p->dato);
            p = p->siguiente;
            ultimo = ultimo ->siguiente;
        }
    }
}

ConjuntoOrdenadoDeEnterosInt::~ConjuntoOrdenadoDeEnterosInt() {
    NodInt* p = inicio;
    NodInt* q = 0;
    while(p != 0){
        q = p ->siguiente;
        delete p;
        p=q;
    }
}

bool ConjuntoOrdenadoDeEnterosInt::insertarOrd(int x){
    bool resultado = false;
    NodInt* p = inicio;
    NodInt* anterior = 0;
    if(inicio == 0){//Se agrega el primer elemeto
        inicio = new NodInt(x);
        resultado = true;
    }else if(inicio->dato > x){// insercion antes del inicio
        p = new NodInt(x);
        p->siguiente = inicio;
        inicio = p;
        resultado = true;
    }else{
      p=inicio; 
      while(p!=0){
          if(p->dato==x)//Para cuando se encuentra x en el conjunto, por lo tanto no se agrega
              p=0;
          else{//todavia no se encuentra, pero no es definitivo
              if(p->dato < x){
                  anterior = p;
                  p = p ->siguiente;
              
          }else//se concliye que no esta
                  p=0;
                  resultado = true;//hay que agregar
          }
      }
      if (resultado){
         p = anterior->siguiente;// p podria ser 0 o null, o no
         anterior ->siguiente = new NodInt(x);
         anterior ->siguiente->siguiente = p;
      }
    }

    
    return resultado;
        
}

 bool ConjuntoOrdenadoDeEnterosInt::eliminar(int x){
     bool resultado = false;
     NodInt* p = inicio;
     NodInt* anterior = 0;
     if(inicio != 0 && inicio->dato <= x)
         if(inicio->dato == x){
             p = inicio->siguiente;
             delete inicio;
             inicio = p;
         }else{
             while(p != 0){//hay que buscar a x
                if(p->dato==x){
                    resultado = true;
                    p=0;
                }else{//hay que seguir buscando
                   if(p->dato < x){
                       anterior = p;
                       p = p->siguiente;
                   } else p=0;//no esta la x en el conjunto
                }
             }
              if(resultado){
                  p = anterior->siguiente->siguiente;
                  delete anterior->siguiente;
                  anterior->siguiente=p;
              }   
         }
         
     return resultado;
 }

bool ConjuntoOrdenadoDeEnterosInt::buscar(int x)const{
    bool resultado = false;
    NodInt* p =inicio;
    while(p!=0){
        if(p->dato==x){//Para cuando se encuentra x en el conjunto
            resultado = true;
            p=0;
        }else{//todavia no se encuentra, pero no es definitivo
            if(p->dato < x)
                p = p ->siguiente;
            else//se concliye que no esta
                p=0;
        }
    }
    return resultado;
}

ConjuntoOrdenadoDeEnterosInt& ConjuntoOrdenadoDeEnterosInt::operator+(const ConjuntoOrdenadoDeEnterosInt& b) const{
}
    
ConjuntoOrdenadoDeEnterosInt& ConjuntoOrdenadoDeEnterosInt::operator*(const ConjuntoOrdenadoDeEnterosInt& b) const{
}
    
ConjuntoOrdenadoDeEnterosInt& ConjuntoOrdenadoDeEnterosInt::operator-(const ConjuntoOrdenadoDeEnterosInt& b) const{
}
    
ConjuntoOrdenadoDeEnterosInt& ConjuntoOrdenadoDeEnterosInt::operator/(const ConjuntoOrdenadoDeEnterosInt& b) const{
}
    
string ConjuntoOrdenadoDeEnterosInt::aHil(){
}