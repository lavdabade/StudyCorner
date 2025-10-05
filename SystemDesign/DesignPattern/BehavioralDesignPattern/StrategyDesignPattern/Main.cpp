#include<iostream>

using namespace std;

class Payment {
    public:
        virtual void pay() = 0;
};

class UPIPayment : public Payment {
    public:
        void pay() {
            cout << "Paying via UPI" << endl;
        }
};

class CashPayment : public Payment {
    public:
        void pay() {
            cout << "Paying via Cash" << endl;
        }
};

class CardPayment : public Payment {
    public:
        void pay() {
            cout << "Paying via Card" << endl;
        }
};

int main() {
    Payment* payment = NULL;
    string mode;
    cout << "Enter Payment Mode: ";
    cin >> mode;
    if(mode == "CASH") {
        payment = new CashPayment();
    }
    else if(mode == "UPI") {
        payment = new UPIPayment();
    }
    else if(mode == "CARD") {
        payment = new CardPayment();
    }
    else {
        cout << "Unable to get payment method for mode: " << mode << endl;
    }
    if(payment) {
        payment->pay();
    }
    return 0;
}