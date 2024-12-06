#include <cstdint>
#include <iostream>
#include "header.h"

using namespace std;

void menu::MainMenu(city listofcities[], int capacity) { // Displays the main menu.
    bool x = true;
    while (x == true) {
        int option;
        cout << "\n-----------------------------------------------\n";
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

void menu::DisplayOptions(city listofcities[], city matchedCities[], const uint8_t selection, int &capacity) { // Displays the menu after the user searched for a city.
    bool n = true;
    while (n) {
        int options;
        cout << "\n---------------------------------------------\n";
        cout << "Select one of the following options \n 1. Update City \n 2. Delete City \n 3. Calculate Distances\n 4. Show Specific Details\n 0. Return to menu\n";

        cout << " Your city: " <<  matchedCities[selection].details[0] << " - " << matchedCities[selection].details[1] << " - " << matchedCities[selection].details[2];
        cout << "\nEnter your option: ";
        cin >> options;
        if (options == 1) {
            managecity::UpdateCity(listofcities, matchedCities, selection, capacity);
            n = false;
        } else if(options == 2) {
            managecity::DeleteCity(listofcities, matchedCities, selection, capacity);
            n = false;
        } else if (options == 3) {
            tools::CalculateDistance(listofcities, matchedCities, selection, capacity);
            n = false;
        } else if (options == 4) {
            tools::showspecific(matchedCities, selection);
        } else if (options == 0) {
            n = false;
        } else {
            cout << "invalid option";
        }
    }
}
