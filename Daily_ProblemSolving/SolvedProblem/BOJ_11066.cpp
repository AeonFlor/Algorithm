#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, K;

vector<int> file, sum;
vector<vector<int>> cache;

int dp(int s, int e)
{
	if (s == e)
		return file[s];

	if (cache[s][e] != -1)
		return cache[s][e];

	int ans = 100000000;
	int part_sum = sum[e];

	if (s != 0)
		part_sum -= sum[s - 1];

	for (int i = s; i < e; ++i)
	{
		ans = min(ans, part_sum + dp(s, i) + dp(i + 1, e));
	}

	return cache[s][e] = ans;
}

int main(void)
{
	cin >> T;

	while (T--)
	{
		cin >> K;

		file.assign(K, 0);
		sum.assign(K, 0);
		cache.assign(K, vector<int>(K, -1));

		cin >> file[0];
		sum[0] = file[0];

		for (int i = 1; i < K; ++i)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		cout << dp(0, K-1) - sum[K-1] << '\n';
	}
}