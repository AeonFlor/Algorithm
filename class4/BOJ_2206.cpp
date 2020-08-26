#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	// 먼저 (x,y) 에 도달한 건 isbroken 상태가 같다면 나중에 도달한 것보다 무조건 빨리 진행된다.
	int map[1002][1002];
	bool visited[1002][1002][2] = {false,};
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	
    // 각각 x 좌표, y 좌표, 벽을 부순적이 있는지 여부에 해당한다.
	queue<tuple<int, int, bool>> q;
	
    // rep 은 BFS 한 번 확인할 때 큐에 들어가 있는 좌표의 수이다.
    // next_rep 은 이번 rep 에서 큐에 넣은 좌표의 수이다. (1,1) 넣으면 rep 이 1 이므로 미리 초기화했다.
    // isFind 는 (N,M) 에 도착했는지 여부를 확인하는 bool 변수이다.
	int N, M, x, y, input, next_rep, ans = 0, rep = 1;
	bool isbroken, isFind = false;
	
	fill(&map[0][0], &map[1001][1001], 2);
	
	cin>>N>>M;
	
    // 숫자를 붙여서 입력하기에 0,1 중 하나이니 10으로 나눈 나머지로 입력했다.
	for(int i=1; i<=N; ++i)
	{
		cin>>input;
		for(int j=M; j>0; --j)
		{
			map[i][j]=input%10;
			input/=10;
		}
	}
	
    // map 에 잘 들어갔는지 확인하는 부분.
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
	
    // (1,1) 에서 시작하고, 시작하는 부분에 벽이 있으면 깨고 시작해야하므로 조건을 붙여놨다.
	q.push(make_tuple(1,1,map[1][1]==1));
	
	while(!q.empty() && !isFind)
	{
		next_rep=0;
		
		while(rep--)
		{
        	// tie 를 통해 미리 만들어놓은 x, y, isbroken 에 한 번에 값을 넣어줬다.
			tie(x, y, isbroken) = q.front();
			q.pop();
            
            // BFS 진행 과정 확인하기 위해 작성한 부분.
			//cout<<"Trial "<<ans<<" : ("<<x<<", "<<y<<") - "<<(isbroken)?"True":"False";
			//cout<<'\n';
			
			if(x==N && y==M)
			{
				isFind = true;
				break;
			}
			
            // 상하좌우 방문했는지 여부 확인해보고, 해당 부분이 0이라면 push.
            // isbroken 이 false 고, 해당 부분이 1이라면 isbroken 을 true 로 두고 push.
            // visited 를 먼저한 이유는 중복해서 큐에 들어가는 것을 방지하기 위함이다.
			for(int i=0; i<4; ++i)
			{
				if(!visited[x+dx[i]][y+dy[i]][isbroken])
				{
					if(map[x+dx[i]][y+dy[i]] == 0)
					{
						q.push(make_tuple(x+dx[i],y+dy[i],isbroken));
						visited[x+dx[i]][y+dy[i]][isbroken] = true;
						++next_rep;
					}
					else if(!isbroken && !visited[x+dx[i]][y+dy[i]][1] && map[x+dx[i]][y+dy[i]]==1)
					{
						q.push(make_tuple(x+dx[i],y+dy[i],true));
						visited[x+dx[i]][y+dy[i]][1] = true;
						++next_rep;
					}
				}
			}
		}
		
		rep = next_rep;
		++ans;
	}
	
	if(!isFind)
		cout<<"-1\n";
	else
		cout<<ans<<'\n';
}
