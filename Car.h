#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Car {
protected:
    string id, brand, model;
    double pricePerDay;
    bool available;
public:
    Car(string i="", string b="", string m="", double p=0.0, bool a=true)
        : id(i), brand(b), model(m), pricePerDay(p), available(a) {}

    virtual double calculatePrice(int days) { return days * pricePerDay; }
    virtual string getType() const { return "Standard"; }

    bool isAvailable() const { return available; }
    void rent() { available = false; }
    void makeAvailable() { available = true; }

    string getId() const { return id; }
    string getInfo() const {
        return id + " | " + brand + " " + model + " | " + getType() + " | " + to_string((int)pricePerDay) + "/day";
    }

    friend ofstream& operator<<(ofstream& ofs, const Car& c) {
        ofs << c.id << " " << c.brand << " " << c.model << " "
            << c.pricePerDay << " " << c.available << " " << c.getType() << endl;
        return ofs;
    }

    virtual ~Car() {}
};
#endif
