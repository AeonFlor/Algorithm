#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
vector<deque<int>> cache;

deque<int> dp(int pos)
{
	if (pos == N)
		return deque<int>(1,1);

	if (pos > N)
		return deque<int>(1,0);

	if (cache[pos].size() != 0)
		return cache[pos]; 

	deque<int> jump1, jump2;

	int max_size, digit, i, tmp;

	jump2 = dp(pos + 2);
	jump1 = dp(pos + 1);

	max_size = (jump1.size() > jump2.size()) ? jump1.size() : jump2.size();

	for (i = max_size - 1; i >= 0; --i)
	{
		if (i < jump1.size() && i < jump2.size())
		{
			digit = jump1[i] + 2 * jump2[i];
		}

		else if (i < jump1.size())
		{
			digit = jump1[i];
		}

		else
		{
			digit = 2 * jump2[i];
		}

		cache[pos].push_front(digit);
	}

	i = 0;

	while (i < cache[pos].size())
	{
		if (cache[pos][i] > 9)
		{
			if (i != cache[pos].size() - 1)
				cache[pos][i + 1] += cache[pos][i] / 10;

			else
				cache[pos].push_back(cache[pos][i] / 10);

			cache[pos][i] %= 10;
		}

		++i;
	}

	return cache[pos];
}

int main(void)
{
	while (cin >> N)
	{
		cache.assign(N + 1, deque<int>());

		cache[0] = dp(0);

		for (int i = cache[0].size() - 1; i >= 0; --i)
			cout << cache[0][i];
		cout << '\n';
	}
}