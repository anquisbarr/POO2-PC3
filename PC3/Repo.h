//
// Created by Sebastian Q.B on 11/9/2019.
//

#ifndef PC3_REPO_H
#define PC3_REPO_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <fstream>
#include "serializadorCountry.h" //serializer
#include "deserializadorCountry.h" //deserializer

using namespace std;

template <class T>
class Repo{
protected:
    Serializador<T*> serializador;
    Deserializador<T*> deserializador;
    vector <T>* items;
public:
    Repo(string separator);
    Repo* insert(T item);
    Repo<T>* load_from(string fileName, function<T*(string)> deserializer);
    vector <T>* order_by(function<bool (T,T)> compare);
    Repo<T>* select(string fileName, function<bool(T*)>where, function<bool(T*,T*)> serializer);
    Repo<T>* save(string fileName, function<string (T*)> serializer);
    Repo<T>* save_to(string fileName, function<bool(T*)>where,function<bool(T*,T*)> serializer);
    void select_and_save(string fileName,function<bool(T*)> where, function<bool(T*,T*)> order_by,function <string (T*)> serializer);
    unsigned int count (function<bool (T*)> where);
    T* min(function<bool (T*)> where, function<bool (T*,T*)> comp);
    T* max(function<bool (T*)> where, function<bool (T*,T*)> comp);
    double sum(function<bool (T*)> where, function<bool (T*,T*)> comp);
    int partition(int start, int final);
    virtual ~Repo();
};

template <class T>
Repo<T>::Repo(string separator) {
    serializador = new serializadorCountry<T>();
    deserializador = new deserializadorCountry();
    string fileName = "commodity_trade.csv";
    fstream *archivo = new fstream(fileName,ios_base::in);
    string linea;
    getline(*archivo,linea);
    if(archivo){
        while(getline(*archivo,linea)){
            Country* country = deserializador->Deserializar(linea,separator);
            deserializador->getElementos()->push_back(country);
        }
        archivo->close();
    }
    items = deserializador->getElementos();
    delete archivo;
}

template <class T>
Repo<T>* Repo<T>::insert(T item) {
    items->push_back(item);
    return this;
}

template<class T>
Repo<T>* Repo<T>::load_from(string fileName, function<T *(string)> deserializer) {

}

template <class T>
vector <T>* Repo<T>::order_by(function<bool(T, T)> compare) {
    for (int i =0; i <items->size()-1;i++)
        for(int j = i+1  ; j <items->size(); j++)
            if(compare((*items)[i],(*items)[j]))
                swap ((*items)[i],(*items)[j]);
    return items;
}

template <class T>
Repo<T>* Repo<T>::select(string fileName, function<bool(T *)> where, function<bool(T *, T *)> serializer) {
    vector <T*> result = new vector <T>();
    for (auto item: *items){
        if(where(item))
            result->push_back(item);
    }
}

template <class T>
Repo<T>* Repo<T>::save(string fileName, function<string (T*)> serializer) {
    fstream* archivo = new fstream(fileName,ios_base::out);
    if (archivo){
        for (Country* country: *deserializador->getElementos()){
            *archivo << serializer(country,",");
        }
    }
}

template <class T>
void Repo<T>::select_and_save(string fileName, function<bool(T *)> where, function<bool(T *, T *)> order_by,function<string(T *)> serializer) {
    auto temp = new vector<T*>();
    temp = this->select(where,order_by);
    fstream* file = new fstream(fileName,ios_base::out);
}

template <class T>
unsigned int Repo<T>::count(function<bool(T *)> where) {
    int quantity = 0;
    for (auto item: *items){
        if(where(item)){
            quantity++;
        }
    }
    return quantity;
}

template <class T>
T* Repo<T>::min(function<bool(T *)> where, function<bool(T *, T *)> comp) {
    /*int min = 0;
    for(auto item:*items){
        if(where(item)){
            if(comp(*item,*item)
               //swap(min,*item);
        }
    }*/
}

template <class T>
T* Repo<T>::max(function<bool(T *)> where, function<bool(T *, T *)> comp) {

}

template <class T>
double Repo<T>::sum(function<bool(T *)> where, function<bool(T *, T *)> comp) {

}

template<class T>
Repo<T>::~Repo() {
    for (auto *item: items){
        delete item;
    }
    delete items;
}

#endif //PC3_REPO_H
