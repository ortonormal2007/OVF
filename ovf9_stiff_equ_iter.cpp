#include <iostream>
#include <cmath>

using namespace std;

double right1(double u, double v){
	return 998 * u + 1998 * v;
}

double right2(double u, double v){
	return -999 * u - 1999 * v;
}

void substanded(double x, double y, double h, double tfinal){
	FILE * phase_plane;
	phase_plane = fopen("phase plane.txt", "w");
	int n = 1;
	double x_next = 0;
	double y_next = 0;
	double t = 0;

	fprintf(phase_plane, "%g\t%.10f\t%.10f\n", t, x, y);
	
	double t_cur = t + h;
	double x0 = 0;
	double y0 = 0;

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
	cout << "program has been done! press any key..." << endl;

	return 0;
}

