#include <cstdint>
#include <iostream>
#include "header.h"

using namespace std;

void menu::MainMenu(city listofcities[], uint8_t &capacity) { // Displays the main menu.
    bool x = true;
    while (x == true) {
        int option;
        cout << "-----------------------------------------------\n";
        cout << "Select one of the following options \n 1. Add New City \n 2. Search City \n 3. Display full list. \n 0. End Program. \n Select your option: ";
        cin >> option;
        if (option == 1) {
            cout << "Adding new city\n";

            managecity::AddCity(listofcities, capacity);

            } else if (option == 2) {
                tools::SearchCities(listofcities, capacity);
        } else if (option == 3) {
            cout << "You currently have " << capacity << " cities.";
            tools::ListCities(listofcities, capacity);
        }else if (option == 0) {
            cout << "Ending program...";
            x = false;
        } else {
            cout << "Invalid Option\n";
        }
    }
}

int DisplayOptions(city listofcities[]) { // Displays the menu after the user searched for a city.
    std::uint8_t option;
    std::cout << "Select one of the following options \n 1. Update City \n 2. Delete City \n 3. Calculate Distances";
    std::cin >> option;
    switch(option) {
        case 1:
            Managecity::UpdateCity(listofcities);
        break;
        case 2:
            Managecity::DeleteCity(listofcities);
        break;
      //  case 3:
      //      tools::CalculateDistance(city1, city2);
      //  break;
        default:
            std::cout << "invalid option";
    }

}
