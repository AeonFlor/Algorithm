#include <iostream>
#include <string>

using namespace std;

string first, second;
int cache[1001][1001];

int lcs(int f_pos, int s_pos)
{
	int ans = 0;

	if (f_pos == first.length() || s_pos == second.length())
		return 0;

	if (cache[f_pos][s_pos] != -1)
		return cache[f_pos][s_pos];

	if (first[f_pos] == second[s_pos])
		ans = (ans > 1 + lcs(f_pos + 1, s_pos + 1)) ? ans : 1 + lcs(f_pos + 1, s_pos + 1);

	else
	{
		ans = (ans > lcs(f_pos + 1, s_pos)) ? ans : lcs(f_pos + 1, s_pos);
		ans = (ans > lcs(f_pos, s_pos + 1)) ? ans : lcs(f_pos, s_pos + 1);
	}

	return cache[f_pos][s_pos] = ans;
}

int main(void)
{
	int ans = 0;

	fill(&cache[0][0], &cache[1000][1001], -1);

	cin >> first >> second;

	for (int i = 0; i < first.length(); ++i)
		ans = (ans > lcs(i, 0)) ? ans : lcs(i, 0);

	cout<<ans<<'\n';
}