#include <iostream>
#include <vector>

using namespace std;

int N, S, M;
vector<int> vol_diff;
vector<vector<int>> cache;

int dp(int pos, int P)
{
	if (pos == N)
		return P;

	if (cache[pos][P] != -11)
		return cache[pos][P];

	int max_vol = -1;

	if (P + vol_diff[pos] <= M)
		max_vol = dp(pos + 1, P + vol_diff[pos]);

	if (P - vol_diff[pos] >= 0)
		max_vol = ((M - max_vol) < (M - dp(pos + 1, P - vol_diff[pos]))) ? max_vol : dp(pos + 1, P - vol_diff[pos]);

	return cache[pos][P] = max_vol;
}

int main(void)
{
	cin >> N >> S >> M;

	vol_diff.assign(N + 1, 0);
	cache.assign(N + 1, vector<int>(M+1, -11));

	for (int i = 0; i < N; ++i)
	{
		cin >> vol_diff[i];
	}

	cout << dp(0, S) << '\n';
}

// ±ò²ûÇÏ°Ô ±¸ÇöÇÑ ¼Ò½º : https://www.acmicpc.net/source/31948482