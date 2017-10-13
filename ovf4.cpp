#include <iostream>
#include <cmath>
 
using namespace std;
 
double func1(double x){
    return 1. / (1 + x*x);
}
 
double deri1(double x){
    return (-2 * x) / ((1 + x*x)*(1 + x*x));
}
 
double func2(double x){
    return (pow(x, 1. / 3))*(exp(sin(x)));
}
 
double deri2(double x){
    return exp(sin(x)) * (3 * x * cos(x) + 1);
}
 
double paral(double(*func)(double), double(*deri)(double), double a, double b, int num){
    double I, R;
    I = 0;
    R = 0;
    double dx =( b - a )/ num;
    while (a < b){
        I += (func(a) * dx + func(a + dx) * dx)/2;
        R += (-dx*dx*dx)*deri(a) / 12;
        a += dx;
    }
    I += R;
 
    return I;
}
 
double simps(double(*func)(double), double(*deri)(double), double a, double b, int num){
   
    double I/*, R*/;
    I = 0;
    double dx =( b - a )/ num;
    while (a < b){
        I += (dx/6.)*(func(a) + (4 * func((a + a + dx)/2.)) + func(a + dx));
        //R += (-dx*dx*dx)*deri(a) / 12;
        a += dx;
    }
    return I;
}
 
int main(){
 
    double a, b;
    a = 0;
    b = 0;
 
    cin >> a;
    cin >> b;
 
    double I_1P4 = paral(func1, deri1, a, b, 4);
    printf("%f\n", I_1P4);
 
    double I_1P8 = paral(func1, deri1, a, b, 8);
    printf("%f\n", I_1P8);
 
    double I_1P16 = paral(func1, deri1, a, b, 16);
    printf("%f\n", I_1P16);
 
    printf("___________\n", I_1P16);
 
    double I_1S4 = simps(func1, deri1, a, b, 4);
    printf("%f\n", I_1S4);
 
    double I_1S8 = simps(func1, deri1, a, b, 8);
    printf("%f\n", I_1S4);
 
    double I_1S16 = simps(func1, deri1, a, b, 16);
    printf("%f\n", I_1S4);
 
    cin >> a;
    cin >> b;
 
    double I_2P4 = paral(func2, deri2, a, b, 4);
    printf("%f\n", I_2P4);
 
    double I_2P8 = paral(func2, deri2, a, b, 8);
    printf("%f\n", I_2P8);
 
    double I_2P16 = paral(func2, deri2, a, b, 16);
    printf("%f\n", I_2P16);
 
    printf("___________\n", I_1P16);
 
    double I_2S4 = simps(func2, deri2, a, b, 4);
    printf("%f\n", I_2S4);
 
    double I_2S8 = simps(func2, deri2, a, b, 8);
    printf("%f\n", I_2S8);
 
    double I_2S16 = simps(func2, deri2, a, b, 16);
    printf("%f\n", I_2S16);
 
    return 0;
}
