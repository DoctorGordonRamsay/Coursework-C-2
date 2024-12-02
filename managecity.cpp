#include <cstdint>
#include <iostream>
#include "header.h"

#include <cmath>

using std::cout;

void AddCity(std::vector<City> &cities) {
    //Adds a city
    City newCity;

    std::cout << "Enter city name: ";
    std::cin >> newCity.name;

    std::cout << "Enter country: ";
    std::cin >> newCity.country;

    std::cout << "Enter county/state: ";
    std::cin >> newCity.division;

    std::cout << "Enter mayor: ";
    std::cin >> newCity.mayor;

    std::cout << "Enter longitude: ";
    std::cin >> newCity.longitude;

    std::cout << "Enter latitude: ";
    std::cin >> newCity.latitude;

    cities.push_back(newCity);
    std::cout << "City added successfully.\n";
}

