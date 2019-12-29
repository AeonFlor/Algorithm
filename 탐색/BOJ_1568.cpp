#include <iostream>

int main(void)
{
	int n,time=0,rt=1;
	
	scanf("%d",&n);
	
	while(n!=0)
	{
		n-=rt++;
		if(n<rt)
			rt=1;
		++time;
	}
	
	printf("%d",time);
}
