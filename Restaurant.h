
#ifndef SYSTEM_RESTAURACJI_RESTAURANT_H
#define SYSTEM_RESTAURACJI_RESTAURANT_H

#include <string>

struct MenuItem {
    std::string name;
    int price;
    std::string ingredients;
};

struct Restaurant {
    std::string name;
    std::string address;
    std::string owner;
    int startHour;
    int endHour;
};

extern Restaurant restauracja;

void displayRestaurantInfo();
bool isValidHour(int hour);

#endif //SYSTEM_RESTAURACJI_RESTAURANT_H