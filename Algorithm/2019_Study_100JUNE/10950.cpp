#include <iostream>

int main(void)
{
	int T,a,b;
	
	std::cin>>T;
	for(int i=0; i<T; i++)
	{
		std::cin>>a>>b;
		std::cout<<a+b<<std::endl;
	}
	return 0;
}