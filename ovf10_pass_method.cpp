#include <iostream>
#include <cmath>
#include <fstream>

double X0 = 0;
double XN = 3.1415926535897932384;

using namespace std;

double right(double x)
{
    return sin(x);
}

//TEMPLATE A_i * y_i-1 - B_i * y_i + C_i * y_i+1 = F_i

void pass(double a1, double a2, double b1, double b2, double a, double b, int n, double( * func)(double)){
    double * s = new double[n];
    double * t = new double[n];
    double * y = new double[n];

    double h = (XN - X0)/(n - 1.);

    double A, B, C;
    A = 1./(h * h);
    B = 2./(h * h);
    C = A;

    //STRAIGHTFORWARD

        //BOUNDARY CONDITIONS (I AND II TYPES, FIRST PRECISION ORDER)
    s[0] = -a2/(a1 * h - a2);
    t[0] = a * h/(a1 * h - a2);

    for(int i = 1; i < n; i++){
        s[i] = C/(B - A * s[i - 1]);
        t[i] = (A * t[i - 1] - func(i * h))/(B - A * s[i - 1]);
    }

    //BACKWARD
    y[n - 1] = (b * h + b2 * t[n - 2])/(b1 * h + b2 * (1 + s[n - 2]));

    ofstream out("graph.txt");
    out << XN << "\t" << y[n - 1] << endl;

    for(int i = n - 1; i >= 1; i--){
        y[i - 1] = s[i - 1] * y[i] + t[i - 1];
        out << (i - 1) * h << "\t" << y[i - 1] << endl;
    }


}

int main()
{
    pass(1, 0, 1, 0, 0, 0, 100, right);
}
