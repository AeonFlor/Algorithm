#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> field, melt;
vector<vector<bool>> visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void meltdown(void)
{
	int cnt;

	for (int i = 1; i < N-1; ++i)
	{
		for (int j = 1; j < M-1; ++j)
		{
			cnt = 0;

			for (int k = 0; k < 4; ++k)
			{
				if (field[i + dy[k]][j + dx[k]] == 0)
					++cnt;
			}

			melt[i][j] -= cnt;

			if (melt[i][j] < 0)
				melt[i][j] = 0;
		}
	}
}

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int k = 0; k < 4; ++k)
	{
		if (!visited[y + dy[k]][x + dx[k]] && field[y + dy[k]][x + dx[k]] != 0)
		{
			dfs(y + dy[k], x + dx[k]);
		}
	}
}

int dfsAll()
{
	int frac = 0;

	visited.assign(N, vector<bool>(M, false));

	for (int i = 1; i < N-1; ++i)
	{
		for (int j = 1; j < M-1; ++j)
		{
			if (!visited[i][j] && field[i][j] != 0)
			{
				dfs(i, j);
				++frac;
			}
		}
	}

	return frac;
}

int main(void)
{
	int ans = 0;
	cin >> N >> M;

	field.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> field[i][j];
		}
	}

	while (dfsAll()==1)
	{
		melt = field;

		meltdown();

		field = melt;

		++ans;
	}

	if (dfsAll() > 1)
		cout << ans << '\n';

	else
		cout << "0\n";
}