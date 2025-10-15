#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H
#include "Car.h"

class ElectricCar : public Car {
public:
    ElectricCar(string i="", string b="", string m="", double p=0.0, bool a=true)
        : Car(i, b, m, p, a) {}
    double calculatePrice(int days) override { return days * (pricePerDay + 100); }
    string getType() const override { return "Electric"; }
};
#endif
