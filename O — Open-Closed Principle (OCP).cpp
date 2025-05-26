#include <vector>
#include <iostream>

// Interface abstrata para formas geom\u00e9tricas
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

// Implementa\u00e7\u00e3o para C\u00edrculo
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

// Implementa\u00e7\u00e3o para Quadrado
class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override { return side * side; }
};

// Fun\u00e7\u00e3o que calcula \u00e1rea total, sem precisar saber tipos espec\u00edficos
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0;
    for(const auto* shape : shapes) {
        total += shape->area();
    }
    return total;
}

// Exemplo de uso
int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(1.0));
    shapes.push_back(new Square(2.0));

    std::cout << "Total Area: " << totalArea(shapes) << std::endl;
    // Se quisermos adicionar Triângulo, basta criar nova classe Triangle : Shape
    // sem alterar totalArea nem as classes existentes.
}
