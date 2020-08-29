#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E, source, u, v, w;
int here, closest, there, nextDist;

vector<pair<int,int>> graph[20001];
vector<int> dist(20001,3000001);
priority_queue<pair<int,int>> q;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E;
	cin>>source;
	
	while(E--)
	{
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
	}
	
	dist[source] = 0;
	q.push(make_pair(0,source));
	
	while(!q.empty())
	{
		here = q.top().second;
		closest = -q.top().first;
		q.pop();
		
		if(closest > dist[here])
			continue;
		
		for(int i=0; i<graph[here].size(); ++i)
		{
			there = graph[here][i].first;
			nextDist = closest + graph[here][i].second;
			
			if(nextDist < dist[there])
			{
				dist[there] = nextDist;
				q.push(make_pair(-nextDist, there));
			}
		}
	}
	
	for(int i=1; i<=V; ++i)
	{
		if(dist[i]==3000001)
			cout<<"INF\n";
		else
			cout<<dist[i]<<'\n';
	}
}
