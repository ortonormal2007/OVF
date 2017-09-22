#include <iostream>
#include <cmath>

int pres(double a, double b, double eps){
	double n;
	n = (log(((b - a) / eps)) / log(2)) - 1;
	std::cout << "n = " << (int)n << std::endl;
	return (int)n;
}

double pol(double x){
	return (8 * x*x*x + x*x + x - 7);
}

int main(){
	int n;
	double a, b, c;
	c = 0;


	std::cout << "Enter region:" << std::endl << "a = ";
	std::cin >> a;
	std::cout <<  "b = ";
	std::cin >> b;

	n = pres(a, b, 0.001);

	for (int i = 0; i < n; i++){
		if (((pol(a)*pol(c) > 0) && (pol(b)*pol(c) > 0))){
			std::cout << "NO ROOTS!" << std::endl;
			break;
		} 

		c = (a + b) / 2;
		
		if (pol(a)*pol(c) > 0){
			a = c;
		}
		else {
			if (pol(b)*pol(c) > 0){
				b = c;
			}
		}
	}

	std::cout << "a = " << a << "; b = " << b << std::endl << "ans = " << (a + b) / 2 << std::endl;
 
	return 0;
}
