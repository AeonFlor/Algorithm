#include <iostream>
#include <string>

using namespace std;

bool flag;
string pw;
int cache[5001];

int dp(int n)
{
	int cnt = 0;
	string pw_part;

	if (n == pw.length())
		return 1;

	if (cache[n] != -1)
		return cache[n];

	if (pw[n] != '0')
	{
		cnt += dp(n + 1);

		if (n < pw.length() - 1)
		{
			pw_part = pw.substr(n, 2);

			if (stoi(pw_part) > 0 && stoi(pw_part) < 27)
				cnt += dp(n + 2);

			else if (stoi(pw_part) % 10 == 0)
				flag = false;
		}
	}

	else
		return 0;

	return cache[n] = cnt % 1000000;
}

int main(void)
{
	cin >> pw;

	flag = true;
	fill_n(cache, pw.length(), -1);

	dp(0);

	if (!flag)
		cout << "0\n";

	else
		cout << dp(0)<<'\n';
}