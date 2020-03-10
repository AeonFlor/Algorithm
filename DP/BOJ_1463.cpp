#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[1000001];

int count(int n)
{
	int& ret = cache[n];
	
	if(ret != -1)
		return ret;
	if(n == 1)
		return ret=0;
	
	int d3,d2,m1;
	d3=d2=m1=1000001;
	
	if(n % 3 == 0 && n > 2)
		d3 = count(n/3);
	
	if(n % 2 == 0 && n > 1)
		d2 = count(n/2);
	
	m1 = count(n-1);
	
	return ret = 1 + min(m1,min(d2,d3));
}

int main(void)
{
	int x;
	memset(cache, -1, sizeof(cache));
	scanf("%d",&x);
	printf("%d\n",count(x));
	return 0;
}
