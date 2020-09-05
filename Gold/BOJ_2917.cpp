#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, J_x, J_y, V_x, V_y, ans, value;
	vector<pair<int,int>> tree;
	priority_queue<pair<pair<int,int>, pair<int,int>>> q;
	
	int minField[502][502];
	int dist[502][502];
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	
	fill(&minField[0][0], &minField[501][501], -1001);
	fill(&dist[0][0], &dist[501][501], 1000);
	
	cin>>N>>M;
	
	char input;
	
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=M; ++j)
		{
			cin>>input;
			
			if(input=='+')
				tree.push_back({i,j});
			
			else if(input=='J')
			{
				J_x = j;
				J_y = i;
			}
			
			else if(input=='V')
			{
				V_x = j;
				V_y = i;
			}
		}
	}
	
	for(int iter = 0; iter<tree.size(); ++iter)
	{
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=M; ++j)
			{
				value = 1000 - abs(tree[iter].first - i) - abs(tree[iter].second - j);
				
				if(minField[i][j] < value)
					minField[i][j] = value;
			}
	}
	
	dist[V_x][V_y] = minField[V_x][V_y];
	ans = minField[V_x][V_y];
	
	q.push({{ans, -dist[V_x][V_y]},{V_x, V_y}});
	
	while(!q.empty())
	{
		int here_x = q.top().second.first;
		int here_y = q.top().second.second;
		int cost = -q.top().first.second;
		q.pop();
		
		if(here_x == J_x && here_y == J_y)
			break;
		
		else if(dist[here_x][here_y] < cost)
			continue;
		
		for(int i=0; i<4; ++i)
		{
			int thereCost = minField[here_x + dx[i]][here_y + dy[i]];
			
			if(thereCost != -1001)
			{
				if(thereCost + cost < dist[here_x + dx[i]][here_y + dy[i]])
				{
					cout<<"("<<here_x + dx[i]<<", "<<here_y + dy[i]<<") is renewed.\n";
					dist[here_x + dx[i]][here_y + dy[i]] = thereCost + cost;
					if(ans < thereCost)
						ans = thereCost;
					q.push({{thereCost, dist[here_x + dx[i]][here_y + dy[i]]}, {here_x + dx[i],here_y + dy[i]}});
				}
			}
		}
	}
	
	cout<<1000-ans<<'\n';
}
