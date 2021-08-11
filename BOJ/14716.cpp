#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

vector<vector<int>> banner;
vector<vector<bool>> visited;

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int k = 0; k < 8; ++k)
	{
		if (y + dy[k] < 0 || y + dy[k] == M || x + dx[k] < 0 || x + dx[k] == N)
			continue;

		if (banner[y + dy[k]][x + dx[k]] == 1 && !visited[y + dy[k]][x + dx[k]])
			dfs(y + dy[k], x + dx[k]);
	}
}

int dfsAll()
{
	int ans = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (banner[i][j] == 1 && !visited[i][j])
			{
				dfs(i, j);
				++ans;
			}
		}
	}

	return ans;
}

int main(void)
{
	cin >> M >> N;

	banner.assign(M, vector<int>(N, 0));
	visited.assign(M, vector<bool>(N, false));

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> banner[i][j];
		}
	}

	cout << dfsAll() << '\n';
}