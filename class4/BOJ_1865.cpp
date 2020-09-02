#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> adj[501];
int TC, N, M, W;
const int INF = 25000001;

bool bellmanFord()
{
	vector<int> upper(N+1, INF);
	
	upper[1] = 0;
	bool update;
	
	for(int iter=0; iter<N; ++iter)
	{
		update = false;
		for(int here=1; here<=N; ++here)
		{
			for(int i=0; i<adj[here].size(); ++i)
			{
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				
				//cout<<"Compare "<<there<<"("<<upper[there]<<") and "<<here<<"("<<upper[here]+cost<<")\n";
				
				if(upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					update = true;
					//cout<<"[Updated] "<<here<<" -> "<<there<<'\n'; 
				}
			}
		}
		if(!update)
			break;
	}
	
	if(update)
		return true;
	
	else
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>TC;
	
	while(TC--)
	{
		for(int i=0; i<501; ++i)
			adj[i].clear();
		
		int S, E, T;
		
		cin>>N>>M>>W;
		
		while(M--)
		{
			cin>>S>>E>>T;
			adj[S].push_back(make_pair(E,T));
			adj[E].push_back(make_pair(S,T));
		}
		
		while(W--)
		{
			cin>>S>>E>>T;
			adj[S].push_back(make_pair(E,-T));
		}
		
		if(bellmanFord())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
