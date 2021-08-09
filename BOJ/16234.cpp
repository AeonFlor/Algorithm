#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<vector<int>> A;
vector<vector<bool>> visited;
queue<pair<int,int>> A_union;

int bfs(int x, int y)
{
	int cnt = 1, total = 0;
	queue<pair<int, int>> q;

	if (!visited[x][y])
	{
		q.push({ x, y });
		A_union.push({ x, y });
		total = A[x][y];
		visited[x][y] = true;

		while (!q.empty())
		{
			pair<int, int> here = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				if (here.first + dx[k] < 0 || here.first + dx[k] == N || here.second + dy[k] < 0 || here.second + dy[k] == N || visited[here.first + dx[k]][here.second + dy[k]])
					continue;

				if (abs(A[here.first][here.second] - A[here.first + dx[k]][here.second + dy[k]]) >= L && abs(A[here.first][here.second] - A[here.first + dx[k]][here.second + dy[k]]) <= R)
				{
					q.push({ here.first + dx[k], here.second + dy[k] });
					A_union.push({ here.first + dx[k], here.second + dy[k] });
					visited[here.first + dx[k]][here.second + dy[k]] = true;
					++cnt;
					total += A[here.first + dx[k]][here.second + dy[k]];
				}
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
				ave = bfs(i, j);

				while (!A_union.empty())
				{
					pair<int, int> pos = A_union.front();
					A_union.pop();

					A[pos.first][pos.second] = ave;
				}

				if (ave == A[i][j])
				{
					++check;
					continue;
				}
			}
		}
	}

	cout << ans << '\n';
}