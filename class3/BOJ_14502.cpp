#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[11][11];
int map[11][11];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, M, tmp, ans=0;

vector<pair<int, int>> virus, hollow;

void print()
{
	cout<<"\n====="<<tmp<<"=====\n";
	for(int j=0; j<N+2; ++j)
	{
		for(int i=0; i<M+2; ++i)
			cout<<map[i][j]<<' ';
		cout<<'\n';
	}
}

void dfs(int x, int y)
{
	visited[x][y] = true;
	
	for(int j=0; j<4; ++j)
		if(!visited[x+dx[j]][y+dy[j]] && map[x+dx[j]][y+dy[j]] == 0)
		{
			--tmp;
			dfs(x+dx[j], y+dy[j]);
		}
}

int main(void)
{
	fill(&map[0][0], &map[10][10], 1);
	cin>>N>>M;
	
	for(int j=1; j<=N; ++j)
		for(int i=1; i<=M; ++i)
		{
			cin>>map[i][j];
			
			if(map[i][j]==0)
				hollow.push_back(make_pair(i,j));
			
			else if(map[i][j]==2)
				virus.push_back(make_pair(i,j));
		}
	
	for(int i=0; i<hollow.size()-2; ++i)
	{
		map[hollow[i].first][hollow[i].second] = 7;
		for(int j=i+1; j<hollow.size()-1; ++j)
		{
			map[hollow[j].first][hollow[j].second] = 8;
			for(int k=j+1; k<hollow.size(); ++k)
			{
				map[hollow[k].first][hollow[k].second] = 9;
				
				tmp = hollow.size()-3;
				fill(&visited[0][0], &visited[10][10], false);
				
				for(int l=0; l<virus.size(); ++l)
					dfs(virus[l].first, virus[l].second);
			
				ans = max(ans,tmp);
				//if(ans == tmp)
				//	print();
				
				map[hollow[k].first][hollow[k].second] = 0;
			}
			map[hollow[j].first][hollow[j].second] = 0;
		}
		map[hollow[i].first][hollow[i].second] = 0;
	}
	
	cout<<ans<<'\n';
}
