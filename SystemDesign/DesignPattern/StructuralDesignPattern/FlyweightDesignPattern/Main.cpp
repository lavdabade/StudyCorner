#include<iostream>
#include<map>

using namespace std;

class Circle {
    private:
        string color;
    public:
        Circle(string color) {
            this->color = color;
        }
        void drawCircle(int x, int y, int r) {
            cout << "Drawing Circle with x: " << x << " y: " << y << " r: " << r << endl;
        }
};

class CircleFactory {
    private:
        map<string, Circle*> mp;
    public:
        Circle* getCircle(string color) {
            if(mp.find(color)==mp.end()) {
                cout << "Creating new circle obj for color " << color << endl;
                mp[color] = new Circle(color);
            }
            return mp[color];
        }
        ~CircleFactory() {
            for(auto it: mp) {
                delete it.second;
            }
        }
};

int main() {
    CircleFactory* circleFactory = new CircleFactory();
    Circle* redCircle1 = circleFactory->getCircle("RED");
    Circle* redCircle2 = circleFactory->getCircle("RED");
    Circle* redCircle3 = circleFactory->getCircle("RED");
    Circle* blueCircle1 = circleFactory->getCircle("BLUE");
    Circle* blueCircle2 = circleFactory->getCircle("BLUE");
    Circle* yellowCircle1 = circleFactory->getCircle("YELLOW");
    
    redCircle1->drawCircle(1,1,1);
    redCircle2->drawCircle(2,2,2);
    redCircle3->drawCircle(3,3,3);
    blueCircle1->drawCircle(1,1,1);
    blueCircle2->drawCircle(2,2,2);
    yellowCircle1->drawCircle(1,1,1);

    // Added destructor in CircleFactory as each color have single instance so 
    // for variables having same color try to delete multiple times
    
    // delete yellowCircle1;
    // delete blueCircle2;
    // delete blueCircle1;
    // delete redCircle3;
    // delete redCircle2;
    // delete redCircle1;

    delete circleFactory;

    return 0;
}