/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConOrdInt.cpp
 * Author: Luis
 *
 * Created on 18 de agosto de 2016, 07:39 AM
 */

#include <stdlib.h>
#include <iostream>
#include "ConjuntoOrdenadoDeEnterosInt.h"

/*
 * Simple C++ Test Suite
 */

void testConjuntoOrdenadoDeEnterosInt() {
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt;
    string h = conjuntoOrdenadoDeEnterosInt.aHil();//Suponemos que el metodo aHil funciona bien
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testConjuntoOrdenadoDeEnterosInt (ConOrdInt) el constructor estandar o el metodo aHil() tiene un fallo message=error message sample" << std::endl;
    }
}

void testConjuntoOrdenadoDeEnterosInt2() {
    ConjuntoOrdenadoDeEnterosInt orig;
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt(orig);
    string h = conjuntoOrdenadoDeEnterosInt.aHil();
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testConjuntoOrdenadoDeEnterosInt2 (ConOrdInt) el constructor de copias o el metodo aHil() tiene un fallo message=error message sample" << std::endl;
    }
}

void testInsertarOrd() {
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt;
    bool result = conjuntoOrdenadoDeEnterosInt.insertarOrd(0);//"{0}"
    string h = conjuntoOrdenadoDeEnterosInt.aHil();
    if (!result || h!="{0}") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (ConOrdInt) hay un fallo en el metodo insertar con x = 0 message=error message sample" << std::endl;
    };
    result = conjuntoOrdenadoDeEnterosInt.insertarOrd(3);
    h = conjuntoOrdenadoDeEnterosInt.aHil();
    if (!result || h!="{0,3}") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (ConOrdInt) hay un fallo en el metodo insertar con x = 0, 3 message=error message sample" << std::endl;
    };
    result = conjuntoOrdenadoDeEnterosInt.insertarOrd(7);
    h = conjuntoOrdenadoDeEnterosInt.aHil();
    if (!result || h!="{0,3,7}") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (ConOrdInt) hay un fallo en el metodo insertar con x = 0, 3, 7 message=error message sample" << std::endl;
    };
}

void testEliminar() {
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt;
    bool result = conjuntoOrdenadoDeEnterosInt.eliminar(0);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (ConOrdInt)hay un fallo en el metodo eliminar con conjunto vacio message=error message sample" << std::endl;
    }
    conjuntoOrdenadoDeEnterosInt.insertarOrd(0);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(3);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(7);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(11);//{0,3,7,11}
    result = conjuntoOrdenadoDeEnterosInt.eliminar(5);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (ConOrdInt)hay un fallo en el metodo eliminar 5 con conjunto {0,3,7,11} message=error message sample" << std::endl;
    }
    
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt2(conjuntoOrdenadoDeEnterosInt);
    result = conjuntoOrdenadoDeEnterosInt2.eliminar(0);
    string h = conjuntoOrdenadoDeEnterosInt2.aHil();
    if (!result||h!="{3,7,11}") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (ConOrdInt)hay un fallo en el metodo eliminar 0 con conjunto {0,3,7,11} message=error message sample" << std::endl;
    }
    
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt3(conjuntoOrdenadoDeEnterosInt);
    result = conjuntoOrdenadoDeEnterosInt3.eliminar(11);
    h = conjuntoOrdenadoDeEnterosInt3.aHil();
    if (!result|| h!="{0,3,7}") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (ConOrdInt)hay un fallo en el metodo eliminar 11 con conjunto {0,3,7,11} message=error message sample" << std::endl;
    }
    
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt4(conjuntoOrdenadoDeEnterosInt);
    result = conjuntoOrdenadoDeEnterosInt4.eliminar(7);
    h = conjuntoOrdenadoDeEnterosInt4.aHil();
    if( !result|| h!= "{0,3,11}") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (ConOrdInt)hay un fallo en el metodo eliminar 7 con conjunto {0,3,7,11} message=error message sample" << std::endl;
    }
}

void testBuscar() {
    ConjuntoOrdenadoDeEnterosInt conjuntoOrdenadoDeEnterosInt;
    
    bool result = conjuntoOrdenadoDeEnterosInt.buscar(5);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (ConOrdInt) hay un fallo en el metodo buscar 5 con el conjunto vacio  message=error message sample" << std::endl;
    }
    conjuntoOrdenadoDeEnterosInt.insertarOrd(0);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(3);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(7);
    conjuntoOrdenadoDeEnterosInt.insertarOrd(11);//{0,3,7,11}
    
    result = conjuntoOrdenadoDeEnterosInt.buscar(5);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (ConOrdInt) hay un fallo en el metodo buscar 5 con el conjunto {0,3,7,11}  message=error message sample" << std::endl;
    }
    
     result = conjuntoOrdenadoDeEnterosInt.buscar(0);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (ConOrdInt) hay un fallo en el metodo buscar 0 con el conjunto {0,3,7,11}  message=error message sample" << std::endl;
    }
   
     result = conjuntoOrdenadoDeEnterosInt.buscar(11);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (ConOrdInt) hay un fallo en el metodo buscar 11 con el conjunto {0,3,7,11}  message=error message sample" << std::endl;
    }
     
     result = conjuntoOrdenadoDeEnterosInt.buscar(7);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (ConOrdInt) hay un fallo en el metodo buscar 7 con el conjunto {0,3,7,11}  message=error message sample" << std::endl;
    }
}

void testUnion(){
    ConjuntoOrdenadoDeEnterosInt a;
    ConjuntoOrdenadoDeEnterosInt b;
    ConjuntoOrdenadoDeEnterosInt c;
    ConjuntoOrdenadoDeEnterosInt d;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(12);
    
    b.insertarOrd(0);
    b.insertarOrd(1);
    
    c.insertarOrd(14);
    
    d.insertarOrd(5);
    d.insertarOrd(9);
    
    ConjuntoOrdenadoDeEnterosInt r1 = a+b;//deberia dar un conjunto "{0,1,4,8,12}"
    string h = r1.aHil();
    if(h != "{0,1,4,8,12}"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (ConOrdInt) hay un fallo en el metodo union de {0,1} y {4,8,12}  message=error message sample" << std::endl;
   
    }
    
    
    ConjuntoOrdenadoDeEnterosInt r2 = a+c;//deberia dar un conjunto "{4,8,12,14}"
    h = r2.aHil();
    if(h != "{4,8,12,14}"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (ConOrdInt) hay un fallo en el metodo union de {4,8,12} y {14}  message=error message sample" << std::endl;
   
    }
    
    ConjuntoOrdenadoDeEnterosInt r3 = a+d;//deberia dar un conjunto "{4,5,8,9,12}"
    h = r1.aHil();
    if(h != "{4,5,8,9,12}"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (ConOrdInt) hay un fallo en el metodo union de {5,9} y {4,8,12}  message=error message sample" << std::endl;
   
    }
    }

void testInterseccion(){
    ConjuntoOrdenadoDeEnterosInt a;
    ConjuntoOrdenadoDeEnterosInt b;
    ConjuntoOrdenadoDeEnterosInt c;
    ConjuntoOrdenadoDeEnterosInt d;
    ConjuntoOrdenadoDeEnterosInt e;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(10);
    a.insertarOrd(12);
    
    b.insertarOrd(5);
    b.insertarOrd(7);
    b.insertarOrd(9);
    
    ConjuntoOrdenadoDeEnterosInt r1 = a*b;
    string h = r1.aHil();
    if(h != "{}"){
        std::cout << "%TEST_FAILED% time=0 testname=testInterseccion (ConOrdInt) hay un fallo en el metodo interseccion de {5,7,9} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    c.insertarOrd(4);
    
     ConjuntoOrdenadoDeEnterosInt r2 = a*c;//{4}
    h = r2.aHil();
    if(h != "{4}"){
        std::cout << "%TEST_FAILED% time=0 testname=testInterseccion (ConOrdInt) hay un fallo en el metodo interseccion de {4} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    d.insertarOrd(8);
    d.insertarOrd(10);
    
    ConjuntoOrdenadoDeEnterosInt r3 = a*d;//{8,10}
    h = r3.aHil();
    if(h != "{8,10}"){
        std::cout << "%TEST_FAILED% time=0 testname=testInterseccion (ConOrdInt) hay un fallo en el metodo interseccion de {8,10} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    
    e.insertarOrd(8);
    e.insertarOrd(10);
    e.insertarOrd(12);
    
     ConjuntoOrdenadoDeEnterosInt r4 = a*e;//{8,10,12}
    h = r4.aHil();
    if(h != "{8,10,12}"){
        std::cout << "%TEST_FAILED% time=0 testname=testInterseccion (ConOrdInt) hay un fallo en el metodo interseccion de {8,10} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    
}

void testDiferencia(){
    
    ConjuntoOrdenadoDeEnterosInt a;
    ConjuntoOrdenadoDeEnterosInt b;
    ConjuntoOrdenadoDeEnterosInt c;
    ConjuntoOrdenadoDeEnterosInt d;
    ConjuntoOrdenadoDeEnterosInt e;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(10);
    a.insertarOrd(12);
    
    b.insertarOrd(5);
    b.insertarOrd(7);
    b.insertarOrd(9);
    
    c.insertarOrd(4);
    c.insertarOrd(8);
    
    d.insertarOrd(5);
    d.insertarOrd(7);
    d.insertarOrd(9);
    d.insertarOrd(11);
    
    e.insertarOrd(7);
    e.insertarOrd(8);
    e.insertarOrd(11);
    e.insertarOrd(12);
    
    ConjuntoOrdenadoDeEnterosInt r1 = a-b;
    string h = r1.aHil();
    if(h != "{4,8,10,12}"){
        std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (ConOrdInt) hay un fallo en el metodo diferencia de {5,7,9} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    
    ConjuntoOrdenadoDeEnterosInt r2 = a-c;//{10,12}
    h = r2.aHil();
    if(h != "{10,12}"){
        std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (ConOrdInt) hay un fallo en el metodo diferencia de {4,8} y {4,8,10,12}  message=error message sample" << std::endl;

    }
    
    ConjuntoOrdenadoDeEnterosInt r3 = b-d;//{}
    h = r3.aHil();
    if(h != "{}"){
        std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (ConOrdInt) hay un fallo en el metodo diferencia de {5,7,9} y {5,7,11}  message=error message sample" << std::endl;

    }
    
    ConjuntoOrdenadoDeEnterosInt r4 = d-e;//{5,9}
    h = r4.aHil();
    if(h != "{5,9}"){
        std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (ConOrdInt) hay un fallo en el metodo diferencia de {5,7,9,11} y {7,8,11,12}  message=error message sample" << std::endl;

    }
}




int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% ConOrdInt" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testConjuntoOrdenadoDeEnterosInt (ConOrdInt)" << std::endl;
    testConjuntoOrdenadoDeEnterosInt();
    std::cout << "%TEST_FINISHED% time=0 testConjuntoOrdenadoDeEnterosInt (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testConjuntoOrdenadoDeEnterosInt2 (ConOrdInt)" << std::endl;
    testConjuntoOrdenadoDeEnterosInt2();
    std::cout << "%TEST_FINISHED% time=0 testConjuntoOrdenadoDeEnterosInt2 (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertarOrd (ConOrdInt)" << std::endl;
    testInsertarOrd();
    std::cout << "%TEST_FINISHED% time=0 testInsertarOrd (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testEliminar (ConOrdInt)" << std::endl;
    testEliminar();
    std::cout << "%TEST_FINISHED% time=0 testEliminar (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testBuscar (ConOrdInt)" << std::endl;
    testBuscar();
    std::cout << "%TEST_FINISHED% time=0 testBuscar (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testUnion (ConOrdInt)" << std::endl;
    testUnion();
    std::cout << "%TEST_FINISHED% time=0 testUnion (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testInterseccion (ConOrdInt)" << std::endl;
    testInterseccion();
    std::cout << "%TEST_FINISHED% time=0 testInterseccion (ConOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testDiferencia (ConOrdInt)" << std::endl;
    testDiferencia();
    std::cout << "%TEST_FINISHED% time=0 testDiferencia (ConOrdInt)" << std::endl;

    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

