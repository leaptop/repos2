#pragma once
class Complex {
    public:
		Complex();
		Complex(double x, double y);
		~Complex();

		Complex operator + (Complex number);
		Complex operator - (Complex number);
		Complex operator * (Complex number);
		Complex operator / (Complex& number);
		//Complex& operator = (Complex& number);
		Complex operator = (Complex number);

		Complex sumByRealNumber(double number);
		Complex decByRealNumber(double number);
		Complex multByRealNumber(double number);
		Complex divideByRealNumber(double number);

		double ReZ();
		double ImZ();
		double ReZ(double x);
		double ImZ(double y);

		static Complex expZ(Complex number);
    private:
		double x, y;
};

void printComplexMas(Complex* mas, int N);
