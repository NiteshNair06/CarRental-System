# 🚗 Car Rental Management System (C++ OOP Project)

A **console-based Car Rental Management System** built in **C++**, demonstrating core **Object-Oriented Programming (OOP)** principles — Encapsulation, Inheritance, and Polymorphism — along with **file handling** for data persistence.

---

## 🧩 Features
- View available cars  
- Rent and return cars  
- Add new cars (Admin mode)  
- File persistence using `cars.txt`  
- Demonstrates classes, inheritance, and encapsulation  

---

## 🏗️ Project Structure

CarRentalSystem/
│
├── src/
│ ├── main.cpp # Entry point
│ ├── Car.h # Base Car class
│ ├── SUV.h # Derived SUV class
│ ├── ElectricCar.h # Derived ElectricCar class
│ └── CarRentalSystem.h # System logic
│
├── cars.txt # Stores car data
└── README.md # Project documentation


---

## ⚙️ How to Run

### 🪟 Windows (MinGW / g++)
```bash
g++ src/main.cpp -o car_rental.exe
.\car_rental.exe


🧠 Concepts Used

Encapsulation – Data members are private, accessed via public methods.

Inheritance – SUV and ElectricCar derive from Car.

Polymorphism – Overridden display methods for dynamic behavior.

File Handling – Data stored persistently in cars.txt.

===== Car Rental Management System =====
1. View Available Cars
2. Rent a Car
3. Return a Car
4. Admin Mode
5. Exit
Enter choice: 1


👨‍💻 Author

Nitesh Nair
📍 Computer Science Student | C++ & Python Developer
