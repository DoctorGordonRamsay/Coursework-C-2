#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

struct city {
    string details[4];
    double location[2];
};

class menu {
public:
    static void MainMenu(city listofcities[], uint8_t &capacity);
};

class managecity {
public:
    static void AddCity(city listofcities[], uint8_t &capacity);
};

class tools {
public:
   static void ListCities(city listofcities[], uint8_t capacity);
    static void SearchCities(city listofcities[], uint8_t capacity);
};

#endif