#include <iostream>

int main(void)
{
	int iter;
	int n, k;
	int iter_n, iter_k;
	
	int cache[101][100][2];
	
	cache[1][0][1] = 1; // 1
	cache[1][0][0] = 1; // 0
	
	for(iter_k=0; iter_k<100; ++iter_k)
		for(iter_n=2; iter_n < 101; ++iter_n)
		{
			if(iter_k==0)
				cache[iter_n][iter_k][1] += cache[iter_n-1][iter_k][0];
			else
				cache[iter_n][iter_k][1] += cache[iter_n-1][iter_k][0] + cache[iter_n-1][iter_k-1][1];
			
			cache[iter_n][iter_k][0] += cache[iter_n-1][iter_k][0] + cache[iter_n-1][iter_k][1];
		}
	
	scanf("%d",&iter);
	
	while(iter--)
	{
		scanf("%d %d",&n,&k);
		
		printf("%d\n",cache[n][k][0]+cache[n][k][1]);
	}
}
