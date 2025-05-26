#include <iostream>

// Classe base Retângulo
class Rectangle {
protected:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int area() const { return width * height; }
};

// Subclasse Quadrado herda de Retângulo
class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}
    void setWidth(int w) override {
        width = w;
        height = w;
    }
    void setHeight(int h) override {
        width = h;
        height = h;
    }
};

// Função que espera um Retângulo e altera dimensões
void printArea(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(10);
    std::cout << "Área = " << r.area() << std::endl;
}

int main() {
    Rectangle rect(5, 10);
    printArea(rect); // Imprime Área = 50 (5*10) -- correto

    Square sq(5);
    printArea(sq);   // Imprime Área = 100 (porque Sq aplica 10x10) -- inesperado!
}
