#include <iostream>
#include <vector>

using namespace std;

int ans;

void bracket(vector<char> &s, int l, int r)
{
	if (ans == 0)
		return;

	if (l == 0 && r == 0)
	{
		for (int i = 0; i < s.size(); ++i)
			cout << s[i];
		cout << '\n';

		--ans;
	}

	if (l < r)
	{
		s.push_back(')');
		bracket(s, l, r - 1);
		s.pop_back();
	}

	if (l > 0)
	{
		s.push_back('(');
		bracket(s, l-1, r);
		s.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<char> s;

	int t, n;

	cin >> t;

	while (t--)
	{
		cin >> n;
		ans = n;
		bracket(s, n, n);
	}
}