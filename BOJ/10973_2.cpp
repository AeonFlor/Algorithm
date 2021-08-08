#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	bool flag = false;

	cin >> n;

	vector<int> seq(n);

	cin >> seq[0];

	for (int i = 1; i < n; ++i)
	{
		cin >> seq[i];

		if (seq[i - 1] > seq[i])
			flag = true;
	}

	if (flag)
	{
		prev_permutation(seq.begin(), seq.end());

		for (auto& i : seq)
			cout << i << ' ';
	}

	else
		cout << "-1";
}