#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

class Car {
public:
    string make;
    string model;
    int year;
    string licensePlate;
    Car() {};
    Car(string licensePlate,string make, string model, int year) {
        this->make = make;
        this->licensePlate = licensePlate;
        this->model = model;
        this->year = year;
    }
};


class Node {
public:
    Car* car;
    Node* next;

    Node(Car* car) {
        this->car = car;
        next = nullptr;
    }
};

// LinkedList class represents the linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current->car;
            delete current;
            current = next;
        }
    }

    // Add a car to the linked list
    void addCar(Car* car) {
        Node* newNode = new Node(car);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Read car data from a file and populate the linked list
    void readDataFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string make, model, licensePlate;
        int year;

        while (inputFile >> licensePlate >> make >> model >> year) {
            Car* car = new Car(licensePlate,make, model, year);
            addCar(car);
        }

        inputFile.close();
    }

    // Write car data from the linked list to a file
    void writeDataToFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            outputFile << current->car->licensePlate << " " << current->car->make << " "
                << current->car->model << " "
                << current->car->year << endl;
            current = current->next;
        }

        outputFile.close();
    }

    // Display car data in the linked list
    void displayCars() {
        Node* current = head;
        while (current != nullptr) {
            cout << "\t \t \t \t  " << "LP: " << current->car->licensePlate <<
                ", Make: " << current->car->make << ", Model: " << current->car->model
                   << ", Year: " << current->car->year << endl;
            current = current->next;
        }
    }
    int searchModel(string value) {
        int counter = 0;
        Node* current = head;

        while (current != nullptr) {
            if (current->car->model == value) {
                cout << "\t\t\t" << current->car->licensePlate << " " << current->car->make << " " << current->car->model << " " << current->car->year << endl;
                counter++;
            }
            current = current->next;
            
        } 
        if (counter < 0)
        {
            
            return 0;
        }
        else if (counter > 0)
        { 
            
            return 1;
        }
        }
    int searchMake(string value) {
        int counter = 0;
        Node* current = head;

        while (current != nullptr) {
            if (current->car->make == value) {
                cout << "\t\t\t" << current->car->licensePlate << " " << current->car->make << " " << current->car->model << " " << current->car->year << endl;
                counter++;
            }
            current = current->next;

        }
        if (counter < 0)
        {

            return 0;
        }
        else if (counter > 0)
        {

            return 1;
        }
    }
    int searchDate(int value) {
        int counter = 0;
        Node* current = head;

        while (current != nullptr) {
            if (current->car->year == value) {
                cout << "\t\t\t" << current->car->licensePlate << " " << current->car->make << " " << current->car->model << " " << current->car->year << endl;
                counter++;
            }
            current = current->next;

        }
        if (counter < 0)
        {

            return 0;
        }
        else if (counter > 0)
        {

            return 1;
        }
    }

};

void saveCarsToFile(const unordered_map<string, Car>& cars, const string& filename) {
    ofstream file(filename);
    for (const auto& pair : cars) {
        const string& licensePlate = pair.first;
        const Car& car = pair.second;
        file << car.licensePlate << " " << car.make << " " << car.model << " " << car.year << endl;
    }
    file.close();
}

unordered_map<string, Car> loadCarsFromFile(const string& filename) {
    unordered_map<string, Car> cars;
    ifstream file(filename);
    string licensePlate, make, model;
    int year;
    while (file >> licensePlate >> make >> model >> year) {
        cars[licensePlate] = { licensePlate, make, model, year };
    }
    file.close();
    return cars;
}

void rentCar(unordered_map<string, Car>& cars, unordered_map<string, Car>& rentedCars, const string& licensePlate) {
    if (cars.find(licensePlate) != cars.end()) {
        Car car = cars[licensePlate];
        cars.erase(licensePlate);
        rentedCars[licensePlate] = car;
    }
}

void returnCar(unordered_map<string, Car>& cars, unordered_map<string, Car>& rentedCars, const string& licensePlate) {
    if (rentedCars.find(licensePlate) != rentedCars.end()) {
        Car car = rentedCars[licensePlate];
        rentedCars.erase(licensePlate);
        cars[licensePlate] = car;
    }
}

int main() {
    int x;
    string Lplate;
    string model;
    do {
        cout << endl << "\t \t \t \t \t \t" << "Welcome To Our ShowRoom" << "\n \n \n \n";


        // Load available and rented cars from files
        unordered_map<string, Car> cars = loadCarsFromFile("available_cars.txt");
        unordered_map<string, Car> rentedCars = loadCarsFromFile("rented_cars.txt");
        cout << "\t\t\t\t\tChoose 1 for seeing all the available Cars"
            << "\n \t\t\t\t\t" << "Choose 2 for seeing all the rented Cars"
            << "\n \t\t\t\t\t" << "Choose 3 for renting a Car"
            << "\n \t\t\t\t\t" << "Choose 4 for returning a Car"
            << "\n \t\t\t\t\t" << "Choose 5 for adding a Car"
            << "\n \t\t\t\t\t" << "Choose 6 for Deleting a Car"
            << "\n \t\t\t\t\t" << "Choose 7 for Searching a Model"
            << "\n \t\t\t\t\t" << "Choose 0 for Exiting the Program" << "\n";
            


        cin >> x;

        if (x == 1)
        {
            // to see available cars
            LinkedList carList;
            string filename = "available_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Available Cars:" << endl;
            carList.displayCars();
        }
        else if (x == 2)
        {
            // to see rented cars
            LinkedList carList;
            string filename = "rented_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Rented Cars:" << endl;
            carList.displayCars();
        }
        else if (x == 3)
        {
            // Rent a car
            LinkedList carList;
            string filename = "available_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Available Cars:" << endl;
            carList.displayCars();
            cout << "insert license plate of the car you want to rent: ";
            cin >> Lplate;
            rentCar(cars, rentedCars, Lplate);
            saveCarsToFile(cars, "available_cars.txt");
            saveCarsToFile(rentedCars, "rented_cars.txt");
        }
        else if (x == 4)
        {
            // return a car
            LinkedList carList;
            string filename = "rented_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Rented Cars:" << endl;
            carList.displayCars();
            cout << "insert license plate: ";
            cin >> Lplate;
            // Return a car
            returnCar(cars, rentedCars, Lplate);
            saveCarsToFile(cars, "available_cars.txt");
            saveCarsToFile(rentedCars, "rented_cars.txt");
        }
        else if (x == 5)
        {
            // add a car
            string make;
            string model;
            int date;
            LinkedList carList;
            string filename = "available_cars.txt";

            // Read car data from the file
            carList.readDataFromFile(filename);

            // Display car data
            cout << "Car Rental Management System" << endl;
            cout << "-----------------------------" << endl;
            cout << "Available Cars:" << endl;
            carList.displayCars();
            cout << "Please enter the Car LP, Make, Model, Year: ";
            // Add a new car to the list
            cin >> Lplate >> make >> model >> date;
            Car* newCar = new Car(Lplate,make, model, date);
            carList.addCar(newCar);

            // Write the updated car data back to the file
            carList.writeDataToFile(filename);
        }
        else if (x == 6)
        {
            // delete a car 
            LinkedList carList;
            string filename = "available_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Available Cars:" << endl;
            carList.displayCars();
            cout << "insert license plate: ";
            cin >> Lplate;
                cars.erase(Lplate);
                saveCarsToFile(cars, "available_cars.txt");
                saveCarsToFile(rentedCars, "rented_cars.txt");
        }
        else if (x == 7)
        {
            // to search
            int condition;
            cout << "what Parameter do you want to search with? \n1. Brand \n2. Model \n3. Date \n";
            cin >> condition;
            if (condition == 2)
            {
                string cond;
                LinkedList carList;
                string filename = "available_cars.txt";
                carList.readDataFromFile(filename);
                cout << "Available Cars:" << endl;
                carList.displayCars();
                cout << "Enter the Model you want to search for: ";
                cin >> model;

                if (carList.searchModel(model) == 1)
                {
                    cout << "Do You Want to Rent this Car? Yes/No" << endl;
                    cin >> cond;
                    if (cond == "Yes")
                    {
                        cout << "Please write the respective LP: ";
                        cin >> Lplate;

                        rentCar(cars, rentedCars, Lplate);
                        saveCarsToFile(cars, "available_cars.txt");
                        saveCarsToFile(rentedCars, "rented_cars.txt");
                    }
                }
                else
                {
                    cout << "Car Not Found!";
                }
            }
            else if (condition == 1)
            {
                string brand;
                string cond;
                LinkedList carList;
                string filename = "available_cars.txt";
                carList.readDataFromFile(filename);
                cout << "Available Cars:" << endl;
                carList.displayCars();
                cout << "Enter the Brand you want to search for: ";
                cin >> brand;

                if (carList.searchMake(brand) == 1)
                {
                    cout << "Do You Want to Rent this Car? Yes/No" << endl;
                    cin >> cond;
                    if (cond == "Yes")
                    {
                        cout << "Please write the respective LP: ";
                        cin >> Lplate;

                        rentCar(cars, rentedCars, Lplate);
                        saveCarsToFile(cars, "available_cars.txt");
                        saveCarsToFile(rentedCars, "rented_cars.txt");
                    }
                }
                else
                {
                    cout << "Car Not Found!";
                }
            }
            else if (condition == 3)
            {
                int date;
                string cond;
                LinkedList carList;
                string filename = "available_cars.txt";
                carList.readDataFromFile(filename);
                cout << "Available Cars:" << endl;
                carList.displayCars();
                cout << "Enter the Brand you want to search for: ";
                cin >> date;

                if (carList.searchDate(date) == 1)
                {
                    cout << "Do You Want to Rent this Car? Yes/No" << endl;
                    cin >> cond;
                    if (cond == "Yes")
                    {
                        cout << "Please write the respective LP: ";
                        cin >> Lplate;

                        rentCar(cars, rentedCars, Lplate);
                        saveCarsToFile(cars, "available_cars.txt");
                        saveCarsToFile(rentedCars, "rented_cars.txt");
                    }
                }
                else
                {
                    cout << "Car Not Found!";
                }
            }
        }
        else if (x == 0)
        {
            //exiting the program
            cout << "\t\t\t\t\t\t\tTHANK YOU!";
        }
        else
        {
            cout << "\t\t\t\t\t\t\tERROR!";
        }
    } while (x != 0);
    // Save available and rented cars to files
    

    
}
