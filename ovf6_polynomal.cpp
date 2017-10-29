#include<iostream>
#include<cmath>
#include<fstream>

#define PI 3.14159265359

using namespace std;

double *pnts(int n){
	double *pnt = new double[n + 1];
	for (int i = 0; i <= n; i++){
		pnt[i] = (PI * i) / (4 * n);
	}
	return pnt;
}

double func(double x){
	return sin(x);
}

double poly(double(*func)(double), double *pnt, double rdx, double x){
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
	int rdx = 0;
	double a = 0;
	double b = 0;
	cin >> rdx;
	cin >> a;
	cin >> b;

	ofstream grinter("poly.txt");
	ofstream grfunc("func.txt");
	ofstream grdiff("diff.txt");
	ofstream grpoint("points.txt");
	double *ppnts = pnts(rdx);
	while (a <= b){
		grinter << a << "\t" << poly(func, ppnts, rdx, a) << endl;
		grfunc << a << "\t" << func(a) << endl;
		grdiff << a << "\t" << abs(poly(func, ppnts, rdx, a) - func(a)) << endl;
		a += 0.1;
	}
	for (int i = 0; i <= rdx; i++){
		grpoint << ppnts[i] << "\t" << func(ppnts[i]) << endl;
	}
	delete[] ppnts;
	return 0;
}
