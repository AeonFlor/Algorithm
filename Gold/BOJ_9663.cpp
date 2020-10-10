#include <iostream>

using namespace std;

int board[16][16] = {0,};
int N;

void setQueen(int x, int y)
{
	for(int i=1; i<=N; ++i)
	{
		++board[i][y];
		++board[x][i];
		
		if(y+i <= N)
			++board[x+i][y+i];
		if(y-i > 0)
			++board[x+i][y-i];
	}
	
	--board[x][y];
}

void delQueen(int x, int y)
{
	for(int i=1; i<=N; ++i)
	{
		--board[i][y];
		--board[x][i];
		
		if(y+i <= N)
			--board[x+i][y+i];
		if(y-i > 0)
			--board[x+i][y-i];
	}
	
	++board[x][y];
}

int count(int line)
{
	int ans=0;
	
	if(line == N)
		return 1;
	
	for(int i=1; i<=N; ++i)
		if(!board[line+1][i])
		{
			setQueen(line+1, i);
			ans += count(line+1);
			delQueen(line+1, i);
		}
	
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	cout<<count(0)<<'\n';
}
