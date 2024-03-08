#include <iostream>
#include <map>

using namespace std;

map<long long, long long> cache;

long long Fibonacci(long long n)
{
	if (cache.count(n) > 0)
		return cache[n];


	if (n % 2 == 1)
		return cache[n] = (Fibonacci((n + 1) / 2) * Fibonacci((n + 1) / 2) + Fibonacci((n - 1) / 2) * Fibonacci((n - 1) / 2)) % 1000000007;

	else
		return cache[n] = (Fibonacci(n / 2) * (Fibonacci(n / 2 + 1) + Fibonacci(n / 2 - 1))) % 1000000007;
}

int main(void)
{
	// remove below line when code copy
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 1;

	long long n;

	cin >> n;

	cout << Fibonacci(n);

	return 0;
}