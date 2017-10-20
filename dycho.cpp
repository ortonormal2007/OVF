#include <iostream>
#include <cmath>

int pres(double a, double b, double eps){
	double n;
	n = (log(((b - a) / eps)) / log(2.)) - 1.;
	return (int)n;
}

double foo(double x){
	return (8 * x*x*x + x*x + x - 7);
}

double bar(double x){
	return tan(x) - x;
}

void dycho(double(*func)(double)){
	double a, b, c;
	a = 0;
	b = 0;
	c = 0;
	std::cout << "Enter region:" << std::endl << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;

	int n = pres(a, b, 0.001);

	//c = (a + b) / 2;

	/*if (((func(a)*func(c) > 0) && (func(b)*func(c) > 0))){
	std::cout << "NO ROOTS in the region!" << std::endl;
	}*/
	//else {

	for (int i = 0; i < n; i++)
	//while (abs(a - b) > 0.001)
	{
		c = (a + b) / 2.;
		if (func(a)*func(c) <= 0){
			b = c;
		}
		else {
			if (func(b)*func(c) <= 0){
				a = c;
			}
		}
	}
	std::cout << "a = " << a << "; b = " << b << std::endl << "n = " << (int)n << std::endl << "ans = " << (a + b) / 2 << std::endl;
	/*printf("%.5f", (a + b) / 2);
	printf("%.5f", c);*/
}
//}

int main(){
	size_t var;

	while (true){
		std::cout << "1: Pol; 2: tg(x) = x" << std::endl;
		std::cin >> var;

		if (var == 1){
			dycho(foo);
			break;
		}
		else {
			if (var == 2){
				dycho(bar);
				break;
			}
			else {
				std::cout << "???" << std::endl;
				continue;
			}
		}
	}

	return 0;
}
