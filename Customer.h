
#ifndef PROJEKT_TRAWERNA_CUSTOMER_H
#define PROJEKT_TRAWERNA_CUSTOMER_H

#include <string>
#include <vector>
#include "Restaurant.h"

struct Customer {
    std::string name;
    bool isDelivery;
    int tableNumber;
    std::string deliveryAddress;
    int deliveryHour;
    std::vector<MenuItem> order;
};

#endif