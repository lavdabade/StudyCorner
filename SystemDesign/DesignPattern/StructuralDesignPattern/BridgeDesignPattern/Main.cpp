#include<iostream>

using namespace std;

class Color {
    public:
        virtual void applyColor() = 0;
        virtual ~Color() {}
};

class RedColor : public Color{
    public:
        void applyColor() {
            cout << "in Red color." << endl;
        }
};

class BlueColor : public Color {
    public:
        void applyColor() {
            cout << "in Blue color" << endl;
        }
};

class YellowColor : public Color {
    public:
        void applyColor() {
            cout << "in Yellow color" << endl;
        }
};

class Shape {
    protected:
        Color* color;
    public:
        virtual void drawShape() = 0;
        virtual ~Shape() {}
};

class Circle : public Shape {
    public:
        Circle(Color* c) {
            color=c;
        }
        void drawShape() {
            cout << "Drawing Circle ";
            color->applyColor();
        }
};

class Square : public Shape {
    public:
        Square(Color* c) {
            color=c;
        }
        void drawShape() {
            cout << "Drawing Square ";
            color->applyColor();
        }
};

class Triangle : public Shape {
    public:
        Triangle(Color* c) {
            color=c;
        }
        void drawShape() {
            cout << "Drawing Triangle ";
            color->applyColor();
        }
};

int main() {
    Shape* blueTriangle = new Triangle(new BlueColor());
    blueTriangle->drawShape();
    Shape* redSquare = new Square(new RedColor());
    redSquare->drawShape();
    Shape* yellowCircle = new Circle(new YellowColor());
    yellowCircle->drawShape();
    delete blueTriangle;
    delete redSquare;
    delete yellowCircle;
    return 0;
}