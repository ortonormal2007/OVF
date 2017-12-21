#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
#include "C:\fftw\fftw3.h"


#define n 4096

//#define pi 3.141592653589

using namespace std;

void no_wisdom (){
    fftw_cleanup();
}

void fourier (fftw_complex * in, fftw_complex * out){
    fftw_plan p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
}
int main(){
    no_wisdom ();
    ofstream four("four.txt");
    ofstream W("w.txt");
    ofstream func("func.txt");

    fftw_complex orig[n];
    fftw_complex trans[n];

    double a = 0;
    double b = /*2*M_PI*/2*M_PI*(n-2.)/(n-1.);
    double t = (b - a)/(n - 1);

    for (int i = 0; i < n; i++)
        {
            orig[i][0] = sin(1024*(a + i * t))/* * 0.5*(1 - cos(2 * M_PI*(i) / n))*/;
            orig[i][1] = 0;
            func << (a + i * t) << "\t" << orig[i][0]<< "\t" << orig[i][1] << endl;
        }

    fourier(orig, trans);

    for (int i = 0; i < n; i++){
        trans[i][0] /= n;
        trans[i][1] /= n;
        four << (a * 2 * M_PI / (b - a) + t*i * 2 * M_PI / (b - a)) << "\t" << trans[i][0]<< "\t" << trans[i][1] << endl;
        W << a * 2 * M_PI / (b - a) + i * 2 * M_PI / (b - a)  <<  "\t" << pow(trans[i][0],2) + pow(trans[i][1],2) << endl;
    }
    cout << "Done!" << endl;
    return 0;
}

