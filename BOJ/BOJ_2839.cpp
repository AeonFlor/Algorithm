#include <iostream>

using namespace std;

int main(void)
{
	int n, cnt, iter;
	bool flag=false;
	
	scanf("%d",&n);
	
	iter=n/5;
	cnt=n/5;
	n%=5;
	
	if(n==0)
		flag=true;
	
	if(!flag)
	{
		for(int i=0; i<=iter;++i)
		{
			if(n%3==0)
			{
				cnt+=n/3;
				flag=true;
				break;
			}
			n+=5;
			--cnt;
		}
	}
	
	if(flag)
		printf("%d",cnt);
	else
		printf("-1");
}
