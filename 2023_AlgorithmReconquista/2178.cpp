#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string input;

	int maze[101][101];
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	vector<vector<bool>> visited(101, vector<bool>(101, false));
	queue<tuple<int, int, int>> bfs;


	cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		cin >> input;

		for (int x = 1; x <= input.length(); ++x)
		{
			if (input[x - 1] == '1')
				maze[y][x] = 1;

			else
				maze[y][x] = 0;
		}
	}


	bfs.push(make_tuple(1, 1, 1));
	visited[1][1] = true;

	while (!bfs.empty())
	{
		int current_count = get<0>(bfs.front());
		int current_y = get<1>(bfs.front());
		int current_x = get<2>(bfs.front());

		bfs.pop();

		if (current_y == N && current_x == M)
			cout << current_count << '\n';

		for (int dir_idx = 0; dir_idx < 4; ++dir_idx)
		{
			if (current_y + dy[dir_idx] < 1 || current_y + dy[dir_idx] > N || current_x + dx[dir_idx] < 1 || current_x + dx[dir_idx] > M)
				continue;

			else if (maze[current_y + dy[dir_idx]][current_x + dx[dir_idx]] == 1 && !visited[current_y + dy[dir_idx]][current_x + dx[dir_idx]])
			{
				bfs.push(make_tuple(current_count + 1, current_y + dy[dir_idx], current_x + dx[dir_idx]));
				visited[current_y + dy[dir_idx]][current_x + dx[dir_idx]] = true;
			}
		}
	}


	return 0;
}