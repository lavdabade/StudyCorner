#include<iostream>

using namespace std;

class Coffee {
    public:
        virtual int getPrice() = 0;
        virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
    public:
        int getPrice() {
            return 30;
        }
};

class CoffeeDecorator : public Coffee {
    protected:
        Coffee* coffee;

    public:
        virtual int getPrice() = 0;
        virtual ~CoffeeDecorator() {}
};

class SugarCoffee : public CoffeeDecorator {
    public:
        SugarCoffee(Coffee* c) {
            coffee = c;
        }
        int getPrice() {
            return coffee->getPrice() + 10;
        }
};

class MilkCoffee : public CoffeeDecorator {
    public:
        MilkCoffee(Coffee* c) {
            coffee = c;
        }
        int getPrice() {
            return coffee->getPrice() + 20;
        }
};

int main() {
    Coffee* simpleCoffee = new SimpleCoffee();
    cout << "SimpleCoffee Price: " << simpleCoffee->getPrice() << endl;
    Coffee* milkCoffee = new MilkCoffee(new SimpleCoffee());
    cout << "MilkCoffee Price: " << milkCoffee->getPrice() << endl;
    Coffee* sugarCoffee = new SugarCoffee(new SimpleCoffee());
    cout << "SugerCoffee Price: " << sugarCoffee->getPrice() << endl;
    Coffee* milkSugarCoffee = new MilkCoffee(new SugarCoffee(new SimpleCoffee));
    cout << "MilkSugatCoffee Price: " << milkSugarCoffee->getPrice() << endl;
    delete simpleCoffee;
    delete milkCoffee;
    delete sugarCoffee;
    delete milkSugarCoffee;
    return 0;
}