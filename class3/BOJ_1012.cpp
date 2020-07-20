#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, M, N, K, x, y, ans;
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		ans = 0;
		
		cin>>M>>N>>K;
		
		bool field[M+2][N+2]={false};
		
		for(int j=0; j<K; ++j)
		{
			cin>>x>>y;
			field[x+1][y+1]=true;
		}
		
		for(int j=1; j<N+1; ++j)
			for(int k=1; k<M+1; ++k)
				if(field[k][j])
				{
					++ans;
					x=k;
					y=j;
					field[x][y]=false;
					while(field[x-1][y] || field[x+1][y] || field[x][y-1] || field[x][y+1])
					{
						while(field[++x][y] && x<M+1)
							field[x][y]=false;
						while(field[x][++y] && y<N+1)
							field[x][y]=false;
						while(field[--x][y] && x>0)
							field[x][y]=false;
						while(field[x][--y] && y>0)
							field[x][y]=false;
					}
				}
		
		cout<<ans<<'\n';
	}
}
