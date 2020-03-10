#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001];

int count(int n)
{
	int& ret = cache[n];
	
	if(ret != -1)
		return ret;
	
	if(n==0 || n==1)
		return ret = 1;
	
	return ret = (2*count(n-2)+count(n-1))%100000;
}

int main(void)
{
	int n;
	
	memset(cache,-1,sizeof(cache));
	
	scanf("%d", &n);
	printf("%d\n",count(n)%10007);
	
	return 0;
}
