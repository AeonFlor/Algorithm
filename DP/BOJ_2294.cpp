#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int cache[101][10001];
int coin[101], n, k;

int count(int index, int remainder)
{
	int& ret = cache[index][remainder];
	
	if(ret!=10001)
		return ret;
	
	if(remainder==0)
		return ret = 0;
	
	if(remainder<coin[n])
		return ret = 10001;
	
	for(int i=index; i<=n; ++i)
	{
		if(coin[i]>remainder)
			continue;
		
		ret = min(ret, 1+count(i, remainder-coin[i]));
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
	
	fill(&cache[0][0], &cache[0][0] + sizeof(cache)/sizeof(int), 10001);
	
	result = count(1,k);
	
	if(result>10000)
		result=-1;
	
	printf("%d",result);
	
	return 0;
}
