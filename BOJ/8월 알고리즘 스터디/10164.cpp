#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache;

int N, M, K;

int dp(bool isPass, int coor)
{
	if (coor > N * M || (!isPass && K < coor))
		return 0;

	else if (coor == N * M)
	{
		if (isPass)
			return 1;

		else
			return 0;
	}

	int cnt = 0;

	if (cache[isPass][coor] != -1)
		return cache[isPass][coor];

	isPass = isPass || (coor == K);

	if (coor % M != 0)
		cnt += dp(isPass, coor + 1);

	cnt += dp(isPass, coor + M);

	return cache[isPass][coor] = cnt;
}

int main(void)
{
	cin >> N >> M >> K;
	
	cache.assign(2, vector<int>((N + 1) * (M + 1), -1));

	if(K == 0)
		cout << dp(true, 1) << '\n';

	else
		cout << dp(false, 1) << '\n';
}

// 좋은 소스 : https://www.acmicpc.net/source/31397007
// 소스 분석 : https://www.acmicpc.net/source/30952429