#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define pi 3.1415926535897932384

double X0 = 0;
double XN = pi;

using namespace std;

double init(double x)
{
    return 0;
}

double pass(double a, double b, int n){
    double h = (XN - X0)/(n - 1.);

    double * s = new double[n];
    double * t = new double[n];
    double * y = new double[n];
    double * phi = new double[n];
    double * fun = new double[n];

    ofstream out3("graph3.txt");
    srand(time(0));
    phi[0] = 0;
    phi[n-1] = 0;
    for(int i = 1; i < n-1; i++){
        phi[i] = rand()%10;
    }

    for(int i = 0; i < n; i++){
        out3 << i * h + X0 << "\t" << phi[i] << endl;
    }

    /*fun[0] = (-(-2.*phi[0] + phi[1])/(h * h) + exp(phi[0]));
    fun[n-1] = (-(phi[n-2] - 2.*phi[n-1])/(h * h) + exp(phi[n-1]) - (1.-((n-1)*h - 1.)*((n-1)*h - 1.)));
    for(int i = 1; i < n-1; i++){
        fun[i] = (-(phi[i-1] - 2.*phi[i] + phi[i+1])/(h * h) + exp(phi[i]) - (1.-(i*h - 1.)*(i*h - 1.)));
    }*/

    fun[0] = (-(-2.*phi[0] + phi[1])/(h * h) + sin(X0));
    fun[n-1] = (-(phi[n-2] - 2.*phi[n-1])/(h * h) + sin(XN));
        for(int i = 1; i < n-1; i++){
            fun[i] = (-(phi[i-1] - 2.*phi[i] + phi[i+1])/(h * h) + sin(i*h));
        }

    int k = 0;
    for(;;){

        double A, B, C;
        A = 1./(h * h);
        B = 2./(h * h);
        C = A;
        s[0] = 0;
        t[0] = a;

        for(int i = 1; i < n; i++){
            s[i] = C/(B - A * s[i - 1]);
            t[i] = (A * t[i - 1] - fun[i])/(B - A * s[i - 1]);
        }

        y[n - 1] = b;

        for(int i = n - 1; i >= 1; i--){
            y[i - 1] = s[i - 1] * y[i] + t[i - 1];
        }

        fun[0] = (-(-2.*phi[0] + phi[1])/(h * h) + sin(X0));
        fun[n-1] = (-(phi[n-2] - 2.*phi[n-1])/(h * h) + sin(XN));
        for(int i = 1; i < n-1; i++){
            fun[i] = (-(phi[i-1] - 2.*phi[i] + phi[i+1])/(h * h) + sin(i*h));
        }

       /* fun[0] = (-(-2.*phi[0] + phi[1])/(h * h) + exp(phi[0]));
        fun[n-1] = (-(phi[n-2] - 2.*phi[n-1])/(h * h) + exp(phi[n-1]) - (1.-((n-1)*h - 1.)*((n-1)*h - 1.)));
        for(int i = 1; i < n-1; i++){
            fun[i] = (-(phi[i-1] - 2.*phi[i] + phi[i+1])/(h * h) + exp(phi[i]) - (1.-(i*h - 1.)*(i*h - 1.)));
        }*/

        for(int i = 0; i < n; i++){
            phi[i] = phi[i] + y[i];

        }
        double def = 0;
        for(int i = 0; i < n; i++){
            if(phi[i] > def){
                def = y[i];
            }
        }
        k++;
        if (def < 0.001){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        out3 << i * h + X0 << "\t" << phi[i]<< endl;
    }
    cout << k << endl;

    /*double max = 0;
    for(int i = 0; i < n; i++){
        if(phi[i] > max){
            max = phi[i];

        }
    }*/
    int num = (n-1)*0.5;
    return phi[num];
}

int main()
{  
    /* for(int i = 2; i < 1024; i *= 2)
        cout << (pass(0, 0, i) + sin(0.5*XN))/(pass(0, 0, i*2) + sin(0.5*XN));
    */

  pass(0, 0, 100);

  /*  double def = 0;

    for(int i = 0; i < n; i++){
        if(phi[i] > def){
            def = y[i];
        }
    }*/
    return 0;

}
