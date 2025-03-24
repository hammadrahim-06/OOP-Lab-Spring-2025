#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    protected:
    int x, y;
    string color;
    float borderThickness;

    public:
    Shape(int posX, int posY, string col, float border = 1.0) : x(posX), y(posY), color(col), borderThickness(border) {}

    virtual void draw() {
        cout << "Drawing a shape at (" << x << ", " << y << ") with color " << color << " and border thickness " << borderThickness << endl;
    }

    virtual float calculateArea() = 0;
    virtual float calculatePerimeter() = 0;
};

class Circle : public Shape {
    private:
    float radius;

    public:
    Circle(int centerX, int centerY, string col, float r, float border = 1.0) : Shape(centerX, centerY, col, border), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << color << endl;
    }

    float calculateArea() override {
        return M_PI * radius * radius;
    }

    float calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
    private:
    float width, height;

    public:
    Rectangle(int topLeftX, int topLeftY, string col, float w, float h, float border = 1.0) : Shape(topLeftX, topLeftY, col, border), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << " and color " << color << endl;
    }

    float calculateArea() override {
        return width * height;
    }

    float calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
    private:
    float sideA, sideB, sideC;

    public:
    Triangle(int posX, int posY, string col, float a, float b, float c, float border = 1.0) : Shape(posX, posY, col, border), sideA(a), sideB(b), sideC(c) {}

    void draw() override {
        cout << "Drawing a Triangle at (" << x << ", " << y << ") with sides " << sideA << ", " << sideB << ", " << sideC << " and color " << color << endl;
    }

    float calculateArea() override {
        float s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    float calculatePerimeter() override {
        return sideA + sideB + sideC;
    }
};

int main() {
    Circle circle(10, 15, "Red", 12);
    Rectangle rectangle(5, 8, "Blue", 18, 25);
    Triangle triangle(2, 3, "Green", 6, 9, 11);

    cout << "=== Shape Details ===\n";
    
    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Circle Perimeter: " << circle.calculatePerimeter() << endl;
    
    cout << "\n";

    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;

    cout << "\n";

    triangle.draw();
    cout << "Triangle Area: " << triangle.calculateArea() << endl;
    cout << "Triangle Perimeter: " << triangle.calculatePerimeter() << endl;

    cout << "\nPerforming Additional Tests...\n";
    
    Circle smallCircle(3, 3, "Yellow", 5);
    smallCircle.draw();
    cout << "Small Circle Area: " << smallCircle.calculateArea() << endl;
    
    Rectangle wideRectangle(0, 0, "Purple", 30, 5);
    wideRectangle.draw();
    cout << "Wide Rectangle Perimeter: " << wideRectangle.calculatePerimeter() << endl;

    return 0;
}