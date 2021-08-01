#include <iostream>

using namespace std;

int sum[1025][1025] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, x1, x2, y1, y2, input;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> sum[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << '\n';
	}
}