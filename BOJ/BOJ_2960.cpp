#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	bool prime[n+1];
	
	memset(prime,true,n+1);
	
	for(int j=2; j<n+1; ++j)
		if(prime[j]==true)
		{
			for(int i=j; i<n+1; i+=j)
			{
				if(prime[i]==false)
					continue;
				prime[i]=false;
				if(--k==0)
				{
					printf("%d",i);
					return 0;
				}
			}
		}
}
