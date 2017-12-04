#include <iostream>
#include <cmath>

    using namespace std;

double right1(double u, double v){
    return 998 * u + 1998 * v;
}

double right2(double u, double v){
    return -999 * u - 1999 * v;
}

    double ans1(double t){
        return 4 * exp(-1 * t) - 3 * exp(-1 * 1000 * t);
    }

    double ans2(double t){
        return -2 * exp(-1 * t) + 3 * exp(-1 * 1000 * t);
    }


    void substanded(double * maxdif1, double * maxdif2, double x, double y, double h, double tfinal){
        FILE * phase_plane;
        phase_plane = fopen("pp.txt", "w");

        FILE * phase_plane1;
        phase_plane1 = fopen("ppa.txt", "w");

        int n = 1;
        double x_next = 10000;
        double y_next = 10000;
        double t = 0;

        fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t, x, y);
        fprintf(phase_plane1, "%g\t%.10f\t%.10f\n", t, ans1(t), ans2(t));

        double t_cur = t + h;
        double x0 = 0;
        double y0 = 0;



        double dif1 = 0;

        double dif2 = 0;

        while (t_cur <= tfinal){

            dif1 = 0;
            dif2 = 0;
            //FIRST ITERATION FROM VALUE OF PREV POINT
            x_next = x - ((x - h * right1(x, y) - x)/200.);
            y_next = y - ((y - h * right2(x, y) - y)/200.);

            //SIMPLE ITERATIONS PROCESS
            while ((abs(x_next - x0) > 0.0001) || (abs(y_next - y0) > 0.0001)){
                x0 = x_next;
                y0 = y_next;
                x_next = x0 - ((x0 - h * right1(x0, y0) - x)/200.);
                y_next = y0 - ((y0 - h * right2(x0, y0) - y)/200.);

            }

            //NEXT STEP OF GRID
            x = x_next;
            y = y_next;

            dif1 = x - ans1(t_cur);
            dif2 = y - ans2(t_cur);

            if (dif1 > *maxdif1){
                *maxdif1 = dif1;
            }

            if (dif2 > *maxdif2){
                *maxdif2 = dif2;
            }


            fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t_cur, x, y);
            fprintf(phase_plane1, "%g\t%.10f\t%.10f\n", t_cur, ans1(t_cur), ans2(t_cur));

            n++;
            t_cur = t + h*n;

        }


        fclose(phase_plane);
        fclose(phase_plane1);
    }

    int main()
    {
        //double xinit = 0;
       // double yinit = 0;
        double tfinal = 0;

        /*cout << "Enter x(t_0)" << endl;
        cin >> xinit;
        cout << "Enter y(t_0)" << endl;
        cin >> yinit;*/
        cout << "Enter t_final" << endl;
        cin >> tfinal;

        //substanded(xinit, yinit, 0.001, tfinal);
        double difx = 0;
        double dify = 0;

        double difx2 = 0;
        double dify2 = 0;

        //cout <<  / substanded(xinit, yinit, i, tfinal) << endl;

        for (double i = 1; i >= 0.00001; i = i * 0.5){
            substanded(&difx, &dify, 1, 1, i, tfinal);
            substanded(&difx2, &dify2, 1, 1, i * 0.5, tfinal);
            cout << difx / difx2 << "\t";
            cout << dify / dify2 << endl;
            //cout << difx << endl;
            //cout << dify << endl;
        }

        //substanded(&difx, &dify, 1, 1, 0.0001, tfinal);
        cout << "program has been done! press any key..." << endl;

        return 0;
    }
