#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> field;
vector<vector<bool>> visited;

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
0
int main(void)
{
	int T, n;
	string input;

	cin >> T;

	while (T--)
	{
		cin >> n;

		field.assign(2, vector<int>(n + 1, 1));
		visited.assign(2, vector<bool>(n + 1, false));

		for (int i = 0; i < 2; ++i)
		{
			input = "";
			cin >> input;

			for (int j = 0; j < input.size(); ++j)
			{
				field[i][j] = input[j] - '0';
			}
		}

		queue<pair<int, int>> bfs;

		bfs.push({ 0,0 });

		while (!bfs.empty())
		{
			int y = bfs.front().first;
			int x = bfs.front().second;

			if (y == 1 && x == n - 1)
				break;

			bfs.pop();

			for (int i = 0; i < 8; ++i)
			{
				if (y + dy[i] < 0 || y + dy[i] >1 || x + dx[i] < 0 || x + dx[i] == n)
					continue;

				if (field[y + dy[i]][x + dx[i]] == 0)
				{
					if (visited[y + dy[i]][x + dx[i]])
						continue;

					bfs.push({ y + dy[i], x + dx[i] });
					visited[y + dy[i]][x + dx[i]] = true;
				}
			}
		}

		if (bfs.empty())
			cout << "NO\n";

		else
			cout << "YES\n";
	}
}