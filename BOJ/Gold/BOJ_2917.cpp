#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

int N, M, J_x, J_y, V_x, V_y, value, sol;
vector<pair<int,int>> tree;

int minField[502][502];
bool visited[502][502] = {false,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int x, int y, int ans)
{
	if(minField[x][y] == -10000)
		return 0;
	
	priority_queue<tuple<int,int,int>> q;
	
	int minDist = 2500001;
	
	ans = max(ans, minField[x][y]);
	//cout<<"coor("<<x<<","<<y<<") -> ans is "<<ans<<'\n';
	
	for(int i=0; i<4; ++i)
		q.push({-minField[x+dx[i]][y+dy[i]], x+dx[i], y+dy[i]});
	
	while(!q.empty())
	{
		int nextDist, next_x,next_y;
		tie(nextDist, next_x, next_y) = q.top();
		q.pop();
		
		if(visited[next_x][next_y])
			continue;
		
		visited[next_x][next_y] = true;
		
		minDist = min(minDist, nextDist + bfs(next_x, next_y, ans));
	}
	
	sol = ans;
	
	return minDist;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	
	char input;
	fill(&minField[0][0], &minField[501][501], -10000);

	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=M; ++j)
		{
			cin>>input;
			
			if(input=='+')
				tree.push_back({i,j});
			
			else if(input=='J')
			{
				J_x = j;
				J_y = i;
			}
			
			else if(input=='V')
			{
				V_x = j;
				V_y = i;
			}
		}
	}
	
	for(int iter = 0; iter<tree.size(); ++iter)
	{
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=M; ++j)
			{
				value = 1000 - abs(tree[iter].first - i) - abs(tree[iter].second - j);
				
				if(minField[i][j] < value)
					minField[i][j] = value;
			}
	}
	
	bfs(V_x, V_y, -1);

	cout<<1000-sol<<'\n';
}
