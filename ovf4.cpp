#include <iostream>
#include <cmath>

using namespace std;

double func1(double x){
	return 1. / (1. + x*x);
}

double deri1(double x){
	return (-2. * x) / ((1. + x*x)*(1. + x*x));
}

/*double func2(double x){
	return 
}*/

//double deri2(double x){
//	return
//}

double paral(double(*func)(double), double(*deri)(double), int num){
	double I, R, a, b, h;
	a = 0; 
	b = 0;
	cin >> a, b;
	h = b - a;
	
	double dx = h / num;
	for (int i = 0; i < num; i++){
		I += 0.5*(func(a) * dx - func(b) * dx);
		R += (-dx*dx*dx)*deri(a) / 12.;
		a += dx;
		b += dx;
	}
	I += R;

	return I;
}

double simps(){


}

int main(){
	
	

	return 0;
}
