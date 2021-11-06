#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<unsigned long long> arr;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned long long t, n, sum, ans;
	int address, next;
	double ave;

	cin >> t;

	while (t--)
	{
		cin >> n;

		sum = ans = 0;
		arr.assign(n, 0);

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		ave = (double)sum / n;

		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; ++i)
		{
			address = lower_bound(arr.begin() + i + 1, arr.end(), ave * 2 - arr[i]) - arr.begin();
			next = upper_bound(arr.begin() + i + 1, arr.end(), ave * 2 - arr[i]) - arr.begin();

			ans += next - address;
		}

		cout << ans << '\n';
	}
}