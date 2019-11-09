//
// Created by Sebastian Q.B on 30/10/2019.
//

#ifndef PC3_SERIALIZADORCOUNTRY_H
#define PC3_SERIALIZADORCOUNTRY_H

#include "serializador.h"
#include "Country.h"
#include <sstream>

template <class T>
class serializadorCountry:public Serializador<Country>{
public:
    serializadorCountry();
    ~serializadorCountry();
    string Serializar(T*) override;
};

template <class T>
serializadorCountry<T>::serializadorCountry():Serializador(){}

template <class T>
serializadorCountry<T>::~serializadorCountry() {}

template <class T>
string serializadorCountry<T>::Serializar(T *country) {
    string delim = ",";
    int year = country->getYear();
    int commCode = country->getCommCode();
    int tradeUsd = country->getTradeUsd();
    return  country->getCountryName()+ delim+
            to_string(year) + delim +
            to_string(commCode)+ delim +
            country->getCommodity() + delim +
            country->getFlow() + delim +
            to_string(tradeUsd) + delim +
            country->getWeight() + delim +
            country->getQuantityName() + delim +
            country->getQuantity() + delim +
            country->getCategory();
}
#endif //PC3_SERIALIZADORCOUNTRY_H
