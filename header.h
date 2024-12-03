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
    static void DisplayOptions(city listofcities[], city matchedCities[], uint8_t matchedCount, uint8_t selection, uint8_t capacity);
};

class managecity {
public:
    static void AddCity(city listofcities[], uint8_t &capacity);
    static void UpdateCity(city listofcities[], city matchedCities[], uint8_t selection, uint8_t capacity);
    static void DeleteCity(city listofcities[], city matchedCities[], uint8_t selection, uint8_t capacity);
};

class tools {
public:
   static void ListCities(city listofcities[], uint8_t capacity);
    static void SearchCities(city listofcities[], uint8_t capacity);
    static void selectCity(city listofcities[], city matchedCities[], uint8_t matchedCount, uint8_t capacity);
    static void CalculateDistance(city listofcities[], city matchedCities[],  uint8_t selection, uint8_t capacity);
};

#endif