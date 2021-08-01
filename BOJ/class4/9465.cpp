#include <iostream>
#include <vector>

using namespace std;

int T, n, input;
vector<vector<int>> sticker;
vector<vector<int>> cache;

int score(int x, int y)
{
	if (x >= n-1)
		return sticker[y][x];

	if (cache[y][x] != -1)
		return cache[y][x];
	
	int max;

	max = score(x + 1, !y);
	max = (max > score(x + 2, y)) ? max : score(x + 2, y);
	max = (max > score(x + 2, !y)) ? max : score(x + 2, !y);
	
	return cache[y][x] = sticker[y][x] + max;
	
}

int main(void)
{
	int max;

	cin >> T;

	while (T--)
	{
		sticker.assign(2, vector<int>(100000, 0));
		cache.assign(2, vector<int>(100000, -1));

		cin >> n;

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> input;
				sticker[i][j] = input;
			}
		}

		// score(0,0) �� ������ �ϸ� sticker[0][0] �� ����ϴ� ��츸 ����ϴ� ���̴�.
		max = score(0, 0);
		max = (max > score(0, 1)) ? max : score(0, 1);

		cout <<max<< '\n';
	}
}