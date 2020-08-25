#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int map[1002][1002];
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	
	queue<vector<pair<pair<int,int>,bool>>> q;
	vector<pair<pair<int,int>,bool>> tmp;
	vector<pair<pair<int,int>,bool>> list;
	
	int N, M, x, y, input, ans = 0;
	bool isbroken, isFind = false;
	
	fill(&map[0][0], &map[1001][1001], 2);
	
	cin>>N>>M;
	
	for(int i=1; i<=N; ++i)
	{
		cin>>input;
		for(int j=M; j>0; --j)
		{
			map[i][j]=input%10;
			input/=10;
		}
	}
	
	/*
	for(int i=0; i<N+2; ++i)
	{
		for(int j=0; j<M+2; ++j)
		{
			cout<<map[i][j];
		}
		cout<<'\n';
	}
	*/
	
	tmp.push_back(make_pair(make_pair(1,1),false));
	q.push(tmp);
	
	while(!q.empty() && !isFind)
	{
		tmp = q.front();
		q.pop();
		
		for(int l=0; l<tmp.size(); ++l)
		{
			x = tmp[l].first.first;
			y = tmp[l].first.second;
			isbroken = tmp[l].second;

			//cout<<"Trial "<<ans<<" : ("<<x<<", "<<y<<") - "<<(isbroken)?"True":"False";
			//cout<<'\n';
			
			if(x==N && y==M)
			{
				isFind = true;
				break;
			}

			for(int i=0; i<4; ++i)
			{
				if(map[x+dx[i]][y+dy[i]] == 0)
					list.push_back(make_pair(make_pair(x+dx[i],y+dy[i]),isbroken));
				else if(!isbroken && map[x+dx[i]][y+dy[i]]==1)
					list.push_back(make_pair(make_pair(x+dx[i],y+dy[i]),true));
			}
		}
		
		if(!list.empty())
			q.push(list);
		list.clear();
		tmp.clear();
		
		++ans;
	}
	
	if(!isFind)
		cout<<"-1\n";
	else
		cout<<ans<<'\n';
}
