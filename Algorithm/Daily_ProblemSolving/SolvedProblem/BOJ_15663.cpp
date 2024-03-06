#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> input, temp;
vector<bool> visited;
vector<vector<int>> ans;

void FindPermutationByRecursion(int remainM)
{
	if (remainM == 0)
	{
		ans.push_back(temp);
		return;
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (visited[i])
			continue;

		temp.push_back(input[i]);
		visited[i] = true;
		FindPermutationByRecursion(remainM - 1);
		visited[i] = false;
		temp.pop_back();
	}
}

int main(void)
{
	// remove below line when code copy
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	input .assign(N, 0);
	visited.assign(N, false);

	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}

	FindPermutationByRecursion(M);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}