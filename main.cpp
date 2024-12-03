#include <cstdint>

#include "header.h"

int main()
{
    uint8_t capacity = 5;
    city listofcities[10] = {  // Pre-existing list of 5 cities
        {{"New York", "USA", "New York", "Eric Adams"}, {40.7128, -74.0060}}, // City 1
        {{"London", "UK", "Greater London", "Sadiq Khan"}, {51.5074, -0.1278}}, // City 2
        {{"Tokyo", "Japan", "Tokyo", "Yuriko Koike"}, {35.6762, 139.6503}}, // City 3
        {{"Berlin", "France", "Île-de-France", "Anne Hidalgo"}, {48.8566, 2.3522}}, // City 4
        {{"Berlin", "Germany", "Berlin", "Franziska Giffey"}, {52.52, 13.4050}} // City 5
    };
    menu::MainMenu(listofcities, capacity);


    return 0;
}
