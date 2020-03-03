#include <iostream>
#include <cmath>

int main(void)
{
	double pi = M_PI;
	double radius;
	
	scanf("%lf",&radius);
	
	printf("%.5lf\n",pi*radius*radius);
	printf("%.5lf",2*radius*radius);
}
