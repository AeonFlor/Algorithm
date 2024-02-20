#include <cstdio>
#include <functional>
#include <algorithm>

using namespace std;

int cache[100001];
int arr[100001];
int n;

int count(int index)
{
	int& ret = cache[index];
	int result = 0;
	
	printf("%d : %d\n",index, ret);
	
	if(ret != -100000001)
		return ret;
	
	if(index==n)
		return ret = arr[index];
	
	result = max(max(arr[index],count(index+1)), arr[index]+count(index+1));
}

int main(void)
{
	fill(&cache[0], &cache[0]+sizeof(cache)/sizeof(int),-100000001);
	scanf("%d", &n);
	
	for(int i=1; i<=n; ++i)
		scanf("%d", &arr[i]);
	
	printf("%d", count(1));
	
	return 0;
}
