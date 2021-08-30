#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<char>> field;
vector<vector<bool>> visited;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N, M, w_power, b_power;

int dfs(int x, int y, bool isW)
{
	int cnt = 0;
	
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
			continue;

		if (!visited[y + dy[i]][x + dx[i]])
		{
			if (isW && field[y + dy[i]][x + dx[i]] == 'W')
					cnt += dfs(x + dx[i], y + dy[i], isW);

			else if (!isW && field[y + dy[i]][x + dx[i]] == 'B')
				cnt += dfs(x + dx[i], y + dy[i], isW);
		}
	}

	return 1 + cnt;
}

int main(void)
{
	cin >> N >> M;

	field.assign(M, vector<char>(N));
	visited.assign(M, vector<bool>(N, false));

	w_power = b_power = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[i][j])
			{
				if (field[i][j] == 'W')
				{
					w_power += pow(dfs(j, i, true), 2);
				}

				else
				{
					b_power += pow(dfs(j, i, false), 2);
				}
			}
		}
	}

	cout << w_power << ' ' << b_power << '\n';
}