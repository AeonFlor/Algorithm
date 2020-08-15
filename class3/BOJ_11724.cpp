#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(1001);
bool visited[1001] = {false,};

void dfs(int n)
{
	visited[n] = true;
	
	for(int i=0; i<adj[n].size(); ++i)
	{
		if(!visited[adj[n][i]])
		{
			dfs(adj[n][i]);
		}
	}
}

int main(void)
{
	int N,M,start,end, ans=0;
	
	cin>>N>>M;
	
	for(int i=0; i<M; ++i)
	{
		cin>>start>>end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	
	for(int i=1; i<=N; ++i)
	{
		if(!visited[i])
		{
			dfs(i);
			++ans;
		}
	}
	
	cout<<ans<<'\n';
}
