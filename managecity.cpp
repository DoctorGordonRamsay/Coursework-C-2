#include <cstdint>
#include <iostream>
#include "header.h"

using namespace std;

void managecity::AddCity(city listofcities[], uint8_t &capacity) {

    city newCity;

    cout << "Enter city name: ";
    cin >> newCity.details[0];

    cout << "Enter country: ";
    cin >> newCity.details[1];

    cout << "Enter county/state: ";
    cin >> newCity.details[2];

    cout << "Enter mayor: ";
    cin >> newCity.details[3];

    cout << "Enter longitude: ";
    cin >> newCity.location[0];

    cout << "Enter latitude: ";
    cin >> newCity.location[1];

    listofcities[capacity] = newCity;
    capacity++;

    cout << "City added successfully.\n";
}

void UpdateCity() {
    std::string name;
    std::cout << "Enter the name of the city to update: ";
    std::cin >> name;

    for (city : cities) {
        if (city.name == name) {
            uint8_t option;
            std::cout << "What do you want to modify? \n"
                      << "1. The name of the city \n"
                      << "2. The country \n"
                      << "3. The state/county \n"
                      << "4. The mayor \n"
                      << "5. The longitude \n"
                      << "6. The latitude \n"
                      << "Enter option: ";
            std::cin >> option;

            switch (option) {
                case 1:
                    std::cout << "Enter new name: ";
                    std::cin >> city.name;
                break;
                case 2:
                    std::cout << "Enter new country: ";
                    std::cin >> city.country;
                break;
                case 3:
                    std::cout << "Enter new state/county: ";
                    std::cin >> city.division;
                break;
                case 4:
                    std::cout << "Enter new mayor: ";
                    std::cin >> city.mayor;
                break;
                case 5:
                    std::cout << "Enter new longitude: ";
                    std::cin >> city.longitude;
                break;
                case 6:
                    std::cout << "Enter new latitude: ";
                    std::cin >> city.latitude;
                break;
                default:
                    std::cout << "Invalid option.\n";
                break;
            }
            std::cout << "City updated successfully.\n";
            return;
        }
    }

    std::cout << "City not found.\n";
}


void DeleteCity() {
    std::string name;
    std::cout << "Enter the name of the city to delete: ";
    std::cin >> name;

    for (auto i = cities.begin(); i != cities.end(); ++i) {
        if (i->name == name) {
            cities.erase(i);
            std::cout << "City deleted successfully.\n";
            return;
        }
    }

    std::cout << "City not found.\n";
}