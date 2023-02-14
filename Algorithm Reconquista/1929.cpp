#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	vector<bool> prime_num(1000001, true);

	prime_num[1] = false;

	for (int divisor = 1; divisor < prime_num.size(); ++divisor)
	{
		if (!prime_num[divisor])
			continue;

		for (int dividend = divisor * 2; dividend < prime_num.size(); dividend += divisor)
			if (prime_num[dividend])
				prime_num[dividend] = false;
	}

	cin >> M >> N;

	for (int check_num = M; check_num <= N; ++check_num)
	{
		if (prime_num[check_num])
			cout << check_num << '\n';
	}

	return 0;
}