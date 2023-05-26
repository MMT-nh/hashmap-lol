#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

// Car class represents a car with its details
class Car {
public:
    string make;
    string model;
    int year;

    Car(string make, string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
    }
};

// Node class represents a node in the linked list
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

        string make, model;
        int year;

        while (inputFile >> make >> model >> year) {
            Car* car = new Car(make, model, year);
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
            outputFile << current->car->make << " "
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
            cout << "Make: " << current->car->make << ", Model: " << current->car->model
                << ", Year: " << current->car->year << endl;
            current = current->next;
        }
    }
};

int main() {
    string make;
    string model;
    int date;
    LinkedList carList;
    string filename = "available_cars.txt";
    carList.readDataFromFile(filename);
}
