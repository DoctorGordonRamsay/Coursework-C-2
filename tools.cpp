#include <cstdint>

#include "header.h"

using namespace std;


void tools::ListCities(city listofcities[], uint8_t capacity) {
    for (int i = 0; i < capacity; i++) {
        cout << "{{"
                  << listofcities[i].details[0] << " "
                  << listofcities[i].details[1] << " "
                  << listofcities[i].details[2] << " "
                  << listofcities[i].details[3] << "}{"
                  << listofcities[i].location[0] << " "
                  << listofcities[i].location[1] << "}}"
                  << std::endl;
    }
}

void tools::SearchCities(city listofcities[], uint8_t capacity) {
    string search;
    cout << "Search city by name: ";
    cin >> search;

    bool found = false;
    city matchedCities[10];
    uint8_t matchedCount = 0;

    for (int i = 0; i < capacity; i++) {
        if (listofcities[i].details[0] == search) {
            if (matchedCount < 10) {
                matchedCities[matchedCount] = listofcities[i];
                matchedCount++;
            }
            found = true;
        }
    }

    if (found) {
        cout << "Cities found:\n";
        for (int i = 0; i < matchedCount; i++) {
            cout << "{{"
                 << matchedCities[i].details[0] << " "
                 << matchedCities[i].details[1] << " "
                 << matchedCities[i].details[2] << " "
                 << matchedCities[i].details[3] << "}{"
                 << matchedCities[i].location[0] << " "
                 << matchedCities[i].location[1] << "}}\n";
        }

    } else {
        cout << search << " was not found.";
    }
}