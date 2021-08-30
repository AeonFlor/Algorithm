#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, min_diff;
	pair<int, int> ans, tmp_low, tmp_up;
	vector<int> liq;

	cin >> N;

	liq.assign(N, 0);
	min_diff = 2147483647;

	for (int i = 0; i < N; ++i)
	{
		cin >> liq[i];
	}

	sort(liq.begin(), liq.end());
	
	for (int i = 0; i < N; ++i)
	{
		tmp_low.second = lower_bound(liq.begin(), liq.end(), liq[i] * -1) - liq.begin();

		if (tmp_low.second == liq.size())
			--tmp_low.second;

		else if (tmp_low.second < 0)
			++tmp_low.second = 0;

		tmp_up.second = upper_bound(liq.begin(), liq.end(), liq[i] * -1) - liq.begin();

		if (tmp_up.second == liq.size())
			--tmp_up.second;

		else if (tmp_up.second < 0)
			tmp_up.second = 0;

		if (i != tmp_low.second)
		{
			tmp_low = { liq[i], liq[tmp_low.second] };

			if (abs(tmp_low.first + tmp_low.second) < min_diff)
			{
				min_diff = abs(tmp_low.first + tmp_low.second);
				ans = tmp_low;
			}
		}
		
		if (i != tmp_up.second)
		{
			tmp_up = { liq[i], liq[tmp_up.second] };

			if (abs(tmp_up.first + tmp_up.second) < min_diff)
			{
				min_diff = abs(tmp_up.first + tmp_up.second);
				ans = tmp_up;
			}
		}
	}

	if (ans.first < ans.second)
	{
		cout << ans.first << ' ' << ans.second << '\n';
	}

	else
	{
		cout << ans.second << ' ' << ans.first << '\n';
	}
}
