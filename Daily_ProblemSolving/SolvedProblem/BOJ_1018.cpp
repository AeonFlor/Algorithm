#include <iostream>

using namespace std;

char board[50][50];

int check_diff(int x,int y)
{
	int cnt = 0;
	
	for(int i=x; i<x+8; ++i)
	{
		for(int j=y; j<y+7; ++j)
		{
			if(temp[i][j]==temp[i][j+1])
			{
				if(temp[i][j+1]=='B')
					temp[i][j+1]='W';
				else
					temp[i][j+1]='B';
				cnt++;
				
				cout<<"[L]cnt++ when ("<<i<<","<<j<<")\n";
			}
		}
		if(i<x+7 && temp[i][y+7]!=temp[i+1][y])
		{
			if(temp[i+1][y]=='B')
				temp[i+1][y]='W';
			else
				temp[i+1][y]='B';
			cnt++;
			
			cout<<"[N]cnt++ when ("<<i+1<<","<<y<<")\n";
		}
	}
	
	if(cnt>32)
		cnt=64-cnt;
	
	return cnt;
}

int main(void)
{
	int N,M,min=64,tmp;
	cin>>N>>M;
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin>>board[i][j];
	
	for(int i=0; i<N-7; ++i)
		for(int j=0; j<M-7; ++j)
		{
			tmp=check_diff(i,j);
			cout<<"("<<i<<","<<j<<") -> "<<tmp<<'\n';
			if(min>tmp)
				min=tmp;
		}
	
	cout<<min<<'\n';
	
	return 0;
}
