#include <iostream>
#include <cmath>
#include <string>

const double PI = 3.14159;

class Shape {
public:
    virtual void whoAmI() = 0;
};

class TwoDimensionalShape : public Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class ThreeDimensionalShape : public Shape {
public:
    virtual double surfaceArea() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDimensionalShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }

    double perimeter() override {
        return 4 * side;
    }

    void whoAmI() override {
        std::cout << "I am Square. I am a two-dimensional shape." << std::endl;
    }
};

class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return PI * radius * radius;
    }

    double perimeter() override {
        return 2 * PI * radius;
    }

    void whoAmI() override {
        std::cout << "I am Circle. I am a two-dimensional shape." << std::endl;
    }
};

class Rectangle : public TwoDimensionalShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }

    void whoAmI() override {
        std::cout << "I am Rectangle. I am a two-dimensional shape." << std::endl;
    }
};

class Triangle : public TwoDimensionalShape {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double area() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() override {
        return a + b + c;
    }

    void whoAmI() override {
        std::cout << "I am Triangle. I am a two-dimensional shape." << std::endl;
    }
};

class Cube : public ThreeDimensionalShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double surfaceArea() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }

    void whoAmI() override {
        std::cout << "I am Cube. I am a three-dimensional shape." << std::endl;
    }
};

class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double surfaceArea() override {
        return 4 * PI * radius * radius;
    }

    double volume() override {
        return (4.0 / 3.0) * PI * radius * radius * radius;
    }

    void whoAmI() override {
        std::cout << "I am Sphere. I am a three-dimensional shape." << std::endl;
    }
};

class Cylinder : public ThreeDimensionalShape {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double surfaceArea() override {
        return 2 * PI * radius * height + 2 * PI * radius * radius;
    }

    double volume() override {
        return PI * radius * radius * height;
    }

    void whoAmI() override {
        std::cout << "I am Cylinder. I am a three-dimensional shape." << std::endl;
    }
};

class Cone : public ThreeDimensionalShape {
private:
    double radius;
    double height;

public:
    Cone(double r, double h) : radius(r), height(h) {}

    double surfaceArea() override {
        return PI * radius * (radius + sqrt(height * height + radius * radius));
    }

    double volume() override {
        return (1 / 3) * PI * height * radius * radius;
    }

    void whoAmI() override {
        std::cout << "I am Cone. I am a three-dimensional shape." << std::endl;
    }
};

int main() {
    Square square(5);
    Circle circle(3);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);

    Cube cube(3);
    Sphere sphere(5);
    Cylinder cylinder(3, 7);
    Cone cone(3, 6);

    square.whoAmI();
    circle.whoAmI();
    rectangle.whoAmI();
    triangle.whoAmI();
    cube.whoAmI();
    sphere.whoAmI();
    cylinder.whoAmI();
    cone.whoAmI();

    std::cout << "Square: Area = " << square.area() << ", Perimeter = " << square.perimeter() << std::endl;
    std::cout << "Circle: Area = " << circle.area() << ", Perimeter = " << circle.perimeter() << std::endl;
    std::cout << "Rectangle: Area = " << rectangle.area() << ", Perimeter = " << rectangle.perimeter() << std::endl;
    std::cout << "Triangle: Area = " << triangle.area() << ", Perimeter = " << triangle.perimeter() << std::endl;

    std::cout << "Cube: Surface Area = " << cube.surfaceArea() << ", Volume = " << cube.volume() << std::endl;
    std::cout << "Sphere: Surface Area = " << sphere.surfaceArea() << ", Volume = " << sphere.volume() << std::endl;
    std::cout << "Cylinder: Surface Area = " << cylinder.surfaceArea() << ", Volume = " << cylinder.volume() << std::endl;
    std::cout << "Cone: Surface Area = " << cone.surfaceArea() << ", Volume = " << cone.volume() << std::endl;

    return 0;
}
