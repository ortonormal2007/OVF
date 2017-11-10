#include<iostream>
#include<cmath>

using namespace std;

double right(double y, double x){
	return -y;
}

double ans(double x){
	return exp(-x);
}

double euler(double xinit, double tinit, double tfinal, double step, double(*right)(double, double)){
	//FILE * integ_line;
	//integ_line = fopen("integralEUdif.txt", "w");

	int n = 1;
	double x_next = 1;
	double x_cur = xinit;
	double t_cur = tinit + step;
	double tmax = tinit;
	double dif = 0;
	double maxdif = fabs(xinit - ans(tinit));
	//fprintf(integ_line, "%g\t%.20f\n", tinit, xinit);
	//fprintf(integ_line, "%g\t%.20f\n", tinit, xinit - ans(tinit));
	//printf("%g\t%.20f\n", tinit, maxdif);
	while (t_cur <= tfinal){
		x_next = x_cur + step * right(x_cur, t_cur);
		x_cur = x_next;

		dif = fabs(x_cur - ans(t_cur));
		if (dif > maxdif){
			maxdif = dif;
			tmax = t_cur;
		}
		//printf("%g\t%.20f\n", t_cur, dif);
		n++;
		t_cur = tinit + step*n;
	}
	//fclose(integ_line);
	printf("%g   ", tmax);
	return maxdif;
}

double rungekutta(double xinit, double tinit, double tfinal, double step, double(*right)(double, double)){
	//FILE * integ_line1;
	//integ_line1 = fopen("integralRK1.txt", "w");
	int n = 1;
	double x_next = 0;
	double t_cur = tinit + step;
	double dif = 0;
	double maxdif = fabs(xinit - ans(tinit));
	double tmax = tinit;
	//fprintf(integ_line1, "%g\t%.20f\n", tinit, xinit);
	while (t_cur <= tfinal){
		x_next = xinit + step * (0.25 * right(xinit, t_cur) + 0.75 * right(xinit + ((2. / 3.) * step * right(xinit, t_cur)), t_cur + ((2. / 3.) * step)));
		xinit = x_next;
		dif = fabs(xinit - ans(t_cur));
		if (dif > maxdif){
			maxdif = dif;
			tmax = t_cur;
		}
		//fprintf(integ_line1, "%g\t%.20f\n", t_cur, xinit);
		n++;
		t_cur = tinit + step*n;
	}
	//fclose(integ_line1);
	printf("%g   ", tmax);
	return maxdif;
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

	double i = 1;
	while (i >= 0.000001){
		printf("%g\t%.20f\n", i, euler(xinit, tinit, tfinal, i , right) / euler(xinit, tinit, tfinal, i * 0.1, right));
		i *= 0.1;
	}
	i = 1;
	while (i >= 0.000001){
		printf("%g\t%.20f\n", i, rungekutta(xinit, tinit, tfinal, i, right) / rungekutta(xinit, tinit, tfinal, i * 0.1, right));
		i *= 0.1;
	}
	/*euler(xinit, tinit, tfinal, 0.1, right);
	rungekutta(xinit, tinit, tfinal, 0.1, right);*/

	return 0;
}
