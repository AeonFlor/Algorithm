#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M, height, width = 1, overheight_length = 0, ans=0;
	vector<int> tree;

	cin >> N >> M;

	tree.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> tree[i];

	sort(tree.begin(), tree.end());

	while (tree.size() - width >= 0)
	{
		if (width != tree.size())
			height = tree[tree.size() - width] - tree[tree.size() - width - 1];

		else
			height = tree[0];

		if (height * width + overheight_length < M)
		{
			overheight_length += height * width++;
		}

		else
		{
			ans = tree[tree.size() - width] - (M - overheight_length) / width;

			if ((M - overheight_length) % width != 0)
				ans--;

			break;
		}
	}

	cout << ans << '\n';

	return 0;
}