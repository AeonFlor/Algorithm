#include <iostream>

using namespace std;

bool field[52][52]={false};

void find(int x, int y)
{
	field[x][y]=false;
	
	if(field[x+1][y])
		find(x+1,y);
	if(field[x][y+1])
		find(x,y+1);
	if(field[x-1][y])
		find(x-1,y);
	if(field[x][y-1])
		find(x,y-1);
}

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
					find(k,j);
				}
		
		cout<<ans<<'\n';
	}
}
