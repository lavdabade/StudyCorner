#include<iostream>

using namespace std;

class Car {
    public:
        virtual void getCarDetails() = 0;
        virtual ~Car() {}
};

class MarutiCar : public Car {
    public:
        void getCarDetails() {
            cout << "Maruti Car" << endl;
        }
};

class TataCar : public Car {
    public:
        void getCarDetails() {
            cout << "Tata Car" << endl;
        }
};

class CarFactory {
    public:
        Car* createCar(string companyName) {
            if(companyName == "TATA") return new TataCar();
            if(companyName == "MARUTI") return new MarutiCar();
            return NULL;
        }
};

int main() {
    CarFactory* carFactory = new CarFactory();
    string companyName;
    cout << "Enter company name: ";
    cin >> companyName;
    cout << endl;
    Car* car = carFactory->createCar(companyName);
    if(car) car->getCarDetails();
    else cout << companyName + " car is not available...";
    return 0;
}