#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, cnt_0, ans;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> virus, active;

void bfs()
{
	int y, x, time;
	queue<tuple<int, int, int>> q;

	int cnt_copy = cnt_0;

	if (cnt_0 == 0)
	{
		ans = 0;
		return;
	}

	visited.assign(N + 2, vector<bool>(N + 2, false));

	for (int i = 0; i < active.size(); ++i)
	{
		q.push({ active[i].first, active[i].second, 0 });
		visited[active[i].first][active[i].second] = true;
	}

	while (!q.empty())
	{
		tie(y, x, time) = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (!visited[y + dy[i]][x + dx[i]] && (map[y + dy[i]][x + dx[i]] == 0 || map[y + dy[i]][x + dx[i]] == 2))
			{
				q.push({ y + dy[i], x + dx[i], time + 1 });
				visited[y + dy[i]][x + dx[i]] = true;
				
				if (map[y + dy[i]][x + dx[i]] == 0 && --cnt_copy == 0)
				{
					while (!q.empty())
						q.pop();

					ans = (ans < time + 1) ? ans : time + 1;
				}
			}
		}
	}
}

void active_virus(int n)
{
	if (active.size() == M)
	{
		bfs();
	}

	for (int i = n; i < virus.size(); ++i)
	{
		active.push_back(virus[i]);
		active_virus(i + 1);
		active.pop_back();
	}
}

int main(void)
{
	cin >> N >> M;

	ans = 2501;
	cnt_0 = 0;
	visited.assign(N + 2, vector<bool>(N + 2, false));
	map.assign(N + 2, vector<int>(N + 2, 1));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 0)
			{
				++cnt_0;
			}

			else if (map[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	active_virus(0);

	if (ans == 2501)
		cout << "-1\n";

	else
		cout << ans << '\n';
}

// 시간 적게 쓰인 소스 : https://www.acmicpc.net/source/32833118
// 분석해 볼 소스 : https://www.acmicpc.net/source/32303370