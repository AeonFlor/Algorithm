#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int adj[101][101];

void floyd()
{
	for(int i=1; i<=n;++i)
		adj[i][i] = 0;
	
	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	const int INF = 1000000000;
	fill(&adj[0][0], &adj[100][100], INF);
	
	int a, b, c;
	cin>>n>>m;
	
	while(m--)
	{
		cin>>a>>b>>c;
		if(adj[a][b] > c)
			adj[a][b] = c;
	}
	
	floyd();	
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(adj[i][j]!= INF)
				cout<<adj[i][j]<<' ';
			else
				cout<<"0 ";
		}
		
		cout<<'\n';
	}
}
