#include <cstdio>
#include <functional>

using namespace std;

int cache[501][501];
int coor[501][501], M, N;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int count(int x, int y)
{
	int& ret = cache[x][y];
	int result = 0;
	
	if(ret != -1)
		return ret;
	
	if(x==N && y==M)
		return 1;
	
	for(int i=0; i<4; ++i)
	{
		if(coor[x][y] > coor[x+dx[i]][y+dy[i]])
			result += count(x+dx[i], y+dy[i]);
		printf("%d(%d,%d) -> %d(%d,%d) : %d\n",coor[x][y],x,y,coor[x+dx[i]][y+dy[i]],x+dx[i],y+dy[i],result);
	}
	
	return ret = result;
}

int main(void)
{
	fill(&coor[0][0], &coor[0][0]+sizeof(coor)/sizeof(int),501);
	fill(&cache[0][0], &cache[0][0]+sizeof(cache)/sizeof(int),-1);
	
	scanf("%d %d",&M, &N);
	
	for(int i=1; i<=M; ++i)
		for(int j=1; j<=N; ++j)
			scanf("%d", &coor[i][j]);
	
	printf("%d", count(1,1));
	
	return 0;
}

/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
*/
