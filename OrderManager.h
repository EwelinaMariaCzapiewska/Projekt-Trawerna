
#ifndef SYSTEM_RESTAURACJI_ORDERMANAGER_H
#define SYSTEM_RESTAURACJI_ORDERMANAGER_H

#include "Customer.h"

void getCustomerInfo(Customer& customer);
void displayMenu();
void takeOrder(Customer& customer);
void displaySummary(const Customer& customer);

#endif //SYSTEM_RESTAURACJI_ORDERMANAGER_H