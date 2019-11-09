//
// Created by Sebastian Q.B on 29/10/2019.
//

#ifndef PC3_COUNTRY_H
#define PC3_COUNTRY_H

#include <iostream>
#include <string>
using namespace std;

class Country{
protected:
    string countryName;
    int year;
    int commCode;
    string commodity;
    string flow;
    int tradeUsd;
    string weight;
    string quantity_name;
    string quantity;
    string category;
public:
    Country(const string &, int, int, const string &c, const string &, int,  const string & , const string &,  const string &, const string &);

    virtual ~Country();
    const string &getCountryName() const;
    int getYear() const;
    int getCommCode() const;
    const string &getCommodity() const;
    const string &getFlow() const;
    int getTradeUsd()const;
    const string &getWeight() const;
    const string &getQuantityName() const;
    const string &getQuantity() const;
    const string &getCategory() const;
};

Country::Country(const string &countryName, int year, int commCode, const string &commodity, const string &flow,
                 int tradeUsd, const string &weight, const string &quantityName, const string &quantity,
                 const string &category) : countryName(countryName), year(year), commCode(commCode),
                                           commodity(commodity), flow(flow), tradeUsd(tradeUsd), weight(weight),
                                           quantity_name(quantityName), quantity(quantity), category(category) {}

Country::~Country(){}

//Getters for all vars
const  string& Country::getCountryName() const {return countryName;}
int Country::getYear() const {return year;}
int Country::getCommCode() const {return commCode;}
const  string& Country::getCommodity() const {return commodity;}
const string& Country::getFlow() const {return flow;}
int Country::getTradeUsd() const {return tradeUsd;}
const string& Country::getWeight() const {return weight;}
const string& Country::getQuantityName() const {return quantity_name;}
const string& Country::getQuantity() const {return quantity;}
const string& Country::getCategory() const {return category;}

#endif //PC3_COUNTRY_H
