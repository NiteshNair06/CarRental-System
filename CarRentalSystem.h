#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H
#include <vector>
#include <fstream>
#include "Car.h"
#include "ElectricCar.h"
#include "SUV.h"

class CarRentalSystem {
    vector<Car*> cars;
    double totalEarnings = 0;

public:
    void addSampleCars() {
        cars.push_back(new Car("C101", "Maruti", "Swift", 1500));
        cars.push_back(new SUV("C102", "Toyota", "Fortuner", 3000));
        cars.push_back(new ElectricCar("C103", "Tata", "NexonEV", 2000));
    }

    void showAvailableCars();
    void rentCar();
    void returnCar();
    void adminLogin();

    void addCar();
    void removeCar();
    void viewAllCars();
    void rentalSummary();
    void saveToFile();

    ~CarRentalSystem() {
        for (auto c : cars) delete c;
    }
};

// ---------------- Implementations ----------------
void CarRentalSystem::showAvailableCars() {
    cout << "\n--- Available Cars ---\n";
    bool found = false;
    for (auto c : cars)
        if (c->isAvailable()) {
            cout << c->getInfo() << endl;
            found = true;
        }
    if (!found) cout << "No cars available.\n";
}

void CarRentalSystem::rentCar() {
    string id; int days;
    cout << "\nEnter Car ID to rent: "; cin >> id;
    cout << "Enter number of days: "; cin >> days;
    for (auto c : cars) {
        if (c->getId() == id && c->isAvailable()) {
            double cost = c->calculatePrice(days);
            c->rent();
            totalEarnings += cost;
            cout << "Car rented successfully!\nTotal Cost: " << cost << endl;
            saveToFile();
            return;
        }
    }
    cout << "Car not available or invalid ID.\n";
}

void CarRentalSystem::returnCar() {
    string id;
    cout << "\nEnter Car ID to return: "; cin >> id;
    for (auto c : cars) {
        if (c->getId() == id && !c->isAvailable()) {
            c->makeAvailable();
            cout << "Car returned successfully!\n";
            saveToFile();
            return;
        }
    }
    cout << "Invalid Car ID or car not rented.\n";
}

void CarRentalSystem::adminLogin() {
    string pass;
    cout << "\nEnter admin password: ";
    cin >> pass;
    if (pass != "admin123") {
        cout << "Incorrect password!\n";
        return;
    }
    int ch;
    do {
        cout << "\n--- Admin Panel ---\n";
        cout << "1. Add Car\n2. Remove Car\n3. View All Cars\n4. View Rental Summary\n5. Back\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: addCar(); break;
            case 2: removeCar(); break;
            case 3: viewAllCars(); break;
            case 4: rentalSummary(); break;
            case 5: break;
            default: cout << "Invalid option.\n";
        }
    } while (ch != 5);
}

void CarRentalSystem::addCar() {
    string id, brand, model, type;
    double price;
    cout << "\nEnter Car ID: "; cin >> id;
    cout << "Enter Brand: "; cin >> brand;
    cout << "Enter Model: "; cin >> model;
    cout << "Enter Price/Day: "; cin >> price;
    cout << "Enter Type (Standard/Electric/SUV): "; cin >> type;

    if (type == "Electric")
        cars.push_back(new ElectricCar(id, brand, model, price));
    else if (type == "SUV")
        cars.push_back(new SUV(id, brand, model, price));
    else
        cars.push_back(new Car(id, brand, model, price));

    cout << "Car added successfully\n" << endl;
    saveToFile();
}

void CarRentalSystem::removeCar() {
    string id;
    cout << "\nEnter Car ID to remove: "; cin >> id;
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            cars.erase(it);
            cout << "Car removed successfully/n";
            saveToFile();
            return;
        }
    }
    cout << "Car ID not found\n" << endl;
}

void CarRentalSystem::viewAllCars() {
    cout << "\n--- All Cars ---\n";
    for (auto c : cars)
        cout << c->getInfo() << (c->isAvailable() ? " | Available" : " | Rented") << endl;
}

void CarRentalSystem::rentalSummary() {
    cout << "\n--- Rental Summary ---\n";
    for (auto c : cars)
        if (!c->isAvailable())
            cout << c->getInfo() << " | Currently Rented\n";
    cout << "\nTotal Earnings: " << totalEarnings << endl;
}

void CarRentalSystem::saveToFile() {
    ofstream ofs("../data/cars.txt");
    for (auto c : cars)
        ofs << *c;
    ofs.close();
}
#endif
