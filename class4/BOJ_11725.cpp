#include <iostream>
#include <vector>

using namespace std;

int N, s, e;
vector<vector<int>> tree(100000);
int parent[100001] = {0};

void link(int node)
{
	for(int i=0; i<tree[node].size(); ++i)
	{
		if(tree[node][i] != parent[node])
		{
			parent[tree[node][i]] = node;
			link(tree[node][i]);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	
	for(int i=1; i<N; ++i)
	{
		cin>>s>>e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	
	link(1);
	
	for(int i=2; i<=N; ++i)
		cout<<parent[i]<<'\n';
}
