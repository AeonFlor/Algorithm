#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, x, y, d, g;
	pair<int, int> std;
	vector<vector<bool>> board(101, vector<bool>(101, false));

	vector<pair<int, int>> prev_coor, mirror;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	cin >> N;

	while (N--)
	{
		prev_coor.clear();
		mirror.clear();

		cin >> x >> y >> d >> g;

		if (!board[y][x])
			board[y][x] = true;
		
		if (!board[y + dy[d]][x + dx[d]])
			board[y + dy[d]][x + dx[d]] = true;

		// prev_coor[prev_coor.size()-1] �� �������� ȸ���� ������
		prev_coor.push_back({ y, x });
		prev_coor.push_back({ y + dy[d], x + dx[d] });

		// �̹� 0���� �Ϸ������� g-- �� �ƴ� --g -> 0���뵵 ������ �״�� g--
		while (g--)
		{
			mirror = prev_coor;
			std = prev_coor[prev_coor.size() - 1];

			// prev_coor.size() - 1 ���� �ϴ� ������ ������ prev_coor �� �������� �α� ����
			for (int i = prev_coor.size() - 2; i >= 0; --i)
			{
				//if (prev_coor[i].second + std < 0 || prev_coor[i].second + std > 100 || prev_coor[i].first - std < 0 || prev_coor[i].first - std > 100)
					//continue;

				board[std.second + std.first - prev_coor[i].second][std.second - std.first + prev_coor[i].first] = board[prev_coor[i].first][prev_coor[i].second];
				mirror.push_back({ std.second + std.first - prev_coor[i].second, std.second - std.first + prev_coor[i].first });
			}

			prev_coor = mirror;
		}

		cout << "============================\n";

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (board[i][j])
					cout << "1 ";

				else
					cout << "0 ";
			}

			cout << '\n';
		}
	}
}