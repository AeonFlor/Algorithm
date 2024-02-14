#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp, mode_idx;
	double total = 0;
	vector<int> mode(8001, 0);
	vector<int> input;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		total += (double)tmp/N;
		++mode[tmp+4000];
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	cout << floor(total + 0.5) << '\n';
	cout << input[N / 2] << '\n';
	
	mode_idx = max_element(mode.begin(), mode.end()) - mode.begin();

	if (mode.begin() + mode_idx + 1 != mode.end() && *max_element(mode.begin() + mode_idx + 1, mode.end()) == mode[mode_idx])
	{
		cout << max_element(mode.begin() + mode_idx + 1, mode.end()) - mode.begin() - 4000 << '\n';
	}

	else
		cout << mode_idx - 4000 << '\n';

	cout << input[N - 1] - input[0] << '\n';

	return 0;
}