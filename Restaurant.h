
#ifndef SYSTEM_RESTAURACJI_RESTAURANT_H
#define SYSTEM_RESTAURACJI_RESTAURANT_H

#include <string>

struct MenuItem {
    std::string name;
    int price;
    std::string ingredients;
};

extern std::string restauracja_nazwa;
extern std::string restauracja_adres;
extern std::string restauracja_owner;
extern int restauracja_start;
extern int restauracja_koniec;

void displayRestaurantInfo();
bool isValidHour(int hour);

#endif //SYSTEM_RESTAURACJI_RESTAURANT_H