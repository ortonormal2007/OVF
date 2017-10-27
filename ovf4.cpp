#include <iostream>
#include <cmath>
#include <fstream>

#define REF1 1.57079632679*0.5
#define REF2 2.97314800644958

using namespace std;

double func1(double x){
	return 1. / (1 + x*x);
}

double func2(double x){
	return (pow(x, 1. / 3))*(exp(sin(x)));
}

double paral(double(*func)(double), double a, double b, int num){
	double I;
	I = 0;
	double dx = (b - a) / num;
	while (a < b){
		I += (func(a) * dx + func(a + dx) * dx) / 2;
		a += dx;
	}
	return I;
}

double simps(double(*func)(double), double a, double b, double num){
	double I;
	I = 0;
	double ainit = a;
	double dx = (b - a) / num;
	I += (dx / 3.)*func(a);
	
	int n = 1;
	
	a = ainit + dx;

	

	while (a < b){
		I += 4 * (dx / 3.)*func(a);
		n += 2;
		a = ainit + n*dx;

	}
	a = ainit + 2 * dx;
	n = 2;
	while (a < b){
		I += 2 * (dx / 3.)*func(a);
		n += 2;
		a = ainit + n*dx;

	}

	I += (dx / 3.)*func(b);
	/*while (a < b){
		I += (dx / 6.)*(func(a) + (4. * func(a + (dx / 2.))) + func(a + dx));
		a += dx;
	}*/
	return I;
}

int main(){
	double nummax = 4096;
	double num = 2;
	double ratio;
	ofstream lalala("simps1.txt");
	while (num <= nummax){
		ratio = abs((REF2 - simps(func2, 1, 2, num))/(REF2- simps(func2, 1, 2, num * 2)));
		lalala << num << "\t" << ratio << endl;
		num *= 2;
	}

	

	/*double a, b;
	a = 0;
	b = 0;

	cin >> a;
	cin >> b;

	double i_1p4 = paral(func1, a, b, 4);
	printf("%f\n", i_1p4);

	double i_1p8 = paral(func1, a, b, 8);
	printf("%f\n", i_1p8);

	double i_1p16 = paral(func1, a, b, 16);
	printf("%f\n", i_1p16);

	printf("___________\n", i_1p16);

	double i_1s4 = simps(func1, a, b, 4);
	printf("%f\n", i_1s4);

	double i_1s8 = simps(func1, a, b, 8);
	printf("%f\n", i_1s4);

	double i_1s16 = simps(func1, a, b, 16);
	printf("%f\n", i_1s4);

	cin >> a;
	cin >> b;

	double i_2p4 = paral(func2, a, b, 4);
	printf("%f\n", i_2p4);

	double i_2p8 = paral(func2, a, b, 8);
	printf("%f\n", i_2p8);

	double i_2p16 = paral(func2, a, b, 16);
	printf("%f\n", i_2p16);

	printf("___________\n", i_1p16);

	double i_2s4 = simps(func2, a, b, 4);
	printf("%f\n", i_2s4);

	double i_2s8 = simps(func2, a, b, 8);
	printf("%f\n", i_2s8);

	double i_2s16 = simps(func2, a, b, 16);
	printf("%f\n", i_2s16);
*/
	return 0;
}
