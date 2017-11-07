#include <iostream>

using namespace std;

double right1(double y, double x/*, double t*/){
    return (10 * x) - (2 * x * y);
}

double right2(double y, double x/*, double t*/){
    return (2 * x * y) - (10 * y);
}



void rungekutta(double x, double y ,double t, double tfinal, double step, double(*right1)(double, double), double(*right2)(double, double)){
    FILE * phase_plane;
    phase_plane = fopen("phase plane.txt", "w");
    int n = 1;
    double x_next = 0;
    double y_next = 0;
    //double x_cur = xinit;
//    fprintf(phase_plane, "%g\t%.20f\t%.20f", t, x, y);
    fprintf(phase_plane, "%g\t%.10f\t%.10f\n",t ,x, y);
    double t_cur = t + step;
    while (t_cur <= tfinal){
        x_next = x + step * (0.25 * right1(y, x) + 0.75 * right1(y + ((2. / 3.) * step * right2(y, x)), x + ((2. / 3.) * step * right1(y, x))/*t + ((2. / 3.) * step)*/));
        y_next = y + step * (0.25 * right2(y, x) + 0.75 * right2(y + ((2. / 3.) * step * right2(y, x)), x + ((2. / 3.) * step * right1(y, x))/*t + ((2. / 3.) * step)*/));


        x = x_next;
        y = y_next;

        fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t_cur, x, y);
        t_cur = t + step*n;
        n++;
    }
    fclose(phase_plane);
}


int main()
{
    double xinit = 0;
    double yinit = 0;
    double tinit = 0;
    double tfinal = 0;
    cout << "Enter t_0: " << endl;
    cin >> tinit;
    cout << "Enter x(t_0)" << endl;
    cin >> xinit;
    cout << "Enter y(t_0)" << endl;
    cin >> yinit;
    cout << "Enter t_final" << endl;
    cin >> tfinal;
    rungekutta(xinit, yinit, tinit, tfinal, 0.005, right1, right2);
    cout << "program stop, press any key..." << endl;
    return 0;
}
