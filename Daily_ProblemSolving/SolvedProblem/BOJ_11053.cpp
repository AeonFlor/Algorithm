#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[1001][1001], A[1001];
int N;

int count(int index, int n)
{
	int& ret=cache[index][n];
	
	if(ret!=0)
		return ret;
	
	if(index==N)
		return ret = (A[index]>n);
	
	if(A[index]>n)
		return ret = max(1+count(index+1,A[index]), count(index+1,n));
	
	return ret = count(index+1, n);
}

int main(void)
{
	memset(cache,0,sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i=1; i<=N; ++i)
		scanf("%d",&A[i]);
	
	printf("%d",count(1,0));
	
	return 0;
}
