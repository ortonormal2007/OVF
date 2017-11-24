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
	return 4 * exp(-t) - 3 * exp(-1000 * t);
}

double ans2(double t){
	return -2 * exp(-t) + 3 * exp(-1000 * t);
}


void *substanded(double * maxdif1, double * maxdif2, double x, double y, double h, double tfinal){
	FILE * phase_plane;
	phase_plane = fopen("phase plane.txt", "w");

	FILE * phase_plane1;
	phase_plane1 = fopen("phase plane1.txt", "w");

	int n = 1;
	double x_next = 0;
	double y_next = 0;
	double t = 0;

	fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t, x, y);
	
	double t_cur = t + h;
	double x0 = 0;
	double y0 = 0;


	//double maxdif1 = 0;
	double dif1 = 0;

	//double maxdif2 = 0;
	double dif2 = 0;

	while (t_cur <= tfinal){

		//FIRST ITERATION FROM VALUE OF PREV POINT
		x_next = x - ((x - right1(x, y) - x));
		y_next = y - ((y - right2(x, y) - y));

		//SIMPLE ITERATIONS PROCESS
		while ((abs(x_next - x0) > 0.001) || (abs(y_next - y0) > 0.001)){
			x0 = x_next;
			y0 = y_next;
			x_next = x0 - ((x0 - right1(x0, y0) - x));
			y_next = y0 - ((y0 - right2(x0, y0) - y));

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


		fprintf(phase_plane1, "%g\t%.10f\t%.10f\n", t_cur, ans1(t_cur), ans2(t_cur));
		fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t_cur, ans1(t_cur), ans2(t_cur));
		t_cur = t + h*n;
		n++;
	}

	//fclose(phase_plane);
	//fclose(phase_plane1);
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

	//substanded(xinit, yinit, 0.001, tfinal);
	double * dif1;
	double * dif2;

	//cout <<  / substanded(xinit, yinit, i, tfinal) << endl;

	for (double i = 0.1; i >= 0.00001; i = i * 0.1){
		substanded(*dif1, *dif2, 1, 1, i, tfinal);
		substanded(*dif1, *dif2, 1, 1, i, tfinal);
		cout << *dif1 / *dif2 << endl;
	}
	cout << "program has been done! press any key..." << endl;

	return 0;
}
