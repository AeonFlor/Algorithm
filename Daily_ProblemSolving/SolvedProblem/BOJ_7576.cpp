#include <iostream>
#include <queue>

using namespace std;

int M,N,cnt=0,ans=0, x, y;
int box[1002][1002];
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

int main(void)
{
	
	queue<vector<pair<int,int>>> q;
	vector<pair<int,int>> coor;
	vector<pair<int,int>> temp;
	
	fill(&box[0][0], &box[1001][1001],-1); // 이거 때문
	cin>>M>>N;
	
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
		{
			cin>>box[j][i];
			
			if(box[j][i]==0)
				++cnt;
			else if(box[j][i]==1)
				coor.push_back(make_pair(j,i));
		}
	
	print();
	
	q.push(coor);
	
	while(!q.empty())
	{
		coor.clear();
		coor = q.front();
		q.pop();
		cout<<"coor size is "<<coor.size()<<'\n';
		for(int i=0; i<coor.size(); ++i)
			for(int j=0; j<4; ++j)
			{
				x = coor[i].first;
				y = coor[i].second;
				if(box[x+dx[j]][y+dy[j]]==0)
				{
					box[x+dx[j]][y+dy[j]] = 1;
					temp.push_back(make_pair(x+dx[j], y+dy[j]));
					--cnt;
				}
			}
		
		if(!temp.empty())
			q.push(temp);
		temp.clear();
		++ans;
		
		//print();
	}
	
	if(cnt)
		cout<<"-1\n";
	else
		cout<<ans-1<<'\n';
	
}
