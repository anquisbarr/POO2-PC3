//
// Created by Sebastian Q.B on 30/10/2019.
//

#ifndef PC3_DESERIALIZADORCOUNTRY_H
#define PC3_DESERIALIZADORCOUNTRY_H

#include "deserializador.h"
#include "Country.h"
#include <sstream>

class deserializadorCountry :public Deserializador<Country>{
public:
    deserializadorCountry();
    ~deserializadorCountry();
    Country* Deserializar(const string&) override;
};

deserializadorCountry::deserializadorCountry() : Deserializador(){}
deserializadorCountry::~deserializadorCountry() {}

Country* deserializadorCountry::Deserializar(const string& informacion) {
    string campo;
    char delim = ',';
    vector<string> campos;
    stringstream stream(informacion);

    while (getline(stream, campo, delim)){
        campos.push_back(campo);
    }

    if (campos.size() == 10){
        string countryName = campos[0];
        int year = stoi(campos[1]);
        int commCode = stoi(campos[2]);
        string commodity = campos[3];
        string flow = campos[4];
        int tradeUsd = stoi(campos[5]);
        string weight = campos[6];
        string quantity_name = campos[7];
        string quantity = campos[8];
        string category = campos[9];

        return new Country(countryName,year,commCode,commodity,flow,tradeUsd,weight,quantity_name,quantity,category);
    }
    throw logic_error("No se puede crear 'country'");
}
#endif //PC3_DESERIALIZADORCOUNTRY_H
