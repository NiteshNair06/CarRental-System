#include <iostream>
#include "CarRentalSystem.h"
using namespace std;

int main() {
    CarRentalSystem system;
    system.addSampleCars();

    int choice;
    do {
        cout << "\n===== Car Rental Management System =====\n";
        cout << "1. View Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Admin Mode\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.showAvailableCars(); break;
            case 2: system.rentCar(); break;
            case 3: system.returnCar(); break;
            case 4: system.adminLogin(); break;
            case 5: cout << "Thank you! Visit again.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
