#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, S, D, U, V, P;
const int INF = 10000001;
vector<pair<int, int>> adj[500];
vector<int> distPrior;
vector<int> ParentPrior;

void almost_shotest(int size, int src)
{
	vector<int> dist(size, INF);
	vector<int> Parent(size, -1);
	priority_queue<pair<int,int>> q;
	
	dist[src] = 0;
	q.push(make_pair(0,src));
	
	while(!q.empty())
	{
		int here = q.top().second;
		int cost = -q.top().first;
		q.pop();
		
		//cout<<here<<", "<<cost<<'\n';
		
		if(dist[here] < cost)
			continue;
		
		for(int i=0; i<adj[here].size(); ++i)
		{
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			
			if(nextDist < dist[there])
			{
				dist[there] = nextDist;
				q.push(make_pair(-nextDist, there));
				Parent[there] = here;
			}
		}
	}
	
	distPrior = dist;
	ParentPrior = Parent;
}

void eraseEdge()
{
	// 같은 거리인 것들 다 없앰.
	//cout<<"END POINT : "<<distPrior[D]<<'\n';
	
	int parent, child = D;
	
	while(ParentPrior[child] != -1)
	{
		parent = ParentPrior[child];
		//cout<<"[START]\n";
		for(int i=0; i<adj[parent].size(); ++i)
		{
			// 최대 1개이므로 지워도 이렇게 찾아도 됨.
			if(adj[parent][i].second == child)
			{
				//cout<<"[Erase] "<<parent<<" -> "<<child<<'\n';
				adj[parent].erase(adj[parent].begin()+i);
				continue;
			}
		}
		
		child = parent;
	}
	
	almost_shotest(N, S);
}

int main(void)
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	while(cin>>N>>M && (N||M))
	{
		cin>>S>>D;
		
		while(M--)
		{
			cin>>U>>V>>P;
			adj[U].push_back(make_pair(P,V));
		}

		almost_shotest(N, S);
		int value = distPrior[D];
		
		while(distPrior[D]==value)
		{
			eraseEdge();
			//cout<<"ERASE COMPLETE\n";
		}	
		
		if(distPrior[D] != INF)
			cout<<distPrior[D]<<'\n';
		else
			cout<<"-1\n";
		
		for(int i=0; i<N; ++i)
			adj[i].clear();
	}
}

// 같은 거리인 거 잘 안 없어지는 듯.
