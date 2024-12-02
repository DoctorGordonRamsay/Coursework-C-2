#include <cstdint>
#include <iostream>
#include "header.h"

int MainMenu(cities[x]) { // Displays the main menu.
    std::uint8_t option;
    std::cout << "Select one of the following options \
                        1. Add New City \
                        2. Search City \
                        3. Display full list.";
    std::cin >> option;

    if (option == 1) {
        managecity::AddCity();
        // } else if (option == 2) {
        //     Tools::SearchCities();
         } else if (option == 3) {
             tools::ListCities();
    } else {
        std::cout << "Invalid Option";
    }
    return 0;
}
