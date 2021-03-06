#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int cache[10001];
int coin[101], n, k;

int count(int remainder)
{
	int& ret = cache[remainder];
	printf("ret --before: %d\n",ret);
	if(remainder==0)
		return ret = 0;
	
	if(remainder<coin[n])
		return ret = 10001;
	
	printf("ret : %d\n",ret);
	if(ret!=10002)
		return ret;
	
	printf("check\n");
	
	for(int i=1; i<=n; ++i)
	{
		if(coin[i]>remainder)
			continue;
		
		printf("%d - %d = %d\n",remainder,coin[i],remainder-coin[i]);
		ret = min(ret, 1+count(remainder-coin[i]));
		printf("ret : %d\n",ret);
	}
	
	return ret;
}

int main(void)
{
	int result;
	scanf("%d %d",&n, &k);
	
	for(int i=1; i<=n; ++i)
		scanf("%d",&coin[i]);
	
	sort(coin+1, coin+n+1, greater<int>());
	
	fill_n(cache,10001,10002);
	
	for(int i=0; i<10; ++i)
		printf("%d\n",cache[i]);
	
	result = count(k);
	
	if(result>10000)
		result=-1;
	
	printf("%d",result);
	
	return 0;
}
