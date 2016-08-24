/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Luis
 *
 * Created on 11 de agosto de 2016, 01:21 PM
 */

#include <cstdlib>

using namespace std;
#include "ConjuntoOrdenadoDeEnterosInt.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ConjuntoOrdenadoDeEnterosInt a,b;
    ConjuntoOrdenadoDeEnterosInt c = a + b;//une a con b
    ConjuntoOrdenadoDeEnterosInt d = a/ b;//costrutyendo la diferencia simetrica de a y b
    c.insertarOrd(5);
    return 0;
}

