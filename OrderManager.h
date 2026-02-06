
#ifndef SYSTEM_RESTAURACJI_ORDERMANAGER_H
#define SYSTEM_RESTAURACJI_ORDERMANAGER_H

#include "Customer.h"

void getCustomerInfo(Customer& customer);
void displayMenu();
void takeOrder(Customer& customer);
void displaySummary(Customer& customer);
bool confirmOrder(Customer& c);
void saveOrderToFile(Customer& c);

#endif //SYSTEM_RESTAURACJI_ORDERMANAGER_H