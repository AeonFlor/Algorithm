#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M;
int plane[1001][1001];
int cache[1001][1001];

int count(int x, int y)
{
	if(x>N || y>M)
		return -99999999;
	
	if(x==N && y==M)
		return plane[x][y];
	
	int & ret = cache[x][y];
	
	if(ret!=-1)
		return ret;
	
	return ret = plane[x][y] + max(max(count(x+1,y), count(x,y+1)), count(x+1,y+1));
}

int main(void)
{
	memset(cache,-1,sizeof(cache));
	
	scanf("%d %d",&N, &M);
	
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
			scanf("%d", &plane[i][j]);
	
	printf("%d", count(1,1));
	
	return 0;
}
