#include <cstdio>
#include <cstring>

using namespace std;

long long cache[1001][10];
long long N;

long long count(int index, int n)
{
	long long& ret = cache[index][n];
	int rtn;
	
	if(ret!=-1)
		return ret;
	
	if(index==N)
		return ret=1;
	
	rtn=0;
	
	for(int i=n; i<10; ++i)
	{
		rtn += count(index+1,i)%10007;
		//printf("count(%d,%d) : %lld     -> rtn : %d\n",index+1,i,count(index+1,i),rtn); // 확인용!
	}
	
	return ret = rtn;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	
	scanf("%lld", &N);
	
	printf("%lld\n", count(0,0)%10007);
	
	return 0;
}
