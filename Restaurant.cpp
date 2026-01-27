
#include "Restaurant.h"
#include <iostream>

using namespace std;

Restaurant restauracja = {
    "Restauracja Trawerna",
    "ul. Kwiatowa",
    "Jan Kowalski",
    10,
    23
};

void displayRestaurantInfo() {
    cout << "--- DANE RESTAURACJI ---" << endl;
    cout << "Nazwa: " << restauracja.name << endl;
    cout << "Adres: " << restauracja.address << endl;
    cout << "Właściciel: " << restauracja.owner << endl;
    cout << "Godziny otwarcia: " << restauracja.startHour << ":00 - " << restauracja.endHour << ":00" << endl;
}

bool isValidHour(int hour) {
    return (hour >= restauracja.startHour && hour <= restauracja.endHour);
}