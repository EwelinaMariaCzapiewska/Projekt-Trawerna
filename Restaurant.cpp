
#include "Restaurant.h"
#include <iostream>

using namespace std;

string restauracja_nazwa = "Restauracja Trawerna";
string restauracja_adres = "ul. Kwiatowa";
string restauracja_owner = "Jan Kowalski";
int restauracja_start = 10;
int restauracja_koniec = 23;

void displayRestaurantInfo() {
    cout << "--- DANE RESTAURACJI ---" << endl;
    cout << "Nazwa: " << restauracja_nazwa << endl;
    cout << "Adres: " << restauracja_adres << endl;
    cout << "Właściciel: " << restauracja_owner << endl;
    cout << "Godziny otwarcia: " << restauracja_start << ":00 - " << restauracja_koniec << ":00" << endl;
}

bool isValidHour(int hour) {
    return (hour >= restauracja_start && hour <= restauracja_koniec);
}