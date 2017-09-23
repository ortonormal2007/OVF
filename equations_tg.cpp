#include <iostream>
#include <cmath>

double fi(double x) {
	return tan(x);
}

void simp_iter(){
	//int n = 
	double z, z0;
	double eps = 0.001;
	std::cin >> z; 
	while (abs(z - z0) > eps){
		z0 = z;
		z = fi(z);
	}
}

int main(){

	return 0;
}
