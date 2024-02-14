#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, input, i;
	set<int> A;

	cin >> N;

	for (i = 0; i < N; ++i)
	{
		cin >> input;
		
		A.insert(input);
	}

	cin >> M;

	for (i = 0; i < M; ++i)
	{
		cin >> input;

		if (A.find(input) != A.end())
			cout << "1\n";

		else
			cout << "0\n";
	}
}