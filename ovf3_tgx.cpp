#include <iostream>
#include <cmath>
#include <cstdlib>
#define PI 3.141592653589

double func(double x) {
	return tan(x) - x;
}

double deriv(double x){
	return ((1 / (cos(x)*cos(x))) - 1);
}

double deriv2(double x){
	return 2 * tan(x) / (cos(x) * cos(x));
}



double simp_iter(double(*func)(double), double eps, double lam, double n){
	double z, z0;
	z0 = 0;
	z = 0;
	z0 = (n + 1.) * PI - (PI / 2.0);
	if (deriv2(z0) > 0){
		z0 = z0 - 0.03;
	}
	if (deriv2(z0) < 0){
		z0 = z0 + 0.03;
	}
	while (abs(z - z0) > eps){
		z = z0;
		z0 = z - (func(z)/lam);
	}
	return z0;
}

double newton(double(*func)(double), double(*deriv)(double), double(*deriv2)(double), double eps, double n){
	double x0, x1;
	x0 = 0;
	x1 = 0;
	x0 = (n + 1.) * PI - (PI / 2.0);
	if (deriv2(x0) > 0){
		x0 = x0 - 0.01;
	}
	if (deriv2(x0) < 0){
		x0 = x0 + 0.01;
	}
	while (fabs(x1 - x0) > eps)
	{
		x1 = x0;
		x0 = x1 - (func(x1) / deriv(x1));

	}
	return x0;
}


int main(){
	double n = 0;
	std::cin >> n;
	printf("%.5f\n", simp_iter(func, 0.001, 20, 1));
	printf("%.5f\n", newton(func, deriv, deriv2, 0.001, n));
	//secant();
	return 0;
}






















/*void secant(){
double x, xnext, xprev;
double eps = 0.001;
std::cin >> x >> xprev;
xnext = x - (func(x)*((x - xprev) / (func(x) - func(xprev))));
printf("%f\n", xnext);
while (abs(x - xnext) > eps){
xprev = x;
x = xnext;
xnext = x - (func(x)*((x - xprev) / (func(x) - func(xprev))));
printf("%f\n", xnext);
}
printf("%f", xnext);
}*/
