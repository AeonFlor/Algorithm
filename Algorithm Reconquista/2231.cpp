#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, decomposition, tmp, check_ans;

	cin >> N;

	check_ans = max(1, N - 54);
	decomposition = 0;

	for (; check_ans < N; ++check_ans)
	{
		decomposition = check_ans;
		tmp = check_ans;

		while (tmp / 10 != 0)
		{
			decomposition += tmp % 10;
			tmp /= 10;
		}

		decomposition += tmp % 10;

		if (decomposition == N)
		{
			cout << check_ans << '\n';
			break;
		}
	}

	if(decomposition != N)
		cout << "0\n";

	return 0;
}