#include <iostream>

int main(void)
{
	int n, vote, cnt=0;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&vote);
		cnt += vote;
	}
	
	if(cnt>n/2)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
}
