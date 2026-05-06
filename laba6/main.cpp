#include <iostream>
#include <cmath>

const double PI = 3.1415926;

class PolarVector {
private:
    double length;
    double angle; // угол в радианах

public:
    PolarVector();
    PolarVector(double len, double ang);
    
    void input();
    void output() const;
    
    void setLength(double len);
    void setAngleDegrees(double angDeg);
    
    double getLength() const;
    double getAngleDegrees() const;
};

// Определения методов класса

PolarVector::PolarVector() : length(0), angle(0) {}

PolarVector::PolarVector(double len, double ang)
    : length(len), angle(ang * PI / 180.0) {}

void PolarVector::input() {
    std::cout << "Длина: ";
    std::cin >> length;
    std::cout << "Угол (град): ";
    double angDeg;
    std::cin >> angDeg;
    angle = angDeg * PI / 180.0;
}

void PolarVector::output() const {
    std::cout << "Вектор: длина=" << length
              << ", угол=" << angle * 180.0 / PI << "°\n";
}

void PolarVector::setLength(double len) {
    length = len;
}

void PolarVector::setAngleDegrees(double angDeg) {
    angle = angDeg * PI / 180.0;
}

double PolarVector::getLength() const {
    return length;
}

double PolarVector::getAngleDegrees() const {
    return angle * 180.0 / PI;
}

// Основная функция

int main() {
    PolarVector v1;
    PolarVector v2(5.0, 45.0);
    
    std::cout << "v1: ";
    v1.output();
    std::cout << "v2: ";
    v2.output();
    
    v1.setLength(3.0);
    v1.setAngleDegrees(90.0);
    std::cout << "После изменений v1: ";
    v1.output();
    
    std::cout << "\nВведите новый вектор:\n";
    v2.input();
    std::cout << "Введённый вектор: ";
    v2.output();

    return 0;
}
