#include <cmath>
#include <cstdint>

#include "header.h"

using namespace std;


void tools::ListCities(city listofcities[], int capacity) { //lists all cities in the array.
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

void tools::SearchCities(city listofcities[], int capacity) { //enables the user to search for a specific city.
    string search;
    cout << "Search city by name: ";
    cin >> search;

    bool found = false;
    city matchedCities[100];
    uint8_t matchedCount = 0;

    for (int i = 0; i < capacity; i++) {
        if (listofcities[i].details[0] == search) {
            matchedCities[matchedCount] = listofcities[i];
            matchedCount++;
            found = true;
        }
    }

    if (found) {
        cout << "Cities found:\n";
        for (int i = 0; i < matchedCount; i++) {
            cout << ""
                 << matchedCities[i].details[0] << " - "
                 << matchedCities[i].details[1] << " - "
                 << matchedCities[i].details[2] << " - "
                 << matchedCities[i].details[3] << " - "
                 << matchedCities[i].location[0] << " - "
                 << matchedCities[i].location[1] << "\n";
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
                    cout << "Returning home\n";
                n = false;
                break;
                default:
                    cout << "invalid option";
            }
        }
    } else {
        cout << search << " was not found.\n";
    }
}

void tools::selectCity(city listofcities[], city matchedCities[], uint8_t matchedCount, int capacity) { //enables the user to select from the list of searched cities.
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

void tools::CalculateDistance(city listofcities[], city matchedCities[],  uint8_t selection, int capacity) {

    uint8_t matchedCount = 0;
    bool found;
    city matchedCities2[100];

    double longitude1 = matchedCities[selection].location[0];
    double latitude1 = matchedCities[selection].location[1];

    //search second city

    string search;
    cout << "Search second city by name: ";
    cin >> search;

    for (int i = 0; i < capacity; i++) {
        if (listofcities[i].details[0] == search) {
            matchedCities2[matchedCount] = listofcities[i];
            matchedCount++;
            found = true;
        } else {
            cout << search << " was not found.";
            found = false;
        }
    }

    if (found) {
        cout << "Cities found:\n";
        for (int i = 0; i < matchedCount; i++) {
            cout << "{{"
                 << matchedCities2[i].details[0] << " "
                 << matchedCities2[i].details[1] << " "
                 << matchedCities2[i].details[2] << " "
                 << matchedCities2[i].details[3] << "}{"
                 << matchedCities2[i].location[0] << " "
                 << matchedCities2[i].location[1] << "}}\n";
        }
        //select second city.

        cout << "select a city:\n";
        for (int i = 0; i < matchedCount; i++) {
            cout << i;
            cout << ":  "
                 << matchedCities2[i].details[0] << "  "
                 << matchedCities2[i].details[1] << "  "
                 << matchedCities2[i].details[2] << "  "
                 << matchedCities2[i].details[3] << "  "
                 << matchedCities2[i].location[0] << "  "
                 << matchedCities2[i].location[1] << "  \n";
        }

        int selection2;
        cout << "Enter the number: ";
        cin >> selection2;

        if (selection2 >= 0 && selection2 < matchedCount) {
            cout << "You selected: " << matchedCities2[selection2].details[0] << " - " << matchedCities2[selection2].details[1] << " - " << matchedCities2[selection2].details[2] << endl;
        } else {
            cout << "Invalid option.\n";
        }

        double longitude2 = matchedCities2[selection2].location[0];
        double latitude2 = matchedCities2[selection2].location[1];

        //Equation

        double distance = acos(sin(latitude1) * sin(latitude2) + cos(latitude1) * cos(latitude2) *cos(longitude1 - longitude2));

        distance = (6371 * M_PI * distance) / 180;

        cout << distance << "\n";
    } else {
        cout << "invalid";
    }
}

void tools::showspecific(city matchedCities[],  uint8_t selection) {
    bool x = true;

    while (x) {
        cout << "What do you want to display?\n";

        int option;

        cout << " 1. Name of city\n"
        << " 2. Country\n"
        << " 3. State/County\n"
        << " 4. Mayor of city\n"
        << " 5. Coordinates of city\n"
        << " 6. longitude\n"
        << " 7. latitude\n"
        << " 0. Exit\n";

        cin >> option;

        switch(option) {
            case 1:
                cout << "Name of city: " << matchedCities[selection].details[0] << "\n";
            break;
            case 2:
                cout << "country: " << matchedCities[selection].details[1] << "\n";
            break;
            case 3:
                cout << "state/county: " << matchedCities[selection].details[2] << "\n";
            break;
            case 4:
                cout << "mayor: " << matchedCities[selection].details[3] << "\n";
            break;
            case 5:
                cout << "coordinates: longitude: " << matchedCities[selection].location[0] << " latitude: " <<  matchedCities[selection].location[1] << "\n";
            break;
            case 6:
                cout << "longitude: " << matchedCities[selection].location[0] << "\n";
            break;
            case 7:
                cout << "latitude: " << matchedCities[selection].location[1] << "\n";
            break;
            case 0:
                x = false;
            break;
            default:
                cout << "Invalid option.\n";
            break;
        }


    }
}