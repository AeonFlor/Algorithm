#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X, S, E, T, ans=0;
vector<pair<int,int>> adj[1001];
const int INF = 1000001;

vector<int> longest(int src)
{
	priority_queue<pair<int,int>> q;
	vector<int> dist(N+1, INF);
	
	dist[src] = 0;
	q.push(make_pair(0,src));
	
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
			
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				q.push(make_pair(-nextDist, there));
            }
		}
	}
	
	return dist;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M>>X;
	
	while(M--)
	{
		cin>>S>>E>>T;
		adj[S].push_back(make_pair(T,E));
	}
	
	vector<int> XtoN = longest(X);
	
	for(int i=1; i<=N; ++i)
	{
		vector<int> NtoX = longest(i);
		ans = max(ans, NtoX[X] + XtoN[i]);
	}
	
	cout<<ans<<'\n';
}
