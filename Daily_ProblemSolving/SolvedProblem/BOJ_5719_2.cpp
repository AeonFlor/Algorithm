#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, S, D, U, V, P;
const int INF = 10000001;
vector<pair<int, int>> adj[500];
priority_queue<pair<int,int>> Parent[500];

int almost_shotest(int size, int src)
{
	vector<int> dist(size, INF);
	priority_queue<pair<int,int>> q;
	
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
			
			if(nextDist <= dist[there])
			{
				dist[there] = nextDist;
				q.push(make_pair(-nextDist, there));
				Parent[there].push(make_pair(-nextDist, here));
			}
		}
	}
	
	return dist[D];
}

void eraseEdge(int child, int min_dist)
{
	vector<int> list;
	
	while(!Parent[child].empty())
	{
		if(-Parent[child].top().first == min_dist)
		{
			int parent = Parent[child].top().second;
			for(int i=0; i<adj[parent].size(); ++i)
			{
				if(adj[parent][i].second == child)
				{
					adj[parent].erase(adj[parent].begin()+i);
					list.push_back(parent);
					break;
				}
			}
		}
		
		Parent[child].pop();
	}
		
	for(int i=0; i<list.size(); ++i)
		if(list[i]!=S)
			eraseEdge(list[i], -Parent[list[i]].top().first);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(cin>>N>>M && (N||M))
	{
		cin>>S>>D;
		
		while(M--)
		{
			cin>>U>>V>>P;
			adj[U].push_back(make_pair(P,V));
		}
		
		eraseEdge(D, almost_shotest(N, S));
		
		int ans = almost_shotest(N, S);
		
		if(ans != INF)
			cout<<ans<<'\n';
		else
			cout<<"-1\n";
		
		for(int i=0; i<N; ++i)
		{
			adj[i].clear();
			
			while(!Parent[i].empty())
				Parent[i].pop();
		}
	}
}
