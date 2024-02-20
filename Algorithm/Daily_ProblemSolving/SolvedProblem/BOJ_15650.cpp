#include <iostream>
#include <string>

using namespace std;

int N, M;

void print_sequence(int n, int m, string ans)
{
	if (m == 0)
		cout << ans << '\n';

	else
	{
		for (int i = n; i <= N; ++i)
		{
			ans += to_string(i) + " ";
			print_sequence(i + 1, m - 1, ans);
			ans = ans.substr(0, ans.length()-2);
		}
	}
}

int main(void)
{
	cin >> N >> M;

	print_sequence(1, M, "");
}