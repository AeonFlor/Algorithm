#include <iostream>

using namespace std;

int main(void)
{
	int H,M;
	
	scanf("%d %d",&H,&M);
	
	if(M<45)
	{
		if(--H<0)
			H=23;
		M+=60;
	}
	M-=45;
	
	printf("%d %d",H,M);
}
