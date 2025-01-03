#include <cstdint>
#include <iostream>
#include "header.h"

using namespace std;

void managecity::AddCity(city listofcities[], int &capacity) { //Adds a new city.

    if (capacity <= 100) {
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

        //similarity-checker

        uint8_t similarityscore;

        for (int i = 0; i < capacity; i++) {
            similarityscore = 0;

            if (newCity.details[0] ==  listofcities[i].details[0]) {
                similarityscore++;
            }
            if (newCity.details[1] ==  listofcities[i].details[1]) {
                similarityscore++;
            }
            if (newCity.details[2] ==  listofcities[i].details[2]) {
                similarityscore++;
            }
            if (newCity.details[3] ==  listofcities[i].details[3]) {
                similarityscore++;
            }
            if (newCity.location[0] ==  listofcities[i].location[0]) {
                similarityscore++;
            }
            if (newCity.location[1] ==  listofcities[i].location[1]) {
                similarityscore++;
            }
        }

        if (similarityscore <= 6) {
            listofcities[capacity] = newCity;
            capacity++;
            tools::SortCity(listofcities, capacity);

            cout << "City added successfully.\n";
        } else {
            cout << "City already exists.\n";
        }

    } else {
        cout << "Max capacity reached, please delete existing cities, before adding new ones.\n";
    }

}

void managecity::UpdateCity(city listofcities[], city matchedCities[], const uint8_t selection, const int capacity) { //Modifies a city.

    for (int i; i < capacity;  i++) {
        if (listofcities[i].location[0] == matchedCities[selection].location[0] and listofcities[i].location[1] == matchedCities[selection].location[1]) {
            int option;
            cout << " \nYour city: " <<  listofcities[i].details[0] << " - " << listofcities[i].details[1] << " - " << listofcities[i].details[2];

            bool x = true;
            while (x) {
                cout << "city info: " << listofcities[i].details[0] << " - " << listofcities[i].details[1] << " - " << listofcities[i].details[2] << " - " << listofcities[i].details[3] << " - " << listofcities[i].location[0] << " - " << listofcities[i].location[1];
                cout << "\nWhat do you want to modify? \n"
                          << "1. The name of the city \n"
                          << "2. The country \n"
                          << "3. The state/county \n"
                          << "4. The mayor \n"
                          << "5. The longitude \n"
                          << "6. The latitude \n"
                            << "0. exit\n"
                          << "Enter option: ";
                cin >> option;

                switch(option) {
                    case 1:
                        cout << "Enter new name: ";
                    cin >> listofcities[i].details[0];
                    tools::SortCity(listofcities, capacity);
;
                    break;
                    case 2:
                        cout << "Enter new country: ";
                    cin >> listofcities[i].details[1];
;
                    break;
                    case 3:
                        cout << "Enter new state/county: ";
                    cin >> listofcities[i].details[2];
;
                    break;
                    case 4:
                        cout << "Enter new mayor: ";
                    cin >> listofcities[i].details[3];
;
                    break;
                    case 5:
                        cout << "Enter new longitude: ";
                    cin >> listofcities[i].location[0];
                    break;
                    case 6:
                        cout << "Enter new latitude: ";
                    cin >> listofcities[i].location[1];
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
    }
}


void managecity::DeleteCity(city listofcities[], city matchedCities[], const uint8_t selection, int &capacity) { //Deletes a city.
    for (int i = 0; i < capacity;  i++) {
        if (listofcities[i].location[0] == matchedCities[selection].location[0] && listofcities[i].location[1] == matchedCities[selection].location[1]) {

            cout << " \nYour city: " <<  listofcities[i].details[0] << " - " << listofcities[i].details[1] << " - " << listofcities[i].details[2];

            for (int j = i; j < capacity - 1; j++) {
                listofcities[j] = listofcities[j + 1];
            }

            capacity = capacity - 1;

            cout << "\ncity successfully deleted.\n";

            //replaces last array slot with empty value, as length can't be modified.

            listofcities[capacity].details[0] = "0";
            listofcities[capacity].details[1] = "0";
            listofcities[capacity].details[2] = "0";
            listofcities[capacity].details[3] = "0";
            listofcities[capacity].location[0] = 0;
            listofcities[capacity].location[1] = 0;

            tools::SortCity(listofcities, capacity);


            break;

        }
    }
}