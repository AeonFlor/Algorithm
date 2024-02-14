#include <cstdio>
#include <cstring>

using namespace std;

int cache[502][502];
int coor[502][502],M,N;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int count(int x, int y)
{
	int& ret = cache[x][y];
	int result = 0;
	
	if(ret!=-1)
		return ret;
	
	if(x==M && y==N)
		return 1;


	for(int i=0; i<4; ++i)
	{
		if(coor[x][y]>coor[x+dx[i]][y+dy[i]])
			result += count(x+dx[i], y+dy[i]);
	}
	
	return ret=result;
}

int main(void)
{
	memset(coor,10001,sizeof(coor));
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &M, &N);
	
	for(int i=1; i<=M; ++i)
		for(int j=1; j<=N; ++j)
			scanf("%d", &coor[i][j]);
	
	printf("%d", count(1,1));
	
	return 0;
}
