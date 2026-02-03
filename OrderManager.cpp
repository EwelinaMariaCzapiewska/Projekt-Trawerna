#include "OrderManager.h"
#include "Restaurant.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

void clearBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getNumber(string message, int min, int max) {
    int value;
    while (true) {
        cout << message;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear();
            clearBuffer();
            cout << "Blad! Podaj liczbe od " << min << " do " << max << ".\n";
        } else {
            clearBuffer();
            return value;
        }
    }
}

MenuItem parseLine(string line) {
    MenuItem item;
    stringstream ss(line);
    string segment;

    if (getline(ss, item.name, '|') && getline(ss, segment, '|') && getline(ss, item.ingredients)) {
        item.price = stoi(segment);
    } else {
        item.name = "BLAD"; item.price = 0;
    }
    return item;
}

vector<MenuItem> loadMenu() {
    vector<MenuItem> menu;
    ifstream file("menu.txt");
    for (string line; getline(file, line); ) {
        if (!line.empty()) menu.push_back(parseLine(line));
    }
    return menu;
}

void displayMenu() {
    cout << "\n--- MENU ---" << endl;
    vector<MenuItem> menu = loadMenu();
    if (menu.empty()) { cout << "Brak menu!" << endl; return; }

    for (int i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].name << " --- " << menu[i].price << " PLN\n"
             << "   (" << menu[i].ingredients << ")" << endl;
    }
}

void getCustomerInfo(Customer& customer) {
    cout << "--- DANE KLIENTA ---" << endl;
    cout << "Podaj imie: ";
    getline(cin, customer.name);

    cout << "\nGdzie jemy?\n1. Na miejscu\n2. Dostawa" << endl;
    int choice = getNumber("Twoj wybor: ", 1, 2);

    if (choice == 1) {
        customer.isDelivery = false;
        customer.tableNumber = getNumber("Podaj numer stolika (1-20): ", 1, 20);
        cout << "OK, stolik nr " << customer.tableNumber << endl;
    } else {
        customer.isDelivery = true;
        cout << "Podaj adres: ";
        getline(cin, customer.deliveryAddress);
        customer.deliveryHour = getNumber("Godzina dostawy (" + to_string(restauracja.startHour) + "-" + to_string(restauracja.endHour) + "): ", restauracja.startHour, restauracja.endHour);
        cout << "OK, dostawa na " << customer.deliveryHour << ":00" << endl;
    }
}

void displaySummary(Customer& c) {
    cout << "\n=== PODSUMOWANIE ===" << endl;
    cout << "Klient: " << c.name << endl;

    if (c.isDelivery) cout << "Dostawa na: " << c.deliveryAddress << " (godz. " << c.deliveryHour << ":00)" << endl;
    else              cout << "Na miejscu, stolik: " << c.tableNumber << endl;

    int total = 0;
    cout << "--------------------" << endl;
    for (int i = 0; i < c.order.size(); i++) {
        cout << i + 1 << ". " << c.order[i].name << "\t" << c.order[i].price << " PLN" << endl;
        total += c.order[i].price;
    }
    cout << "--------------------" << endl;
    cout << "RAZEM: " << total << " PLN" << endl;
}

void takeOrder(Customer& customer) {
    vector<MenuItem> menu = loadMenu();
    if (menu.empty()) {
        cout << "Blad menu." << endl;
        return;
    }

    cout << "\n--- ZAMAWIANIE (0 konczy) ---" << endl;
    while (true) {
        int choice = getNumber("Nr dania > ", 0, menu.size());

        if (choice == 0) {
            if (customer.order.empty()) {
                cout << "[BLAD] Musisz wybrac minimum jedna pozycje z menu!" << endl;
                continue;
            }
            break;
        }

        MenuItem item = menu[choice - 1];
        int sztuki = getNumber("Ile sztuk > ", 0, 100);

        for (int i = 0; i < sztuki; i++){
            customer.order.push_back(item);
        }

        if (sztuki > 0) {
            cout << "+ " << item.name << " * " << sztuki << endl;
        }
    }
}

void saveOrderToFile(Customer& c) {
    string filename = "rachunek_" + c.name + ".txt";

    ofstream file(filename);

    if (file.is_open()) {
        file << "=== RACHUNEK KOŃCOWY ===" << endl;
        file << "Klient: " << c.name << endl;

        if (c.isDelivery) {
            file << "Dostawa na adres: " << c.deliveryAddress << endl;
            file << "Godzina dostawy: " << c.deliveryHour << ":00" << endl;
        } else {
            file << "Zamowienie na miejscu." << endl;
            file << "Stolik numer: " << c.tableNumber << endl;
        }

        file << "--------------------------------" << endl;
        file << "ZAMOWIONE POZYCJE:" << endl;

        int total = 0;

        for (int i = 0; i < c.order.size(); i++) {
            file << i + 1 << ". " << c.order[i].name
                 << " \t| " << c.order[i].price << " PLN" << endl;
            total += c.order[i].price;
        }

        file << "--------------------------------" << endl;
        file << "LACZNIE DO ZAPLATY: " << total << " PLN" << endl;
        file << "================================" << endl;

        file.close();
        cout << "\n[SUKCES] Rachunek zostal zapisany w pliku: " << filename << endl;
    } else {
        cout << "\n[BLAD] Nie udalo sie utworzyc pliku z rachunkiem!" << endl;
    }
}