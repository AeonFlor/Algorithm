#include <iostream>
#include <vector>

using namespace std;

int n, m, ans, temp, cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> paper;
vector<vector<bool>> visited;

int dfs(int x, int y)
{
	int size = 0;

	visited[x][y] = true;

	for (int k = 0; k < 4; ++k)
	{
		if (x + dx[k] >= n || x + dx[k] < 0 || y + dy[k] >= m || y + dy[k] < 0)
			continue;

		if (paper[x + dx[k]][y + dy[k]] == 1 && !visited[x + dx[k]][y + dy[k]])
		{
			size += dfs(x + dx[k], y + dy[k]);
		}
	}

	return 1 + size;
}

int main(void)
{
	ans = cnt = 0;
	cin >> n >> m;

	paper.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			temp = 0;

			if (paper[i][j] == 1 && !visited[i][j])
			{
				temp = dfs(i, j);
				++cnt;
			}

			ans = (ans > temp) ? ans : temp;
		}
	}

	cout << cnt << '\n' << ans << '\n';
}