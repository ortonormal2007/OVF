#include<iostream>

using namespace std;

double right(double y, double x){
	return -y;
}

void euler(double xinit, double tinit, double tfinal, double step, double(*right)(double, double)){
	FILE * integ_line;
	integ_line = fopen("integralEU1.txt", "w");
	int n = 1;
	double x_next = 0;
	double x_cur = xinit;
	fprintf(integ_line, "%g\t%.20f\n", tinit, xinit);
	double t_cur = tinit;
	while (t_cur <= tfinal){
	x_next = x_cur + step * right(x_cur, t_cur);
		x_cur = x_next;
		fprintf(integ_line, "%g\t%.20f\n", t_cur, x_cur);
		t_cur = step*n;
		n++;
	}
	fclose(integ_line);
}

void rungekutta(double xinit, double tinit, double tfinal, double step, double(*right)(double, double)){
	FILE * integ_line1;
	integ_line1 = fopen("integralRK1.txt", "w");
	int n = 1;
	double x_next = 0;
	double x_cur = xinit;
	fprintf(integ_line1, "%g\t%.20f\n", tinit, xinit);
	double t_cur = tinit;
	while (t_cur <= tfinal){
		x_next = x_cur + step * (0.25 * right(x_cur, t_cur) + 0.75 * right(x_cur + ((2. / 3.) * step * right(x_cur, t_cur)), t_cur + ((2. / 3.) * step)));
		x_cur = x_next;
		fprintf(integ_line1, "%g\t%.20f\n", t_cur, x_cur);
		t_cur = step*n;
		n++;
	}
	fclose(integ_line1);
}

int main(){
	double xinit = 0;
	double tinit = 0;
	double tfinal = 0;
	cout << "Enter t_0: " << endl;
	cin >> tinit;
	cout << "Enter x(t_0)" << endl;
	cin >> xinit; 
	cout << "Enter t_final" << endl;
	cin >> tfinal;
	euler(xinit, tinit, tfinal, 0.1, right);
	rungekutta(xinit, tinit, tfinal, 0.1, right);

	return 0;
}
