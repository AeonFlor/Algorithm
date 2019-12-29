#include <iostream>

using namespace std;

int main(void)
{
	int ave=0 ,n;
	
	for(int i=0; i<5; ++i)
	{
		scanf("%d",&n);
		if(n<40) n=40;
		ave+=n;
	}
	
	printf("%d",ave/5);
}
