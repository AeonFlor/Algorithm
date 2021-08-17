#include <iostream>

using namespace std;

int main(void)
{
	long long side[6];
	long long N, ans, min_side, min_edge, min_vertex, max;

	min_side = min_edge = min_vertex = 151;

	cin >> N;

	ans = 0;
	max = 0;

	for (int i = 0; i < 6; ++i)
	{
		cin >> side[i];
		min_side = (min_side < side[i]) ? min_side : side[i];
		
		max = (max > side[i]) ? max : side[i];
		ans += side[i];
	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (i == j || j == 5 - i)
				continue;

			min_edge = (min_edge < side[i] + side[j]) ? min_edge : side[i] + side[j];
		}

		for (int j = 0; j < 6; ++j)
		{
			if (j == i || j == 5 - i)
				continue;

			for (int k = 0; k < 6; ++k)
			{
				if (k == i || k == j || k == 5 - i || k == 5 - j)
					continue;

				min_vertex = (min_vertex < side[i] + side[j] + side[k]) ? min_vertex : side[i] + side[j] + side[k];

			}
		}
	}

	if (N > 2)
		ans = (5 * N * N - 16 * N + 12) * min_side + (8 * N - 12) * min_edge + 4 * min_vertex;

	else if (N == 2)
		ans = 4 * min_edge + 4 * min_vertex;

	else
		ans -= max;

	cout << ans << '\n';
}