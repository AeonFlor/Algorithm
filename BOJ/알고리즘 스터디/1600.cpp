// dp 로 풀면 루프 돔. 사례 소개하고 그래프로 풀기. visited 필요한데 이걸 쓰면 제대로 확인을 못 함.

#include <iostream>
#include <vector>

using namespace std;

int K, W, H;

int knight_dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int knight_dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<vector<int>> map;
vector<vector<vector<int>>> cache;

int dp(int y, int x, int jump)
{
	if (y == H && x == W)
		return 0;

	if (y > H || x > W)
		return 40001;

	if (cache[y][x][jump] != -1)
		return cache[y][x][jump];

	int ans = 40001;

	cout << y << ' ' << x << ' ' << jump << '\n';

	if (jump < K)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (y + knight_dy[i] < 1 || y + knight_dy[i] > H || x + knight_dx[i] < 1 || x + knight_dx[i] > W)
			{
				continue;
			}

			if (map[y + knight_dy[i]][x + knight_dx[i]] != 1)
			{
				ans = (ans < dp(y + knight_dy[i], x + knight_dx[i], jump + 1)) ? ans : dp(y + knight_dy[i], x + knight_dx[i], jump + 1);
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{		
		if (y + dy[i] < 1 || y + dy[i] > H || x + dx[i] < 1 || x + dx[i] > W)
		{
			continue;
		}

		if (map[y + dy[i]][x + dx[i]] != 1)
		{
			ans = (ans < dp(y + dy[i], x + dx[i], jump)) ? ans : dp(y + dy[i], x + dx[i], jump);
		}
	}

	return cache[y][x][jump] = 1 + ans;
}

int main(void)
{
	int ans;

	cin >> K >> W >> H;

	map.assign(H + 1, vector<int>(W + 1, 1));
	cache.assign(H + 1, vector<vector<int>>(W + 1, vector<int>(H + 1, -1)));

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			cin >> map[i][j];
		}
	}

	ans = dp(1, 1, 0);

	if (ans > 40000)
		cout << "-1\n";

	else
		cout << ans << '\n';
}