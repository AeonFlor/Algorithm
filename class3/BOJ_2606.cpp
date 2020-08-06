#include <iostream>

using namespace std;

int v,e;
bool adj[101][101] = {false};
bool visited[101] = {false};

int dfs(int n)
{
	int cnt=0;
	visited[n] = true;
	
	for(int i=1; i<=v; ++i)
		if(!visited[i] && adj[n][i])
			cnt=cnt+1+dfs(i);
	
	return cnt;
}

int main(void)
{
	int in, out;
	cin>>v>>e;
	
	for(int i=0; i<e; ++i)
	{
		cin>>in>>out;
		adj[in][out]=adj[out][in]=true;
	}
	
	cout<<dfs(1)<<'\n';
}
