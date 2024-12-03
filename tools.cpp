#include <cmath>
#include <cstdint>

#include "header.h"

using namespace std;


void tools::ListCities(city listofcities[], uint8_t capacity) { //lists all cities in the array.
    cout<<"\n";
    cout << "City Name - Country - State/County - Mayor - Longitude - Latitude\n";
    cout << "-----------------------------------------------------------------\n";
    for (int i = 0; i < capacity; i++) {
                cout << listofcities[i].details[0] << " - "
                  << listofcities[i].details[1] << " - "
                  << listofcities[i].details[2] << " - "
                  << listofcities[i].details[3] << " - "
                  << listofcities[i].location[0] << " - "
                  << listofcities[i].location[1] << "\n"
                  << std::endl;
    }
}

void tools::SearchCities(city listofcities[], uint8_t capacity) { //enables the user to search for a specific city.
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

        bool n = true;

        while (n) {
            int option;

            cout << "Do you want to edit the list?\n"
            << "select 1 to proceed\n"
            << "select 2 to return to menu\n";
            cin >> option;

            switch(option){
                case 1:
                    tools::selectCity(listofcities, matchedCities, matchedCount, capacity);
                n = false;
                break;
                case 2:
                    cout << "Returning home";
                n = false;
                break;
                default:
                    cout << "invalid option";
            }
        }
    } else {
        cout << search << " was not found.";
    }
}

void tools::selectCity(city listofcities[], city matchedCities[], uint8_t matchedCount, uint8_t capacity) { //enables the user to select from the list of searched cities.
    cout << "select a city:\n";
    for (int i = 0; i < matchedCount; i++) {
        cout << i;
        cout << ":  "
             << matchedCities[i].details[0] << "  "
             << matchedCities[i].details[1] << "  "
             << matchedCities[i].details[2] << "  "
             << matchedCities[i].details[3] << "  "
             << matchedCities[i].location[0] << "  "
             << matchedCities[i].location[1] << "  \n";
    }

    int selection;
    cout << "Enter the number: ";
    cin >> selection;

    if (selection >= 0 && selection < matchedCount) {
        cout << "You selected: " << matchedCities[selection].details[0] << " - " << matchedCities[selection].details[1] << " - " << matchedCities[selection].details[2] << endl;
        menu::DisplayOptions(listofcities, matchedCities,matchedCount, selection, capacity);
    } else {
        cout << "Invalid option.\n";
    }
}

void tools::CalculateDistance(city listofcities[], city matchedCities[],  uint8_t selection, uint8_t capacity){
    //
    // int longitude1 = matchedCities[selection].location[0];
    // int latitude1 = matchedCities[selection].location[1];
    //
    // //search second city
    //
    // string search;
    // cout << "Search second city by name: ";
    // cin >> search;
    //
    // uint8_t matchedCount = 0;
    // bool found = false;
    // city matchedCities2[10];
    //
    // if (found) {
    //     cout << "Cities found:\n";
    //     for (int i = 0; i < matchedCount; i++) {
    //         cout << "{{"
    //              << matchedCities2[i].details[0] << " "
    //              << matchedCities2[i].details[1] << " "
    //              << matchedCities2[i].details[2] << " "
    //              << matchedCities2[i].details[3] << "}{"
    //              << matchedCities2[i].location[0] << " "
    //              << matchedCities2[i].location[1] << "}}\n";
    //     }
    //
    //
    // for (int i = 0; i < capacity; i++) {
    //     if (listofcities[i].details[0] == search) {
    //         if (matchedCount < 10) {
    //             matchedCities2[matchedCount] = listofcities[i];
    //             matchedCount++;
    //         }
    //         found = true;
    //     } else {
    //         cout << search << " was not found.";
    //     }
    // }
    //
    //     //select city
    //
    //     cout << "select a city:\n";
    //     for (int i = 0; i < matchedCount; i++) {
    //         cout << i;
    //         cout << ":  "
    //              << matchedCities2[i].details[0] << "  "
    //              << matchedCities2[i].details[1] << "  "
    //              << matchedCities2[i].details[2] << "  "
    //              << matchedCities2[i].details[3] << "  "
    //              << matchedCities2[i].location[0] << "  "
    //              << matchedCities2[i].location[1] << "  \n";
    //     }
    //
    //     int selection2;
    //     cout << "Enter the number: ";
    //     cin >> selection2;
    //
    //     if (selection2 >= 0 && selection2 < matchedCount) {
    //         cout << "You selected: " << matchedCities2[selection2].details[0] << " - " << matchedCities2[selection2].details[1] << " - " << matchedCities2[selection2].details[2] << endl;
    //     } else {
    //         cout << "Invalid option.\n";
    //     }
    //
    //     int longitude2 = matchedCities2[selection2].location[0];
    //     int latitude2 = matchedCities2[selection2].location[1];
    //
    // int distance;
    //
    // cos(distance) = sin(latitude1) * sin(latitude2) + cos(latitude1) * cos(latitude2) *cos(longitude1 - longitude2);
    //
    // distance = (6371 * M_PI * distance) / 180;
    //
    // cout << distance;
}