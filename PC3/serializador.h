//
// Created by Sebastian Q.B on 29/10/2019.
//

#ifndef PC3_SERIALIZADOR_H
#define PC3_SERIALIZADOR_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Serializador {
protected:
    vector<T*>* elementos;
public:
    Serializador();
    ~Serializador();
    vector <T*>* getElementos();
    virtual string Serializar(T*) = 0;
};

template <class T>
Serializador<T>::Serializador() {
    elementos = new vector<T*>();
}

template <class T>
Serializador<T>::~Serializador() {
    for (auto elemento: *elementos)
        delete elemento;
    delete elementos;
}

template <class T>
vector<T*>* Serializador<T>::getElementos() {
    return elementos;
}

#endif //PC3_SERIALIZADOR_H
