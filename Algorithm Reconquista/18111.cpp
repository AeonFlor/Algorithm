#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B, input, max_height = -1, min_height = 257, dtime, ans_time, ans_height;
	vector<int> height_count(257, 0);


	cin >> N >> M >> B;

	for (int i = 0; i < N * M; ++i)
	{
		cin >> input;

		for(int j=0; j<=input; ++j)
			++height_count[j];

		if (min_height > input)
			min_height = input;

		else if (max_height < input)
			max_height = input;
	}


	ans_time = 0;

	ans_height = min_height;

	for (int check_height = min_height + 1; check_height <= max_height; ++check_height)
	{
		ans_time += height_count[check_height] * 2;
		B += height_count[check_height];
	}


	for (int check_height = min_height + 1; check_height <= max_height; ++check_height)
	{
		if (B - N * M < 0)
			break;

		B -= N * M;

		dtime = -2 * height_count[check_height] + 1 * (N * M - height_count[check_height]);

		if (dtime > 0)
			break;

		ans_time += dtime;
		ans_height = check_height;
	}


	cout << ans_time <<' '<< ans_height << '\n';

	return 0;
}