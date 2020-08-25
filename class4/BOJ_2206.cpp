#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	// 먼저 (x,y) 에 도달한 건 나중에 도달한 것보다 무조건 빨리 나아감. 따라서 visited 로 메모리 낭비 줄임.
	int map[1002][1002];
	bool visited[1002][1002][2] = {false,};
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	
	queue<tuple<int, int, bool>> q;
	
	int N, M, x, y, input, next_rep, ans = 0, rep = 1;
	bool isbroken, isFind = false;
	
	fill(&map[0][0], &map[1001][1001], 2);
	
	cin>>N>>M;
	
	for(int i=1; i<=N; ++i)
	{
		cin>>input;
		for(int j=M; j>0; --j)
		{
			map[i][j]=input%10;
			input/=10;
		}
	}
	
	/*
	for(int i=0; i<N+2; ++i)
	{
		for(int j=0; j<M+2; ++j)
		{
			cout<<map[i][j];
		}
		cout<<'\n';
	}
	*/
	
	q.push(make_tuple(1,1,false));
	
	while(!q.empty() && !isFind)
	{
		next_rep=0;
		
		while(rep--)
		{
			tie(x, y, isbroken) = q.front();
			q.pop();
			
			//cout<<"Trial "<<ans<<" : ("<<x<<", "<<y<<") - "<<(isbroken)?"True":"False";
			//cout<<'\n';
			
			if(x==N && y==M)
			{
				isFind = true;
				break;
			}

			for(int i=0; i<4; ++i)
			{
				if(!visited[x+dx[i]][y+dy[i]][isbroken] && map[x+dx[i]][y+dy[i]] == 0)
				{
					q.push(make_tuple(x+dx[i],y+dy[i],isbroken));
					visited[x+dx[i]][y+dy[i]][isbroken] = true;
					++next_rep;
				}
				else if(!isbroken && !visited[x+dx[i]][y+dy[i]][1] && map[x+dx[i]][y+dy[i]]==1)
				{
					q.push(make_tuple(x+dx[i],y+dy[i],true));
					visited[x+dx[i]][y+dy[i]][1] = true;
					++next_rep;
				}
			}
		}
		
		rep = next_rep;
		++ans;
	}
	
	if(!isFind)
		cout<<"-1\n";
	else
		cout<<ans<<'\n';
}
