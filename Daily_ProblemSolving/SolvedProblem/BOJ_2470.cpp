#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, min_diff, s, e;
	pair<int, int> ans;
	vector<int> liq;

	cin >> N;

	liq.assign(N, 0);
	min_diff = 2147483647;

	for (int i = 0; i < N; ++i)
	{
		cin >> liq[i];
	}

	sort(liq.begin(), liq.end());
	
	s = 0;
	e = N - 1;

	while (s < e)
	{
		if (abs(liq[s] + liq[e]) < min_diff)
		{
			min_diff = abs(liq[s] + liq[e]);
			ans = { liq[s], liq[e] };

			if (min_diff == 0)
				break;
		}

		else if (liq[s] + liq[e] > 0)
			--e;

		else
			++s;
	}

	cout << ans.first << ' ' << ans.second << '\n';
}
