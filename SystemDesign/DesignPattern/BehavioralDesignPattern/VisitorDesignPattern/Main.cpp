#include<iostream>

using namespace std;

class Shape {
    public:
        virtual void accept(Visitor* visitor) = 0;
        virtual ~Shape() {}
};

class Rectangle : public Shape {
    private:
        int width;
        int height;
    public:
        Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
        }
        int getHeight() {
            return height;
        }
        int getWidth() {
            return width;
        }
        void accept(Visitor* visitor);
};

class Square : public Shape {
    private:
        int length;
    public:
        Square(int length) {
            this->length = length;
        }
        int getLength() {
            return length;
        }
        void accept(Visitor* visitor);
};

class Circle : public Shape {
    private:
        int radius;
    public:
        Circle(int radius) {
            this->radius = radius;
        }
        int getRadius() {
            return radius;
        }
        void accept(Visitor* visitor);
};

class Visitor {
    public:
        virtual void visit(Rectangle* rectangle) = 0;
        virtual void visit(Square* square) = 0;
        virtual void visit(Circle* circle) = 0;
        virtual ~Visitor() {}
};

void Rectangle::accept(Visitor* visitor) {
    visitor->visit(this);
}

void Square::accept(Visitor* visitor) {
    visitor->visit(this);
}

void Circle::accept(Visitor* visitor) {
    visitor->visit(this);
}

class Area : public Visitor {
    public:
        void visit(Rectangle* rectangle) {
            cout << "Area for Rectangle is " << rectangle->getWidth() * rectangle->getHeight() << endl;
        }
        void visit(Square* square) {
            cout << "Area of Square is " << square->getLength() * square->getLength() << endl;
        }
        void visit(Circle* circle) {
            cout << "Area of circle is " << (circle->getRadius())*(circle->getRadius())*(3.14) << endl;
        }
};

class Perimeter : public Visitor {
    public:
        void visit(Rectangle* rectangle) {
            cout << "Perimeter for Rectangle is " << 2 * (rectangle->getWidth() + rectangle->getHeight()) << endl;
        }
        void visit(Square* square) {
            cout << "Perimeter of Square is " << square->getLength()*4 << endl;
        }
        void visit(Circle* circle) {
            cout << "Perimeter of circle is " << 2*(circle->getRadius())*(3.14) << endl;
        }
};

int main() {
    Shape* rectangle = new Rectangle(2, 3);
    Shape* square = new Square(5);
    Shape* circle = new Circle(4);

    Visitor* areaVisitor = new Area();
    rectangle->accept(areaVisitor);
    square->accept(areaVisitor);
    circle->accept(areaVisitor);

    Visitor* perimeterVisitor = new Perimeter();
    rectangle->accept(perimeterVisitor);
    square->accept(perimeterVisitor);
    circle->accept(perimeterVisitor);

    delete rectangle;
    delete square;
    delete circle;
    delete areaVisitor;
    delete perimeterVisitor;

    return 0;
}