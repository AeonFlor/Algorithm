#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> seq, ans;
bool check[8] = {false, };

void print_sequence(int n, int m)
{
	if (m == M)
	{
		for (int i = 0; i < M; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (check[i])
				continue;
			ans.push_back(seq[i]);
			check[i] = true;
			print_sequence(i, m + 1);
			ans.pop_back();
			check[i] = false;
		}
	}
}

int main(void)
{
	int input;

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		seq.push_back(input);
	}

	sort(seq.begin(), seq.end());

	print_sequence(-1, 0);
}