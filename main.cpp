#include <cstdint>
#include <fstream>
#include "header.h"

int main() {

    //opens the file
    ifstream myFile("listofcities.txt");

    //checks if file was successfully added
    if (myFile.fail()) {
        cout << "Could not detect file";
    } else {
        cout << "File successfully added";
    }

    //Declares the array and capacity
    city listofcities[100];
    uint8_t capacity = 0;

    // Read city data from the file into the listofcities array
    while (myFile >> listofcities[capacity].details[0]
                    >> listofcities[capacity].details[1]
                    >> listofcities[capacity].details[2]
                    >> listofcities[capacity].details[3]
                    >> listofcities[capacity].location[0]
                    >> listofcities[capacity].location[1]) {
        capacity++;

        //checks for capacity
        if (capacity >= 100) {
            cout << "Maximum capacity of 100 cities reached." << endl;
            break;
        }
    }
    tools::SortCity(listofcities, capacity);
    menu::MainMenu(listofcities, capacity);

    myFile.close();
    return 0;
}
