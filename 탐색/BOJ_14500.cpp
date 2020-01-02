#include <iostream>
#include <vector>

using namespace std;

int n, m;

int shape_sum(vector<vector<int>>&board, int x, int y)
{
	int max=-1;
	int scene[19]={0,};
	
	if(y+3<n)
		scene[0] = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+3][x];
	if(x+3<m)
		scene[1] = board[y][x] + board[y][x+1] + board[y][x+2] + board[y][x+3];
	
	if(y+1<n && x+1<m)
		scene[2] = board[y][x] + board[y+1][x] + board[y][x+1] + board[y+1][x+1];
	if(y+2<n && x+1<m)
		scene[3] = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+2][x+1];
	
	if(y+2<n && x-1>0)
		scene[4] = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+2][x-1];
	if(y+1<n && x+2<m)
		scene[5] = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+2];
	if(y+1<n && x+2<m)
		scene[6] = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x];
	if(y+2<n && x+1<m)
		scene[7] = board[y][x] + board[y][x+1] + board[y+1][x] + board[y+2][x];
	if(y+2<n && x+1<m)
		scene[8] = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+2][x+1];
	if(y+1<n && x+2<m)
		scene[9] = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+1][x+2];
	if(y-1>0 && x+2<m)
		scene[10] = board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+2];
	
	if(y+2<n && x+1<m)
		scene[11] = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x+1];
	if(y+2<n && x-1>0)
		scene[12] = board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+2][x-1];
	if(y+1<n && x+2<m)
		scene[13] = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+1][x+2];
	if(y-1>0 && x+2<m)
		scene[14] = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y-1][x+2];
	
	if(y+2<n && x+1<m)
		scene[15] = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x];
	if(y+2<n && x-1>0)
		scene[16] = board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+2][x];
	if(y-1>0 && x+2<m)
		scene[17] = board[y][x] + board[y-1][x+1] + board[y][x+1] + board[y][x+2];
	if(y+1<n && x+2<m)
		scene[18] = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y][x+2];
	
	for(int i=0; i<19; ++i)
		if(max<scene[i])
			max=scene[i];
	
	return max;
}

int main(void)
{
	int i, j, max=-1,temp;
	
	scanf("%d %d",&n, &m);
	
	vector<vector<int>> board(n, vector<int>(m,0));
	
	for(i=0; i<n; ++i)
		for(j=0; j<m; ++j)
			scanf("%d",&board[i][j]);
	
	for(i=0; i<n; ++i)
		for(j=0; j<m; ++j)
		{
			temp = shape_sum(board,i,j);
			if(temp>max)
				max=temp;
		}
	
	printf("%d",max);
}
