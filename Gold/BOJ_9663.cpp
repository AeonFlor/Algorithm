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

void print()
{
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=N; ++j)
			cout<<board[i][j]<<' ';
		cout<<'\n';
	}
}

int count(int line)
{
	int ans=0;
	
	if(line == N)
	{
		cout<<"CHECK\n";
		return 1;
	}
	
	for(int i=1; i<=N; ++i)
		if(!board[line+1][i])
		{
			setQueen(line+1, i);
			cout<<"SET line "<<line+1<<" at "<<i<<"\n";
			print();
			ans += count(line+1);
			delQueen(line+1, i);
			cout<<"DEL line "<<line+1<<" at "<<i<<"\n";
			print();
		}
	
	return ans;
}

int main(void)
{
	cin>>N;
	
	cout<<count(0)<<'\n';
}
