#ifndef SUV_H
#define SUV_H
#include "Car.h"

class SUV : public Car {
public:
    SUV(string i="", string b="", string m="", double p=0.0, bool a=true)
        : Car(i, b, m, p, a) {}
    double calculatePrice(int days) override { return days * (pricePerDay + 200); }
    string getType() const override { return "SUV"; }
};
#endif
