#include<iostream>

using namespace std;

class Country {
    private:
        string name;
        string code;
    public:
        Country(string name, string code) {
            this->name = name;
            this->code = code;
        }
        Country(Country &other) {
            name = other.name;
            code = other.code;
        }
        string toString() {
            return " Country Name: " + name + ", Country Code: " + code + ".";
        }
};

class Address {
    private:
        string city;
        Country* country;
    public:
        Address(string city, Country* country) {
            this->city = city;
            this->country = country;
        }
        Address(Address &other) {
            city = other.city;
            country = new Country(*other.country);
        }
        string toString() {
            return " City: " + city + ", " + country->toString();
        }
};

class Employee {
    private:
        string name;
        Address* address;
    public:
        Employee(string n, Address* a) : name(n), address(new Address(*a)) {};
        Employee(Employee &other) {
            name = other.name;
            address = new Address(*other.address);
        }
        Employee* clone() {
            return new Employee(*this);
        }
        string toString() {
            return "Employee Name: " + name + ", " + address->toString();
        }
        void setName(string name) {
            this->name = name;
        }
};

int main() {
    Employee* e1 = new Employee("Lav", new Address("Mumbai", new Country("India", "IN")));
    Employee* e2 = e1->clone();
    e2->setName("Kush");
    cout << e1->toString() << endl;
    cout << e2->toString() << endl;
    return 0;
}