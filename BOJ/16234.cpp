#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
vector<vector<int>> A;
vector<vector<bool>> visited, bak;

int bfs(int x, int y, int val)
{
	int cnt = 1, total = 0;
	queue<pair<int, int>> q;

	if (!visited[x][y])
	{
		q.push({ x, y });
		total = A[x][y];
		visited[x][y] = true;

		while (!q.empty())
		{
			pair<int, int> here = q.front();
			q.pop();

			if (here.first != 0 && !visited[here.first - 1][here.second])
			{
				if (abs(A[here.first][here.second] - A[here.first - 1][here.second]) >= L && abs(A[here.first][here.second] - A[here.first - 1][here.second]) <= R)
				{
					q.push({ here.first - 1, here.second });
					visited[here.first - 1][here.second] = true;
					++cnt;
					total += A[here.first - 1][here.second];
				}
			}

			if (here.first != N - 1 && !visited[here.first + 1][here.second])
			{
				if (abs(A[here.first][here.second] - A[here.first + 1][here.second]) >= L && abs(A[here.first][here.second] - A[here.first + 1][here.second]) <= R)
				{
					q.push({ here.first + 1, here.second });
					visited[here.first + 1][here.second] = true;
					++cnt;
					total += A[here.first + 1][here.second];
				}
			}

			if (here.second != 0 && !visited[here.first][here.second - 1])
			{
				if (abs(A[here.first][here.second] - A[here.first][here.second - 1]) >= L && abs(A[here.first][here.second] - A[here.first][here.second - 1]) <= R)
				{
					q.push({ here.first, here.second - 1 });
					visited[here.first][here.second - 1] = true;
					++cnt;
					total += A[here.first][here.second - 1];
				}
			}

			if (here.second != N - 1 && !visited[here.first][here.second + 1])
			{
				if (abs(A[here.first][here.second] - A[here.first][here.second + 1]) >= L && abs(A[here.first][here.second] - A[here.first][here.second + 1]) <= R)
				{
					q.push({ here.first, here.second + 1 });
					visited[here.first][here.second + 1] = true;
					++cnt;
					total += A[here.first][here.second + 1];
				}
			}

			if (val != 0)
			{
				A[here.first][here.second] = val;
			}
		}
	}

	return total/cnt;
}

int main(void)
{
	int ans = -1, ave = -1, check = 0;

	cin >> N >> L >> R;

	A.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];

	while (check != N*N)
	{
		++ans;
		check = 0;
		visited.assign(N, vector<bool>(N, false));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				ave = bfs(i, j, 0);

				if (ave == A[i][j])
				{
					++check;
					continue;
				}

				bak = visited;
				visited.assign(N, vector<bool>(N, false));
				bfs(i, j, ave);
				visited = bak;
			}
		}
	}

	cout << ans << '\n';
}