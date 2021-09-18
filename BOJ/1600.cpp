#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;

int knight_dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int knight_dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

int main(void)
{
	int ans = -1;
	int y, x, jump, time;

	cin >> K >> W >> H;

	map.assign(H + 1, vector<int>(W + 1, 1));
	visited.assign(H + 1, vector<vector<bool>>(W + 1, vector<bool>(K + 1, false)));

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			cin >> map[i][j];
		}
	}

	queue<tuple<int, int, int, int>> q;

	q.push({ 1, 1, 0, 0 });
	visited[1][1][0] = true;

	while (!q.empty())
	{
		tie(y, x, jump, time) = q.front();
		q.pop();

		if (y == H && x == W)
		{
			ans = time;
			break;
		}

		if (jump < K)
		{
			for (int i = 0; i < 8; ++i)
			{
				if (y + knight_dy[i] < 1 || y + knight_dy[i] > H || x + knight_dx[i] < 1 || x + knight_dx[i] > W)
				{
					continue;
				}

				if (!visited[y + knight_dy[i]][x + knight_dx[i]][jump+1] && map[y + knight_dy[i]][x + knight_dx[i]] != 1)
				{
					visited[y + knight_dy[i]][x + knight_dx[i]][jump+1] = true;
					q.push({ y + knight_dy[i], x + knight_dx[i], jump + 1, time + 1});
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			if (y + dy[i] < 1 || y + dy[i] > H || x + dx[i] < 1 || x + dx[i] > W)
			{
				continue;
			}

			if (!visited[y + dy[i]][x + dx[i]][jump] && map[y + dy[i]][x + dx[i]] != 1)
			{
				visited[y + dy[i]][x + dx[i]][jump] = true;
				q.push({ y + dy[i], x + dx[i], jump, time + 1});
			}
		}
	}

	
	cout << ans << '\n';
}

//canJump 라는 boolean 변수로 visited 으로 점프할 수 있는지만 확인했는데, jump 횟수가 적은게 후에 도달할 수도 있으니 jump 가능 여부가 아닌 jump 횟수로 확인했다.