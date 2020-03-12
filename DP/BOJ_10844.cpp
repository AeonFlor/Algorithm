#include <cstdio>
#include <cstring>

using namespace std;

long long cache[101][10];
int N;

long long count(int index, int n)
{
	long long& ret = cache[index][n];
	
	if(ret!=-1)
		return ret;
	
	if(index==N)
		return ret=1;
	
	if(n==0)
		return ret = count(index+1,n+1)%1000000000;
	
	if(n==9)
		return ret = count(index+1,n-1)%1000000000;
	
	return ret = (count(index+1,n-1)+count(index+1,n+1))%1000000000;
}

int main(void)
{
	long long result=0;

	memset(cache,-1,sizeof(cache));
	
	scanf("%d",&N);
	
	for(int i=1; i<10; ++i)
	{
		result += count(1,i);
	}
	
	printf("%lld", result%1000000000);
	
	return 0;
}
