#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float sum_bl = 0;
	float sum_lb = 0;
	float sum_lb_pos = 0;
	float sum_lb_neg = 0;
	float sum_bl_sep = 0;

	for (int i = 10000; i > 0; i--){
		sum_bl += (pow(-1, i)) / i;
	}

	for (int i = 1; i <= 10000; i++){
		sum_lb += (pow(-1, i))/i;
	}

	for (int i = 2; i <= 10000; i = i + 2){
		sum_lb_pos += (pow(-1, i)) / i;
	}
	for (int i = 1; i < 10000; i = i + 2){
		sum_lb_neg += (pow(-1, i)) / (i);
	}

	for (int i = 10000; i > 1; i = i - 2){
		sum_bl_sep += (pow(-1, i - 1)) / (i - 1);
		sum_bl_sep += (pow(-1, i)) / i;
	}

	printf("little to big: %f\n", sum_bl);
	printf("big to little: %f\n", sum_lb);
	printf("little to big separatly: %f\n", sum_lb_sep);
	printf("big to little separatly: %f\n", sum_bl_sep);

	return 0;
}
