//#include "pch.h"
#include "Complex.h"
#include <math.h>
#include <iostream>

Complex::Complex() {
    this->x = 0.0;
    this->y = 0.0;
}

Complex::Complex(double x, double y) {
    this->x = x;
    this->y = y;
}

Complex::~Complex() {
}

double Complex::ReZ() {//возвращаем Real part
    return this->x;
}

double Complex::ImZ() {// возвращаем Imagine part
    return this->y;
}

double Complex::ReZ(double x) {//присваиваем вещественной части значение параметра
    this->x = x;
    return x;
}

double Complex::ImZ(double y) {//присваиваем мнимой части значение параметра
    this->y = y;
    return y;
}

Complex Complex::operator+(Complex number) {
    double x = this->ReZ() + number.ReZ();
    double y = this->ImZ() + number.ImZ();
    return Complex(x, y);
}

Complex Complex::operator-(Complex number) {
    double x = this->ReZ() - number.ReZ();
    double y = this->ImZ() - number.ImZ();
    return Complex(x, y);
}

Complex Complex::operator*(Complex number) {
    double x = this->ReZ() * number.ReZ() - this->ImZ() * number.ImZ();
    double y = this->ReZ() * number.ImZ() + this->ImZ() * number.ReZ();
    return Complex(x, y);
}

Complex Complex::operator/(Complex &number) {
    double k = ReZ() * ReZ() + number.ReZ() * number.ReZ();
    double x = (ReZ() * number.ReZ() + ImZ() * number.ImZ()) / k;
    double y = (ImZ() * number.ReZ() - ReZ() * number.ImZ()) / k;
    return Complex(x, y);
}

/*
Complex& Complex::operator= (Complex& number) {
	this->x = number.ReZ();
	this->y = number.ImZ();
	return *this;
}*/

Complex Complex::expZ(Complex number) {
    double x = cos(number.ImZ()) / exp(number.ReZ());
    double y = sin(number.ImZ()) / exp(number.ReZ());
    return Complex(x, y);
}

Complex Complex::sumByRealNumber(double number) {
    double x = this->x + number;
    double y = this->y + number;
    return Complex(x, y);
}

Complex Complex::decByRealNumber(double number) {
    double x = this->x - number;
    double y = this->y - number;
    return Complex(x, y);
}

Complex Complex::multByRealNumber(double number) {
    double x = this->x * number;
    double y = this->y * number;
    return Complex(x, y);
}

Complex Complex::divideByRealNumber(double number) {
    double x = this->x / number;
    double y = this->y / number;
    return Complex(x, y);
}

Complex Complex::operator=(Complex number) {
    this->x = number.ReZ();
    this->y = number.ImZ();
    return *this;
}

void printComplexMas(Complex *mas, int N) {
    for (int i = 0; i < N; i++) {
        std::cout << mas[i].ReZ() << " + " << mas[i].ImZ() << "i\n";
    }
    std::cout << "\n";
}

void printComplexMasDisc(Complex *mas, int N) {
    double x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (fabs(mas[i].ReZ()) < 0.00000001) x = 0; else x = mas[i].ReZ();
        if (fabs(mas[i].ImZ()) < 0.00000001) y = 0; else y = mas[i].ImZ();

        std::cout << x << " + " << -y << "i\n";
        // std::cout << mas[i].ReZ() << " + " << -mas[i].ImZ() << "i\n";
    }//X.ImZ(-X.ImZ());
    std::cout << "\n";
}
