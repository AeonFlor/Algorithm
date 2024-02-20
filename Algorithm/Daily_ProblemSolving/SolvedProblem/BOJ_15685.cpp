#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, x, y, d, g, move_size, ans;
	vector<vector<bool>> board(101, vector<bool>(101, false));

	vector<int> prev_move;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	cin >> N;

	ans = 0;

	while (N--)
	{
		prev_move.clear();

		cin >> x >> y >> d >> g;

		board[y][x] = true;
		y += dy[d];
		x += dx[d];
		board[y][x] = true;
		prev_move.push_back(d);

		while (g--)
		{
			move_size = prev_move.size();

			for (int i = move_size - 1; i >= 0; --i)
			{
				y += dy[(prev_move[i] + 1) % 4];
				x += dx[(prev_move[i] + 1) % 4];

				board[y][x] = true;
				prev_move.push_back((prev_move[i] + 1) % 4);
			}
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
			{
				++ans;
			}
		}
	}

	cout << ans << '\n';
}