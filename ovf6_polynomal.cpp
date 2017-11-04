#include<iostream>
#include<cmath>
#include<fstream>

#define PI 3.14159265359

using namespace std;

double *pnts(int n){
	double *pnt = new double[n + 1];
	for (int i = 0; i <= n; i++){
		pnt[i] = (PI * i) / (4. * n);
	}
	return pnt;
}

double *pnts1(int n){
	double *pnt = new double[n + 1];
	for (int i = 0; i <= n; i++){
		pnt[i] = -1 + (2 * i) / (double)n;
	}
	return pnt;
}

double func(double x){
	return sin(x);
}

double funcrun(double x){
	return (1 / ((1. + 25. * x * x)));
}


double poly(double(*func)(double), double *pnt, int rdx, double x){
	double P = 0;
	double L;
	for (int i = 0; i <= rdx; i++){
		L = 1;
		for (int j = 0; j <= rdx; j++){
			if (j == i) continue;
			L *= (x - pnt[j]) / (pnt[i] - pnt[j]);
		}
		P += func(pnt[i]) * L;
	}
	return P;
}



int main(){
	/*int rdx = 0;
	double a = 0;
	double ainit = a;
	double b = 0;
	double t = 0;
	cout << "Enter radix: ";
	cin >> rdx;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter point for test: ";
	cin >> t;
	int n = 1;

	ofstream grinter("poly.txt");
	ofstream grfunc("func.txt");
	ofstream grdiff("diff.txt");
	ofstream grpoint("points.txt");
	ofstream grprec("precise.txt");
	double *ppnts = pnts(rdx);

	while (a <= b){
		grinter << a << "\t" << poly(func, ppnts, rdx, a) << endl;
		grfunc << a << "\t" << func(a) << endl;
		grdiff << a << "\t" << abs(poly(func, ppnts, rdx, a) - func(a)) << endl;
		a = ainit + 0.001 * n;
		n++;
	}
	for (int i = 0; i <= rdx; i++){
		grpoint << ppnts[i] << "\t" << func(ppnts[i]) << endl;
	}
	delete[] ppnts;

	//PREC TEST


	for (int i = 1; i <= 80; i++){
		double *ppnts1 = pnts(i);
		grprec << i << "\t" << abs(func(t) - poly(func, ppnts1, i, t)) << endl;
		delete[] ppnts1;
	}*/

	int rdx = 10;
	double a = -1;
	double ainit = a;
	double b = 0;
	int n = 1;

	ofstream grinter("poly1.txt");
	ofstream grfunc("func1.txt");
	ofstream grdiff("diff1.txt");
	ofstream grpoint("points1.txt");

	double *ppnts = pnts1(rdx);
	while (a <= 1){
		grinter << a << "\t" << poly(funcrun, ppnts, rdx, a) << endl;
		grfunc << a << "\t" << funcrun(a) << endl;
		grdiff << a << "\t" << abs(poly(funcrun, ppnts, rdx, a) - funcrun(a)) << endl;
		a = ainit + 0.001 * n;
		n++;
	}
	for (int i = 0; i <= rdx; i++){
		grpoint << ppnts[i] << "\t" << funcrun(ppnts[i]) << endl;
	}
	return 0;
}
