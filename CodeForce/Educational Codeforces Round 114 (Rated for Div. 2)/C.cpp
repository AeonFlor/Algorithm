#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, m, gold, sum_a, atk, sum_mirror;

	vector<long long> hero, mirror;
	vector<pair<long, long>> dragon;

	sum_a = 0;

	cin >> n;

	hero.assign(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> hero[i];
		sum_a += hero[i];
	}

	cin >> m;

	dragon.assign(m, { 0,0 });

	sort(hero.begin(), hero.end());

	for (int i = 0; i < m; ++i)
	{
		gold = 0;
		mirror = hero;
		sum_mirror = sum_a;

		cin >> dragon[i].first >> dragon[i].second;

		atk = lower_bound(mirror.begin(), mirror.end(), dragon[i].first) - mirror.begin();
			
		if (atk == n)
		{
			gold += dragon[i].first - mirror[atk - 1];
			sum_mirror -= mirror[atk - 1];

			if (sum_mirror < dragon[i].second)
				gold += dragon[i].second - sum_mirror;
		}

		else if (mirror[atk] == dragon[i].first)
		{
			sum_mirror -= mirror[atk];

			if (sum_mirror < dragon[i].second)
				gold += dragon[i].second - sum_mirror;
		}

		else if (atk == 0)
		{
			sum_mirror -= mirror[atk];

			if (sum_mirror < dragon[i].second)
				gold += dragon[i].second - sum_mirror;
		}

		else
		{
			int temp = 0;

			if (sum_mirror - mirror[atk - 1] < dragon[i].second)
			{
				temp = dragon[i].first - mirror[atk - 1] + dragon[i].second - (sum_mirror - mirror[atk - 1]);
			}

			if (sum_mirror - mirror[atk] < dragon[i].second)
			{
				temp = (temp>dragon[i].second - (sum_mirror - mirror[atk]))? dragon[i].second - (sum_mirror - mirror[atk]) : temp;
			}

			gold += temp;
		}

		cout << gold << '\n';
	}
}