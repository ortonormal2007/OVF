#include <iostream>

using namespace std;

//right1 998 * u + 1998 * v

//right2 - 999 * u - 1999 * v

double det(double h){
    return (1 - 998 * h)*(1 + 1999 * h) - (999 * h)*(- 1998 * h);
}

void substanded(double x, double y, double h, double tfinal){
    FILE * phase_plane;
        phase_plane = fopen("phase plane.txt", "w");
        int n = 1;
        double x_next = 0;
        double y_next = 0;
        double t = 0;
        double d = det(h);
        fprintf(phase_plane, "%g\t%.10f\t%.10f\n",t ,x, y);
        double t_cur = t + h;

        while (t_cur <= tfinal){

            x_next = ((1 + 1999 * h) * x + (1998 * h) * y)/d;
            y_next = (((-1 * 999) * h) * x + (1 - 998 * h) * y)/d;

            x = x_next;
            y = y_next;
            fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t_cur, x, y);
            t_cur = t + h*n;
            n++;
        }

        fclose(phase_plane);
}


int main()
{
    double xinit = 0;
    double yinit = 0;
    double tfinal = 0;

    cout << "Enter x(t_0)" << endl;
    cin >> xinit;
    cout << "Enter y(t_0)" << endl;
    cin >> yinit;
    cout << "Enter t_final" << endl;
    cin >> tfinal;
    substanded(xinit, yinit, 0.001, tfinal);

    cout << "Done!" << endl;
    return 0;
}


//SANYOK SOURCE: https://pastebin.com/8bcqdZvX
