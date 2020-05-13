#include <cstdio>
#include <algorithm>

using namespace std;

unsigned long long dp[41];

unsigned long long fibonacci(int n)
{
	
	unsigned long long & ret = dp[n];
		
	if(ret!=-1)
		return ret;
	
	ret = 0;
	
	if(n == 0)
		return ret = 1000000000;
	
	else if(n == 1)
		return ret = 1;
	
	else
		return ret = fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
	int T, f;
	fill_n(dp,41,-1);
	
	scanf("%d",&T);
	
	for(int i=0; i<T; ++i)
	{
		scanf("%d", &f);
		
		printf("%lld %lld\n", fibonacci(f)/1000000000, fibonacci(f)%1000000000);
	}
	
	return 0;
}
