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
    static void MainMenu(city listofcities[], int capacity);
    static void DisplayOptions(city listofcities[], city matchedCities[], uint8_t selection, int &capacity);
};

class managecity {
public:
    static void AddCity(city listofcities[], int &capacity);
    static void UpdateCity(city listofcities[], city matchedCities[], uint8_t selection, int capacity);
    static void DeleteCity(city listofcities[], city matchedCities[], uint8_t selection, int &capacity);
};

class tools {
public:
   static void ListCities(city listofcities[], int capacity);
    static void SearchCities(city listofcities[], int capacity);
    static void selectCity(city listofcities[], city matchedCities[], uint8_t matchedCount, int capacity);
    static void CalculateDistance(city listofcities[], city matchedCities[],  uint8_t selection, int capacity);
    static void showspecific(city matchedCities[],  uint8_t selection);
    static void SortCity(city listofcities[], int capacity);
};

// class managefile {
//
// };

#endif