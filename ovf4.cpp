#include <iostream>
#include <cmath>
#include <fstream>

#define REF1 1.57079632679
#define REF2 1.29587400873

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

double simps(double(*func)(double), double a, double b, int num){

	double I;
	I = 0;
	double dx = (b - a) / num;
	while (a < b){
		I += (dx / 6.)*(func(a) + (4 * func((a + a + dx) / 2.)) + func(a + dx));
		a += dx;
	}
	return I;
}

int main(){
	int nummax = 2048;
	int num = 1;
	double res;
	double res1;
	double ratio;
	ofstream lalala("ratio(2_sim).txt");
	while (num < nummax){
		res = fabs(REF2 - simps(func2, 0, 1, num));
		res1 = fabs(REF2 - simps(func2, 0, 1, num * 2));
		ratio = res / res1;
		lalala << num << "\t" << ratio << endl;
		num *= 2;
	}


	//double * parr1 = prestest1(func1, -1, 1, 2048);
	//double * parr2 = prestest2(func2, 0, 1, 2048);
	
	/*
	double a, b;
	a = 0;
	b = 0;

	cin >> a;
	cin >> b;

	double I_1P4 = paral(func1, a, b, 4);
	printf("%f\n", I_1P4);

	double I_1P8 = paral(func1, a, b, 8);
	printf("%f\n", I_1P8);

	double I_1P16 = paral(func1, a, b, 16);
	printf("%f\n", I_1P16);

	printf("___________\n", I_1P16);

	double I_1S4 = simps(func1, a, b, 4);
	printf("%f\n", I_1S4);

	double I_1S8 = simps(func1, a, b, 8);
	printf("%f\n", I_1S4);

	double I_1S16 = simps(func1, a, b, 16);
	printf("%f\n", I_1S4);

	cin >> a;
	cin >> b;

	double I_2P4 = paral(func2, a, b, 4);
	printf("%f\n", I_2P4);

	double I_2P8 = paral(func2, a, b, 8);
	printf("%f\n", I_2P8);

	double I_2P16 = paral(func2, a, b, 16);
	printf("%f\n", I_2P16);

	printf("___________\n", I_1P16);

	double I_2S4 = simps(func2, a, b, 4);
	printf("%f\n", I_2S4);

	double I_2S8 = simps(func2, a, b, 8);
	printf("%f\n", I_2S8);

	double I_2S16 = simps(func2, a, b, 16);
	printf("%f\n", I_2S16);
	*/

	return 0;
}
