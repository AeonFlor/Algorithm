#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, Input, i, j;

	cin >> N >> M;

	vector<int> SumUntil(N+1, 0);

	while (N)
	{
		cin >> Input;

		SumUntil[SumUntil.size() - N] = SumUntil[SumUntil.size() - N - 1] + Input;

		N--;
	}

	while (M)
	{
		cin >> i >> j;

		cout << SumUntil[j] - SumUntil[i-1] << '\n';

		M--;
	}

	return 0;
}