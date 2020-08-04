#include <iostream>
#include <vector>

using namespace std;

int v,e;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int n)
{
	int cnt=0;
	visited[n] = true;
	
	for(int i=1; i<adj[n].size(); ++i)
		if(!visited[adj[n][i]])
			cnt=cnt+1+dfs(adj[n][i]);
	
	return cnt;
}

int main(void)
{
	int in, out;
	vector<int> init(1);
	cin>>v>>e;
	
	visited.push_back(false);
	
	for(int i=0; i<v; ++i)
	{
		adj.push_back(init);
		visited.push_back(false);
	}
	
	for(int i=0; i<e; ++i)
	{
		cin>>in>>out;
		adj[in].push_back(out);
		adj[out].push_back(in);
	}
	
	cout<<dfs(1)<<'\n';
}
