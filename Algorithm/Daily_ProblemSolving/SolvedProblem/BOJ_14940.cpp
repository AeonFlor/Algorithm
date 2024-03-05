#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	// remove below line when code copy
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, row, col;
	int map[1001][1001] = { 0, };
	int ans[1001][1001] = { 0, };
	int dRow[4] = { 0, 1, 0, -1 };
	int dCol[4] = { -1, 0, 1, 0 };
	queue<tuple<int, int, int>> bfs;

	cin >> n >> m;

	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < m; ++col)
		{
			cin >> map[row][col];

			if (map[row][col] == 2)
			{
				bfs.push(make_tuple(0, row, col));
			}

			else if (map[row][col] == 1)
			{
				ans[row][col] = -1;
			}
		}
	}

	while (!bfs.empty())
	{
		int distance = get<0>(bfs.front());
		int curRow = get<1>(bfs.front());
		int curCol = get<2>(bfs.front());
		bfs.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (curRow + dRow[i] < 0 || curRow + dRow[i] >= n || curCol + dCol[i] < 0 || curCol + dCol[i] >= m)
				continue;

			if (ans[curRow + dRow[i]][curCol + dCol[i]] == -1 && map[curRow + dRow[i]][curCol + dCol[i]] == 1)
			{
				ans[curRow + dRow[i]][curCol + dCol[i]] = distance + 1;
				bfs.push(make_tuple(distance + 1, curRow + dRow[i], curCol + dCol[i]));
			}
		}
	}

	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < m; ++col)
		{
			cout << ans[row][col] << " ";
		}
		cout << '\n';
	}

	return 0;
}