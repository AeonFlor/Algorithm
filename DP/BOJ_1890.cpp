#include <cstdio>
#include <cstring>

using namespace std;

long long cache[101][101];
int plane[101][101];
int N;

long long count(int x, int y)
{
	if(x==N && y==N)
		return 1;
	
	if(x>N || y>N || plane[x][y]==0)
		return 0;
	
	long long& ret = cache[x][y];
	
	if(ret!=-1)
		return ret;
	
	return ret = count(x+plane[x][y],y) + count(x,y+plane[x][y]);
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	
	scanf("%d",&N);
	
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=N; ++j)
			scanf("%d",&plane[i][j]);
	
	printf("%lld", count(1,1));
	
	return 0;
}
