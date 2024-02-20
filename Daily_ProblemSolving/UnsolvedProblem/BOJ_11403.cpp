#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int adjacent[101][101];

bool can_reach(int start, int end)
{
	bool flag = false;

	if (adjacent[start][end] == 1)
		return true;

	for (int check = 1; check <= N; ++check)
	{
		if (check == start)
			continue;

		if (check == end)
			return true;

		if (adjacent[start][check] == 1)
		{
			flag = can_reach(check, end);
		}
	}

	return flag;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&adjacent[0][0], &adjacent[100][100], -1);


	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> adjacent[i][j];


	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (can_reach(i, j))
				adjacent[i][j] = 1;


	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << adjacent[i][j] << ' ';
		}
		
		cout << '\n';
	}


	return 0;
}