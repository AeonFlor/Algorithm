#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long t, m, max_m, min_m;
	vector<long long> letter(3,0);

	cin >> t;

	while (t--)
	{
		cin >> letter[0] >> letter[1] >> letter[2] >> m;

		max_m = letter[0] + letter[1] + letter[2] - 3;
		
		sort(letter.begin(), letter.end());

		if (letter[2] - 1 < letter[0] + letter[1])
			min_m = 0;

		else
			min_m = letter[2] - letter[1] - letter[0] - 1;

		if (m <= max_m && m >= min_m)
			cout << "YES\n";

		else
			cout << "NO\n";
	}
}