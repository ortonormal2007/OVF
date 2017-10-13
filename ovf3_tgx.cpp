#include <iostream>
#include <cmath>
#include <cstdlib>
#define PI 3,141592653589

double fi(double x) {
	return tan(x);
}

double func(double x) {
	return tan(x) - x;
}

double deriv(double x){
	return ((1/(cos(x)*cos(x))) - 1);
}

void simp_iter(){
	double z, z0;
	z0 = 0;
	z = 0;
	double eps = 0.00001;
	std::cin >> z0;
	while (abs(z - z0) > eps){
		z = z0;
		z0 = fi(z) ;
	}
	printf("%f", z0);
}

void newton(){
	/*double x, xnext;
	int n = 0;
	double eps = 0.00001;
	x = 0;
	xnext = 0;
	std::cin >> xnext;
	//x = (n + 1) * PI - (PI / 2.0) - 0.05;
	//xnext = x - func(x) / deriv(x);
	while (abs(x - xnext) > eps){
		x = xnext;
	
		xnext = x - func(x)/deriv(x);

	}
	printf("%f", xnext);*/
	double x0, x1;
	x0 = 0;
	x1 = 0;
	std::cin >> x0;
	while (fabs(x1 - x0) > 0.00001)
	{
		x1 = x0;
		x0 = x1 - (func(x1) / deriv(x1));
		
	}
	std::cout << x0;
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

}
*/

int main(){
	simp_iter();
	//newton();
	//secant();
	return 0;
}
