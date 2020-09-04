#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int N, M, J_x, J_y, V_x, V_y, ans;
	vector<pair<int,int>> tree;
	priority_queue<pair<int, pair<int,int>>> q;
	
	char field[502][502];
	int minField[502][502];
	int dist[502][502];
	
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	
	fill(&field[0][0], &field[501][501], 'x');
	fill(&minField[0][0], &minField[501][501], -1001);
	fill(&dist[0][0], &dist[501][501], 1000);
	
	cin>>N>>M;
	
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=M; ++j)
		{
			cin>>field[i][j];
			
			if(field[i][j]=='+')
				tree.push_back({i,j});
			
			else if(field[i][j]=='J')
			{
				J_x = j;
				J_y = i;
			}
			
			else if(field[i][j]=='V')
			{
				V_x = j;
				V_y = i;
			}
		}
	}
	
	for(int iter = 0; iter<tree.size(); ++iter)
	{
		//cout<<"[Transformation] "<<tree[iter].first<<", "<<tree[iter].second<<'\n';
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=M; ++j)
			{
				int value = 1000 - abs(tree[iter].first - i) - abs(tree[iter].second - j);
				//cout<<value<<" and "<<minField[i][j]<<'\n';
				if(minField[i][j] < value)
					minField[i][j] = value;
			}
	}
	
	/*
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=M; ++j)
		{
			cout<<minField[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	
	dist[V_x][V_y] = minField[V_x][V_y];
	ans = minField[V_x][V_y];
	
	q.push({-dist[V_x][V_y],{V_x, V_y}});
	
	while(!q.empty())
	{
		int here_x = q.top().second.first;
		int here_y = q.top().second.second;
		int cost = -q.top().first;
		q.pop();
		
		if(dist[here_x][here_y] < cost)
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
					q.push({thereCost + cost, {here_x + dx[i],here_y + dy[i]}});
				}
			}
		}
	}
	
	cout<<1000-ans<<'\n';
}
