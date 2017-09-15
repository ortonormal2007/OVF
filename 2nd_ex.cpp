#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float sum_bl = 0;
	float sum_lb = 0;
	
	float sum_lb_pos = 0;
	float sum_lb_neg = 0;
	float sum_lb_sep = 0;
	
	float sum_bl_pos = 0;
	float sum_bl_neg = 0;
	float sum_bl_sep = 0;
	
	double sum_blD = 0;
	double sum_lbD = 0;

	double sum_lb_posD = 0;
	double sum_lb_negD = 0;
	double sum_lb_sepD = 0;

	double sum_bl_posD = 0;
	double sum_bl_negD = 0;
	double sum_bl_sepD = 0;

	double dbl = 0;
	double dlb = 0;
	double dbl_sep = 0;
	double dlb_sep = 0;


	//FLOAT
	for (int i = 10000; i > 0; i--){
		sum_bl += (pow(-1, i)) / i;
	}

	for (int i = 1; i <= 10000; i++){
		sum_lb += (pow(-1, i)) / i;
	}

	for (int i = 10000; i > 1; i = i - 2){
		sum_bl_pos += (pow(-1, i)) / (i);
	}
	for (int i = 10000; i > 1; i = i - 2){
		sum_bl_neg += (pow(-1, i - 1)) / (i - 1);
	}
	sum_bl_sep = sum_bl_pos + sum_bl_neg;


	for (int i = 2; i <= 10000; i = i + 2){
		sum_lb_pos += (pow(-1, i)) / i;
	}
	for (int i = 2; i <= 10000; i = i + 2){
		sum_lb_neg += (pow(-1, i - 1)) / (i - 1);
	}
	sum_lb_sep = sum_lb_pos + sum_lb_neg;
	
	printf("FLOAT:\n");
	printf("%.20f little to big\n", sum_lb);
	printf("%.20f big to little\n", sum_bl);
	printf("%.20f little to big separatly\n", sum_lb_sep);
	printf("%.20f big to little separatly\n", sum_bl_sep);
	printf("*********************************");
	printf("\n");


	//DOUBLE
	for (int i = 10000; i > 0; i--){
		sum_blD += (pow(-1, i)) / i;
	}

	for (int i = 1; i <= 10000; i++){
		sum_lbD += (pow(-1, i)) / i;
	}

	for (int i = 10000; i > 1; i = i - 2){
		sum_bl_posD += (pow(-1, i)) / (i);
	}
	for (int i = 10000; i > 1; i = i - 2){
		sum_bl_negD += (pow(-1, i - 1)) / (i - 1);
	}
	sum_bl_sepD = sum_bl_posD + sum_bl_negD;


	for (int i = 2; i <= 10000; i = i + 2){
		sum_lb_posD += (pow(-1, i)) / i;
	}
	for (int i = 2; i <= 10000; i = i + 2){
		sum_lb_negD += (pow(-1, i - 1)) / (i - 1);
	}
	sum_lb_sepD = sum_lb_posD + sum_lb_negD;
	
	dbl = sum_bl - sum_blD;

	dlb = sum_lb - sum_lbD;

	dlb_sep = sum_lb_sep - sum_lb_sepD;

	dbl_sep = sum_bl_sep - sum_bl_sepD;





	printf("DOUBLE:\n");
	printf("%.20f little to big\n", sum_lbD);
	printf("%.20f big to little\n", sum_blD);
	printf("%.20f little to big separatly\n", sum_lb_sepD);
	printf("%.20f big to little separatly\n", sum_bl_sepD);
	printf("%.20f little to big\n", dlb);
	printf("%.20f big to little\n", dbl);
	printf("%.20f little to big separatly\n", dlb_sep);
	printf("%.20f big to little separatly\n", dbl_sep);

	return 0;
}
