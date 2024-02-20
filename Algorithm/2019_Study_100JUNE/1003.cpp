#include <iostream>

int c0,c1;

int fibonacci(int n, int current, int next)
{
	if(current==0)
		c0++;

	else if(current==1)
		c1++;
	
	if(n==0)
		return current;

	return fibonacci(n-1,next,current+next);
}

int main(void)
{
	int T,c4se;

	std::cin>>T;

	for(int i=0;i<T;i++)
	{
		c0=0;
		c1=0;
		std::cin>>c4se;
		fibonacci(c4se,0,1);
		if(c4se==1)
			c0-=1;
		std::cout<<c0<<" "<<c1<<std::endl;
	}

	return 0;
}