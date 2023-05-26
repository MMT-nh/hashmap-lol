#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <list>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;
void toppan() {
    cout << "\t  | " << endl;
    cout << "\t  |  Plate Number\tBrand\t\tModel\t     Colour   Rate Per 24 Hour   Transmission" << endl;
    cout << "\t  |  ======================================================================================================" << endl;
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void mainmenu();
struct User{
    string username;
    string password;
};
void log()
{
    
    system("cls");
    int timer = 5 + rand() % 20;
    int row, col, r, c, q;
    gotoxy(55, 18);
    cout << "loging in...";
    gotoxy(45, 20);
    for (r = 1; r <= timer; r++)
    {
        for (q = 0; q <= 100000000; q++);//to display the character slowly
        printf("%c", 177);
    }
    Sleep(100);
    system("cls");
}
void pas() {
    char ch;
    cout << "\t  |";
    system("pause");

    ch = getchar();
        if (ch == '\n') {
        std::cout << "Continuing...";
    }
}

void art()
{



    
    ifstream ifs("art.txt");
    string Lines = "";

    if (ifs)
    {
        while (ifs.good())
        {
            string TempLine;
            getline(ifs, TempLine);
            TempLine += "\n";

            Lines += TempLine;
        }

        cout << Lines;

    }

    ifs.close();
}

void register_user() {
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    ofstream outfile("users.txt", ios::app);
    outfile << user.username << " " << user.password << endl;
    outfile.close();
}

bool login(User user) {


    ifstream infile("users.txt");
    string username, password;
    while (infile >> username >> password) {
        if (username == user.username && password == user.password) {
            return true;
        }




    }
    return false;
}
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

void welcome()
{


    ifstream ifs("welcome.txt");
    string Lines = "";

    if (ifs)
    {
        while (ifs.good())
        {
            string TempLine;
            getline(ifs, TempLine);
            TempLine += "\n";

            Lines += TempLine;
        }

        cout << Lines;


    }
    cout << "\n\t  |\t\t\t\t\t\t\t";
    ifs.close();
    Sleep(1000);
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");

}

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
            cout<< "\t  |  "<< current->car->licensePlate << "\t\t"
                 << current->car->make<<"\t\t"<< current->car->model
                   << "\t\t" << current->car->year << endl;
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
void carsearch() {
    unordered_map<string, Car> cars = loadCarsFromFile("available_cars.txt");
    unordered_map<string, Car> rentedCars = loadCarsFromFile("rented_cars.txt");
    int condition;
    string model;
    string Lplate;
    cout << "\t  |what Parameter do you want to search with? \n\t  |1. Brand \n\t  |2. Model \n\t  |3. Date \n";
    cin >> condition;
    if (condition == 2)
    {
        string cond;
        LinkedList carList;
        string filename = "available_cars.txt";
        carList.readDataFromFile(filename);
        toppan();
        carList.displayCars();
        cout << "\t  |Enter the Model you want to search for: ";
        cin >> model;

        if (carList.searchModel(model) == 1)
        {
            cout << "\t  |Do You Want to Rent this Car? Yes/No" << endl;
            cin >> cond;
            if (cond == "Yes")
            {
                cout << "\t  |Please write the respective LP: ";
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
        toppan();
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
int admin(){
int x;
string Lplate;
string model;
do {
    system("cls");
    art();

    // Load available and rented cars from files
    unordered_map<string, Car> cars = loadCarsFromFile("available_cars.txt");
    unordered_map<string, Car> rentedCars = loadCarsFromFile("rented_cars.txt");
    cout << "\t  |";
    cout <<"\n\t  |\t\t\t\t\t\t"<<"1.for seeing all the available Cars"
        << "\n\t  |\t\t\t\t\t\t"<<"2.for seeing all the rented Cars"
        << "\n\t  |\t\t\t\t\t\t"<<"3.for renting a Car"
        <<" \n\t  |\t\t\t\t\t\t"<<"4.for returning a Car"
        << "\n\t  |\t\t\t\t\t\t"<<"5.for adding a Car"
        << "\n\t  |\t\t\t\t\t\t"<<"6.for Deleting a Car"
        << "\n\t  |\t\t\t\t\t\t"<<"7.for Searching for car"
        << "\n\t  |\t\t\t\t\t\t"<<"8. Exiting the Program" << "\n";


    cout << "\t  |\t\t\t\t\t\tEnter your choice:";
    cin >> x;

    if (x == 1)
    { 
        system("cls");
        art();
        // to see available cars
        LinkedList carList;
        string filename = "available_cars.txt";
        toppan();
        carList.readDataFromFile(filename);
        carList.displayCars();
        pas();
       

   

    }
    
    else if (x == 2)
    {
        system("cls");
        art();
        // to see rented cars
        LinkedList carList;
        string filename = "rented_cars.txt";
        carList.readDataFromFile(filename);
        toppan();
        carList.displayCars();
        pas();

    }
    else if (x == 3)
    {
        system("cls");
        art();
        // Rent a car
        LinkedList carList;
        string filename = "available_cars.txt";
        carList.readDataFromFile(filename);
        toppan();
        carList.displayCars();

        cout << "\t  |insert license plate of the car you want to rent: ";
        cin >> Lplate;
        rentCar(cars, rentedCars, Lplate);
        saveCarsToFile(cars, "available_cars.txt");
        saveCarsToFile(rentedCars, "rented_cars.txt");
    }
    else if (x == 4)
    {
        system("cls");
        art();
        // return a car
        LinkedList carList;
        string filename = "rented_cars.txt";
        carList.readDataFromFile(filename);
        toppan();
        carList.displayCars();
        cout << "\t  |insert license plate: ";
        cin >> Lplate;
        // Return a car
        returnCar(cars, rentedCars, Lplate);
        saveCarsToFile(cars, "available_cars.txt");
        saveCarsToFile(rentedCars, "rented_cars.txt");
    }
    else if (x == 5)
    {
        system("cls");
        art();
        // add a car
        string make;
        string model;
        int date;
        LinkedList carList;
        string filename = "available_cars.txt";

        // Read car data from the file
        carList.readDataFromFile(filename);

        // Display car data
        toppan();
        carList.displayCars();
        cout << "\t  |Please enter the Car LP, Make, Model, Year: ";
        // Add a new car to the list
        cin >> Lplate >> make >> model >> date;
        Car* newCar = new Car(Lplate, make, model, date);
        carList.addCar(newCar);

        // Write the updated car data back to the file
        carList.writeDataToFile(filename);
    }
    else if (x == 6)
    {
        system("cls");
        art();
        // delete a car 
        LinkedList carList;
        string filename = "available_cars.txt";
        carList.readDataFromFile(filename);
        cout << "\t  |Available Cars:" << endl;
        carList.displayCars();
        cout << "\t  |insert license plate: ";
        cin >> Lplate;
        cars.erase(Lplate);
        saveCarsToFile(cars, "available_cars.txt");
        saveCarsToFile(rentedCars, "rented_cars.txt");
    }
    else if (x == 7)
    {
       system("cls");
        art();
        carsearch();
    }
    else if (x == 8)
    {
    mainmenu();
    }
    else
    {
        cout << "\t\t\t\t\t\t\tERROR!";
    }
} while (x != 8); 


return 1;


}

int userfunc() {
    int x;
    string Lplate;
    string model;
    do {
      

        system("cls");
        art();
        // Load available and rented cars from files
        unordered_map<string, Car> cars = loadCarsFromFile("available_cars.txt");
        unordered_map<string, Car> rentedCars = loadCarsFromFile("rented_cars.txt");
        cout <<"\n\t  |\t\t\t\t\t\t" <<"1.for seaing available Cars"
            << "\n\t  |\t\t\t\t\t\t" << "2.for renting a Car"
            << "\n\t  |\t\t\t\t\t\t" << "3.for returning a Car"
            << "\n\t  |\t\t\t\t\t\t" << "4.for Searching a car"
            << "\n\t  |\t\t\t\t\t\t" << "5.Back" << "\n";
            


        cin >> x;

        if (x == 1)
        {    
            // to see available cars
            LinkedList carList;
            system("cls");
            art();
            toppan();
            string filename = "available_cars.txt";
            carList.readDataFromFile(filename);
            cout << "Available Cars:" << endl;
            carList.displayCars();
            pas();
      
        }
        
        else if (x == 2)
        {
            // Rent a car
            LinkedList carList;
            string filename = "available_cars.txt";
            carList.readDataFromFile(filename);
            toppan();
            carList.displayCars();
            cout << "\t  |insert license plate of the car you want to rent: ";
            cin >> Lplate;
            rentCar(cars, rentedCars, Lplate);
            saveCarsToFile(cars, "available_cars.txt");
            saveCarsToFile(rentedCars, "rented_cars.txt");
        }
        else if (x == 3)
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
            cout << "\t  |Please enter the Car LP, Make, Model, Year: ";
            // Add a new car to the list
            cin >> Lplate >> make >> model >> date;
            Car* newCar = new Car(Lplate,make, model, date);
            carList.addCar(newCar);

            // Write the updated car data back to the file
            carList.writeDataToFile(filename);
        }
        else if (x == 4)
        {
            system("cls");
            art();
            // to search
            carsearch();
        }
        else if (x == 5)
        {
        mainmenu();
        }
        else
        {
            cout << "\t\t\t\t\t\t\tERROR!";
        }
    } while (x != 5);
    
    return 0;

    
}

void  mainmenu() {
    
   
    int choice;
    User user;
    while (true) {
        system("cls");
        art();
        cout << "\t  |";
        cout << "\n\t  |\t\t\t\t\t\t\t  1.Login\n\t  |\t\t\t\t\t\t\t  2.Register\n\t  |\t\t\t\t\t\t\t  3.Exit";
        cout << "\n\t  |\n\t  |\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:

            cout << "\t  | Enter username: ";
            cin >> user.username;
            cout << "\t  | Enter password: ";
            cin >> user.password;
            if (login(user)) {
                log();
                userfunc();

            }
            else if (user.username == "admin" && user.password == "1") {
                
                log();
                admin();
            }


            else {
                system("cls");
                art();
                cout << "\t  |"<<endl;
                cout << "\t  |"<<endl;
                cout << "\t  |\t\tInvalid username or password!" << endl;
                pas();
            }

            break;

        case 2:
            register_user();
            break;

        case 3:
            exit(0);

        default:
            cout << "|\n\t|\t\t\t\t\t\t\t Invalid choice! " << endl;
        }
    }


}

int main() {
    welcome();
    mainmenu();
}





