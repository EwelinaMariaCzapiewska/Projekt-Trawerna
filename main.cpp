#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Customer {
    string name;               
    bool isDelivery;           
    int tableNumber;           
    string deliveryAddress;    
    int deliveryHour;          
};

// USTAWIENIA

string restauracja_nazwa = "Restauracja Trawerna";
string restauracja_adres = "ul. Kwiatowa";
string restauracja_owner = "Jan Kowalski";
int restauracja_start = 10;    
int restauracja_koniec = 23;  

// FUNKCJE 

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

void getCustomerInfo(Customer& customer) {
    cout << "--- PODAJ SWOJE DANE ---" << endl;
    cout << "Podaj swoje imię: ";
    getline(cin, customer.name);  // Czyta całą linię (przechwyci spacje)
    cout << endl;

    // Krok 2: Wybór miejsca (na miejscu czy dostawa)
    int choice;
    bool validChoice = false;

    while (!validChoice) {  // Pętla - powtarza się aż do prawidłowego wyboru
        cout << "Gdzie chcesz zamówienie?" << endl;
        cout << "1. Na miejscu (w restauracji)" << endl;
        cout << "2. Dostawa na adres" << endl;
        cout << "Twój wybór (1 lub 2): ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            // Na miejscu - wymagany numer stolika
            customer.isDelivery = false;
            cout << "Podaj numer stolika (1-20): ";
            cin >> customer.tableNumber;
            cout << endl;

            if (customer.tableNumber >= 1 && customer.tableNumber <= 20) {
                validChoice = true;
                cout << "✓ Rezerwacja na stoliku nr " << customer.tableNumber << endl;
            } else {
                cout << "✗ Numer stolika musi być między 1 a 20!" << endl;
                cout << endl;
            }
        } else if (choice == 2) {
            // Dostawa - wymagany adres i godzina
            customer.isDelivery = true;

            cin.ignore();  // Czyści pozostały enter z wcześniejszego cin

            // Pobranie adresu
            cout << "Podaj adres dostawy: ";
            getline(cin, customer.deliveryAddress);

            // Pobranie preferowanej godziny
            bool validHour = false;
            while (!validHour) {
                cout << "Podaj preferowaną godzinę dostawy ("
                     << restauracja_start << "-"
                     << restauracja_koniec << "): ";
                cin >> customer.deliveryHour;
                cout << endl;

                // Sprawdzenie czy godzina jest w zakresie
                if (isValidHour(customer.deliveryHour)) {
                    validHour = true;
                    cout << "✓ Dostawa o godzinie " << customer.deliveryHour << ":00" << endl;
                } else {
                    cout << "✗ Godzina musi być między " << restauracja_start
                         << " a " << restauracja_koniec << "!" << endl;
                    cout << endl;
                }
            }
            validChoice = true;
        } else {
            // Nie 1 ani 2 - nieprawidłowy wybór
            cout << "✗ Podaj 1 lub 2!" << endl;
            cout << endl;
        }
    }
}

// Sprawdza czy godzina jest w zakresie działania restauracji


// Wyświetla menu (na razie tylko placeholder)
void displayMenu() {
    cout << "--- DOSTĘPNE DANIA ---" << endl;
    cout << "1. Pizza Margherita - 25 PLN" << endl;
    cout << "2. Pasta Carbonara - 30 PLN" << endl;
    cout << "3. Stek wołowy - 50 PLN" << endl;
    cout << "4. Sałatka Cezara - 20 PLN" << endl;
    cout << "(system menu będzie zrobiony w następnym etapie)" << endl;
}

int main() {
    
     

    // Utworzenie obiektu klienta
    Customer customer;


    cout << "===============================================" << endl;
    cout << "        WITAJ W SYSTEMIE ZAMÓWIANIA DAŃ        " << endl;
    cout << "===============================================" << endl;
    cout << endl;


    displayRestaurantInfo();
    cout << endl;

  
    getCustomerInfo(customer);
    cout << endl;

  
    cout << "KROK 2: Wybierz swoje dania" << endl;
    displayMenu();
    cout << endl;

   
    cout << "===============================================" << endl;
    cout << "            PODSUMOWANIE ZAMÓWIENIA           " << endl;
    cout << "===============================================" << endl;
    cout << "To będzie zrobione w kolejnym etapie" << endl;
    cout << endl;

    return 0;  
}


