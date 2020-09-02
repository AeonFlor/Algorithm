#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> adj[1001];
vector<int> via(1001, -1);
int N, M, A, B, C;

void circuit()
{
	vector<int> dist(1001, 10000001);
	priority_queue<pair<int,int>> q;
	
	dist[1] = 0;
	q.push(make_pair(0,1));
	
	while(!q.empty())
	{
		int here = q.top().second;
		int cost = -q.top().first;
		q.pop();
		
		if(dist[here] < cost)
			continue;
		
		for(int i=0; i<adj[here].size(); ++i)
		{
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			
			if(nextDist < dist[there])
			{
				dist[there] = nextDist;
				via[there] = here;
				q.push(make_pair(-nextDist, there));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int,int>> ans;
	
	cin>>N>>M;
	
	while(M--)
	{
		cin>>A>>B>>C;
		
		adj[A].push_back(make_pair(C,B));
		adj[B].push_back(make_pair(C,A));
	}
	
	circuit();
	
	for(int i=1; i<=N; ++i)
		if(via[i] != -1)
			ans.push_back(make_pair(i,via[i]));
	
	cout<<ans.size()<<'\n';
	
	for(int i=0; i<ans.size(); ++i)
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}
