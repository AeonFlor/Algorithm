#include <iostream>

using namespace std;

int N;
int num[101];
long long cache[101][21];

long long dp(int n, int val)
{
	if (n == N-1)
	{
		if (val == num[N-1])
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	if (cache[n][val] != -1)
		return cache[n][val];

	long long cnt = 0;

	if (val + num[n] <= 20)
		cnt += dp(n+1, val + num[n]);

	if (val - num[n] >= 0)
		cnt += dp(n+1, val - num[n]);

	return cache[n][val] = cnt;
	
}

int main(void)
{
	cin >> N;

	fill(&cache[0][0], &cache[100][20], -1);

	for (int i = 0; i < N; ++i)
		cin >> num[i];

	cout << dp(1, num[0]) << '\n';
}