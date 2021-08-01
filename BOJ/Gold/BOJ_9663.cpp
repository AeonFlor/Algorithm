#include <iostream>

using namespace std;

int N;
int board[16];

int count(int line)
{
	if(line == N)
		return 1;
	
	int ans=0;
	
	for(int i=0; i<N; ++i)
	{
		bool flag=false;
		
		for(int j=0; j<line; ++j)
			if(board[j] == i || board[j] - (line-j) == i || board[j] + (line-j) == i)
			{
				flag = true;
				break;
			}
		
		if(!flag)
		{
			board[line] = i;
			ans += count(line+1);
		}
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
