#include<iostream>

using namespace std;

class Button {
    public:
        virtual void onClick() = 0;
};

class MacButton : public Button{
    public:
        void onClick() {
            cout << "Clicked Mac Button" << endl;
        }
};

class WindowsButton : public Button{
    public:
        void onClick() {
            cout << "Clicked Windows Button" << endl;
        }
};

class GUIFactory {
    public:
        virtual Button* createButton() = 0;
};

class WindowsFactory : public GUIFactory {
    public:
        Button* createButton() {
            return new WindowsButton();
        }
};

class MacFactory : public GUIFactory{
    public:
        Button* createButton() {
            return new MacButton();
        }
};

int main() {
    GUIFactory* factory = NULL;
    string os ;
    cout << "Enter OS name: ";
    cin >> os;
    cout << endl;
    if(os == "MAC") {
        factory = new MacFactory();
    }
    else if(os == "WINDOWS") {
        factory = new WindowsFactory();
    }
    else {
        cout << "Unable to get Factory for OS: " << os << endl;
    }
    if(factory) {
        Button* button = factory->createButton();
        button->onClick();
    }
    return 0;
}