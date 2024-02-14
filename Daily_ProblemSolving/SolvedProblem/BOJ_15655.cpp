#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> seq, ans;

void print_seq(int pos)
{
	if (ans.size() == M)
	{
		for(int i=0; i<ans.size(); ++i)
			cout << ans[i] <<' ';
		cout << '\n';
	}

	for (int i = pos; i < N; ++i)
	{
		ans.push_back(seq[i]);
		print_seq(i + 1);
		ans.pop_back();
	}
}

int main(void)
{
	cin >> N >> M;

	seq.assign(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	sort(seq.begin(), seq.end());

	print_seq(0);
}