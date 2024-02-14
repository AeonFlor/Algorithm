#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, input;
	long long c1, c2, ans = 0;
	priority_queue<long long, vector<long long>, greater<long long>> card;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		card.push(input);
	}

	for (int i = 0; i < m; ++i)
	{
		c1 = card.top();
		card.pop();
		c2 = card.top();
		card.pop();

		card.push(c1 + c2);
		card.push(c1 + c2);
	}

	while (!card.empty())
	{
		ans += card.top();
		card.pop();
	}

	cout << ans << '\n';
}