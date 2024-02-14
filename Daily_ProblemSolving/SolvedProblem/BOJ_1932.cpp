#include <cstdio>
#include <algorithm>

using namespace std;

int tri[501][501];
int dp[501][501];

int n;

int max_tri(int line, int index)
{
	if(line == n)
		return tri[line][index];
	
	if(index > line)
		return 0;
	
	int & ret = dp[line][index];
	
	if(ret != -1)
		return ret;
	
	return ret = tri[line][index]+max(max_tri(line+1,index),max_tri(line+1,index+1));
}

int main(void)
{
	fill_n(&dp[0][0], 501*501, -1);
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<i; ++j)
			scanf("%d",&tri[i][j]);
	
	printf("%d",max_tri(0,0));
	
	return 0;
}  

/*
Test Case

1. 예제
2. 삼각형 크기가 1인 경우
3. 직접 만들어본 예제
*/
