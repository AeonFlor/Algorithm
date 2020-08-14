#include <iostream>
#include <algorithm>

using namespace std;

int M,N,cnt=0,ans=0;
int box[1002][1002];
bool visited[1002][1002];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void print()
{
	for(int i=0; i<=N+1; ++i)
	{
		for(int j=0; j<=M+1; ++j)
		{
			cout.fill(' ');
			cout.width(2);
			cout<<box[j][i]<<' ';
		}
		cout<<'\n';
	}
	
	cout<<"=====================\n";
}

int simulate()
{
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
			if(box[j][i]==0 && box[j+1][i] + box[j][i+1] + box[j-1][i] + box[j][i-1] == -4)
				return -1;
				
	while(cnt>0)
	{
		fill(&visited[0][0],&visited[1001][1001],false);
		
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=M; ++j)
				if(!visited[j][i] && box[j][i]==1)
					for(int k=0; k<4; ++k)
						if(!visited[j+dx[k]][i+dy[k]] && box[j+dx[k]][i+dy[k]]==0)
						{
							visited[j+dx[k]][i+dy[k]] = true;
							box[j+dx[k]][i+dy[k]]=1;
							--cnt;
						}
		//print();
		++ans;
	}
	
	return ans;
}

int main(void)
{
	fill(&box[0][0], &box[1001][1001],-1);
	cin>>M>>N;
	
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
		{
			cin>>box[j][i];
			if(box[j][i]==0)
				++cnt;
		}
	
	//print();
	
	cout<<simulate()<<'\n';
}
