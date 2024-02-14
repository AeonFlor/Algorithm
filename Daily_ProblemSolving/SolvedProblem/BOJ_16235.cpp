#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K, x, y, age, size, it;

	int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

	vector<vector<int>> A, field;
	deque<tuple<int, int, int>> tree_data, tree_death;

	cin >> N >> M >> K;

	A.assign(N + 1, vector<int>(N + 1, 0));
	field.assign(N + 1, vector<int>(N + 1, 5));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> x >> y >> age;
		tree_data.push_back({ age, x, y });
	}

	while (K-- && !tree_data.empty())
	{
		size = tree_data.size();

		while(size--)
		{
			tie(age, x, y) = tree_data[0];
			tree_data.pop_front();

			if (field[x][y] >= age)
			{
				field[x][y] -= age;
				++age;
				tree_data.push_back({ age, x, y});
			}

			else
			{
				tree_death.push_back({ age, x, y });
			}
		}

		while(!tree_death.empty())
		{
			tie(age, x, y) = tree_death[0];
			tree_death.pop_front();

			field[x][y] += age / 2;
		}

		size = tree_data.size();
		it = 0;

		while(size--)
		{
			tie(age, x, y) = tree_data[it++];

			if (age % 5 == 0)
			{
				for (int k = 0; k < 8; ++k)
				{
					if (y + dy[k] == 0 || y + dy[k] == N + 1 || x + dx[k] == 0 || x + dx[k] == N + 1)
						continue;

					tree_data.push_front({ 1, x + dx[k], y + dy[k] });
					++it;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				field[i][j] += A[i][j];
			}
		}
	}

	cout << tree_data.size() << '\n';
}