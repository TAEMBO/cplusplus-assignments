#ifndef CALCULATORH
#define CALCULATORH

class Calculator {
	public:
        Calculator();
        void Add(double num);
        void Subtract(double num);
        void Multiply(double num);
        void Divide(double num);
        void Clear();
        double GetValue();
	private:
        double value;
};

#endif