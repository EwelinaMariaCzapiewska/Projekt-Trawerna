#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  // Do formatowania wydruku (wyrównanie liczb)

using namespace std;

// =====================================================
// KROK 1: Definicje struktur danych
// =====================================================

// Struktura do przechowywania danych restauracji
struct Restaurant {
    string name;        // Nazwa restauracji
    string address;     // Adres restauracji
    string owner;       // Właściciel restauracji
    int openingHour;    // Godzina otwarcia (np. 10)
    int closingHour;    // Godzina zamknięcia (np. 23)
};

// Struktura do przechowywania danych klienta
struct Customer {
    string name;                // Imię klienta
    bool isDelivery;           // true = dostawa, false = na miejscu
    int tableNumber;           // Numer stolika (jeśli na miejscu)
    string deliveryAddress;    // Adres dostawy (jeśli dostawa)
    int deliveryHour;          // Preferowana godzina dostawy
};

// =====================================================
// KROK 2: Deklaracje funkcji
// =====================================================

// Funkcja do wyświetlania danych restauracji
void displayRestaurantInfo(const Restaurant& restaurant);

// Funkcja do zbierania danych klienta (krok 1 - osoba 1)
void getCustomerInfo(Customer& customer, const Restaurant& restaurant);

// Funkcja pomocnicza do sprawdzenia czy godzina jest w zakresie działania
bool isValidHour(int hour, const Restaurant& restaurant);

// Funkcja do wyświetlenia menu (będzie rozwinięta w dalszych krokach)
void displayMenu();

// =====================================================
// KROK 3: Główna funkcja programu
// =====================================================

int main() {
    // Ustawienie restauracji - dane na sztywno (hardcoded)
    Restaurant myRestaurant;
    myRestaurant.name = "Taverna Pod Dębem";
    myRestaurant.address = "ul. Kwiatowa";
    myRestaurant.owner = "Jan Kowalski";
    myRestaurant.openingHour = 10;    // Otwarte od 10:00
    myRestaurant.closingHour = 23;    // Zamknięte o 23:00

    // Utworzenie obiektu klienta
    Customer customer;

    // Wyświetlenie danych restauracji
    cout << "===============================================" << endl;
    cout << "        WITAJ W SYSTEMIE ZAMÓWIANIA DAŃ        " << endl;
    cout << "===============================================" << endl;
    cout << endl;

    // OSOBA 1 - Wyświetlanie danych restauracji
    displayRestaurantInfo(myRestaurant);
    cout << endl;

    // OSOBA 1 - Zbieranie danych klienta
    getCustomerInfo(customer, myRestaurant);
    cout << endl;

    // OSOBA 2 - Menu (placeholder na razie)
    cout << "KROK 2: Wybierz swoje dania" << endl;
    displayMenu();
    cout << endl;

    // OSOBA 3 - Podsumowanie
    cout << "===============================================" << endl;
    cout << "            PODSUMOWANIE ZAMÓWIENIA           " << endl;
    cout << "===============================================" << endl;
    cout << "To będzie zrobione w kolejnym etapie" << endl;
    cout << endl;

    return 0;  // Program kończy się (zwraca 0 = brak błędów)
}

// =====================================================
// KROK 4: Implementacje funkcji
// =====================================================

// Wyświetla informacje o restauracji
void displayRestaurantInfo(const Restaurant& restaurant) {
    cout << "--- DANE RESTAURACJI ---" << endl;
    cout << "Nazwa: " << restaurant.name << endl;
    cout << "Adres: " << restaurant.address << endl;
    cout << "Właściciel: " << restaurant.owner << endl;
    cout << "Godziny otwarcia: " << restaurant.openingHour << ":00 - "
         << restaurant.closingHour << ":00" << endl;
}

// Zbiera dane od klienta
void getCustomerInfo(Customer& customer, const Restaurant& restaurant) {
    cout << "--- PODAJ SWOJE DANE ---" << endl;

    // Krok 1: Imię klienta
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
                     << restaurant.openingHour << "-"
                     << restaurant.closingHour << "): ";
                cin >> customer.deliveryHour;
                cout << endl;

                // Sprawdzenie czy godzina jest w zakresie
                if (isValidHour(customer.deliveryHour, restaurant)) {
                    validHour = true;
                    cout << "✓ Dostawa o godzinie " << customer.deliveryHour << ":00" << endl;
                } else {
                    cout << "✗ Godzina musi być między " << restaurant.openingHour
                         << " a " << restaurant.closingHour << "!" << endl;
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
bool isValidHour(int hour, const Restaurant& restaurant) {
    return (hour >= restaurant.openingHour && hour <= restaurant.closingHour);
}

// Wyświetla menu (na razie tylko placeholder)
void displayMenu() {
    cout << "--- DOSTĘPNE DANIA ---" << endl;
    cout << "1. Pizza Margherita - 25 PLN" << endl;
    cout << "2. Pasta Carbonara - 30 PLN" << endl;
    cout << "3. Stek wołowy - 50 PLN" << endl;
    cout << "4. Sałatka Cezara - 20 PLN" << endl;
    cout << "(system menu będzie zrobiony w następnym etapie)" << endl;
}




