#include <iostream>
#include <cmath>

const double PI = 3.1415926;

class PolarVector {
private:
    double length;
    double angle;

    void normalizeAngle() {
        while (angle >= 2 * PI) angle -= 2 * PI;
        while (angle < 0) angle += 2 * PI;
    }

public:
    PolarVector();
    PolarVector(double len, double ang);
    ~PolarVector() = default;

    void input();
    void output() const;

    void read(std::istream& in);
    void write(std::ostream& out) const;

    void setLength(double len);
    void setAngleDegrees(double angDeg);

    double getLength() const;
    double getAngleDegrees() const;
};

PolarVector::PolarVector() : length(0), angle(0) {}

PolarVector::PolarVector(double len, double ang) {
    if (len < 0) {
        length = -len;
        angle = (ang - 180.0) * PI / 180.0;
    } else {
        length = len;
        angle = ang * PI / 180.0;
    }
    normalizeAngle();
}

void PolarVector::input() {
    std::cout << "Длина: ";
    double len;
    std::cin >> len;

    std::cout << "Угол (град): ";
    double angDeg;
    std::cin >> angDeg;

    if (len < 0) {
        length = -len;
        angle = (angDeg - 180.0) * PI / 180.0;
    } else {
        length = len;
        angle = angDeg * PI / 180.0;
    }
    normalizeAngle();
}

void PolarVector::output() const {
    std::cout << "Вектор: длина=" << length
              << ", угол=" << angle * 180.0 / PI << "°\n";
}

void PolarVector::read(std::istream& in) {
    double len, angDeg;
    in >> len >> angDeg;

    if (len < 0) {
        length = -len;
        angle = (angDeg - 180.0) * PI / 180.0;
    } else {
        length = len;
        angle = angDeg * PI / 180.0;
    }
    normalizeAngle();
}

void PolarVector::write(std::ostream& out) const {
    out << "Вектор: длина=" << length
        << ", угол=" << angle * 180.0 / PI << "°\n";
}

void PolarVector::setLength(double len) {
    if (len < 0) {
        length = -len;
        angle += PI;
    } else {
        length = len;
    }
    normalizeAngle();
}

void PolarVector::setAngleDegrees(double angDeg) {
    angle = angDeg * PI / 180.0;
    normalizeAngle();
}

double PolarVector::getLength() const {
    return length;
}

double PolarVector::getAngleDegrees() const {
    return angle * 180.0 / PI;
}

int main() {
    PolarVector v1;
    PolarVector v2(-5.0, 45.0);

    std::cout << "v1: ";
    v1.output();
    std::cout << "v2: ";
    v2.output();

    v1.setLength(-3.0);
    v1.setAngleDegrees(90.0);
    std::cout << "После изменений v1: ";
    v1.output();

    std::cout << "\nВведите новый вектор (длина угол в градусах): ";
    v2.read(std::cin);
    std::cout << "Введённый вектор: ";
    v2.write(std::cout);
    return 0;
}


//добавить диструктор(по умолчанию)
//методоы ввода вывода
//методы, принимающие ссылку на std:cin и читает из этого потока 2 значения и устанавливает значения длинны и угла(логика установки значений имеющаяся)
//метод берёт ссылку на std:cout и выводит туда длинну и угол
