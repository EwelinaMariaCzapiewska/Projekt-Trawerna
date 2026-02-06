
#include <iostream>
#include "Customer.h"
#include "Restaurant.h"
#include "OrderManager.h"

using namespace std;

int main() {

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
    cout << endl;
    displayMenu();
    cout << endl;

    takeOrder(customer);

    cout << "===============================================" << endl;
    cout << "            PODSUMOWANIE ZAMÓWIENIA           " << endl;
    cout << "===============================================" << endl;
    cout << endl;
    displaySummary(customer);
    saveOrderToFile(customer);

    return 0;
}