#include <cstdio>
#include <cstring>

using namespace std;

long long cache[91];
int N;

long long count( int index )
{
	long long& ret = cache[index];
	if(ret!=-1)
		return ret;
	
	if(index==N)
		return 2;
	
	if(index+2>N)
		return ret = count(index+1)+1;
	
	return ret = count(index+1) + count(index+2);
}

int main(void)
{
	memset(cache,-1,sizeof(cache));
	scanf("%d",&N);
	
	if(N<3)
		printf("1\n");
	
	else
		printf("%lld\n",count(3));
	
	return 0;
}
