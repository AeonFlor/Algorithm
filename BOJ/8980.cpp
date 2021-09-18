#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, C, M, ans;

vector<vector<int>> goods;
vector<tuple<int, int, int, int>> info;

void print()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << goods[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void)
{
	// vol : 그 구간에서 배송 중인 박스의 가능한
	int dis, from, to, cnt, vol, tmp;

	cin >> N >> C >> M;
	
	ans = 0;
	goods.assign(N + 1, vector<int>(N + 1, 0));

	while (M--)
	{
		cin >> from >> to >> cnt;
		info.push_back({ to - from, from, to, cnt });
	}

	sort(info.begin(), info.end());

	for (int i = 0; i < info.size(); ++i)
	{
		print();

		if (i == 5)
		{
			i = 5;
		}

		tie(dis, from, to, cnt) = info[i];

		cout << from << ' ' << to << '\n';

		vol = 0;

		for (int j = to; j > from; --j)
		{
			tmp = 0;

			for (int k = 1; k <= N; ++k)
			{
				tmp = (tmp > goods[k][j]) ? tmp : goods[k][j];
			}

			vol += tmp;
		}

		vol = C - vol;

		if (vol < 0)
			vol = 0;

		goods[from][to] = (vol < cnt) ? vol : cnt;

		ans += goods[from][to];
	}

	cout << ans << '\n';
}