#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int n)
{
	bool flag = false;

	visited[n] = true;

	for (int i = 0; i < adj[n].size(); ++i)
	{
		if (!visited[adj[n][i]])
			flag = dfs(adj[n][i]);

		else
			flag = true;
	}

	return flag;
}

int main(void)
{
	int T, N, input, ans;

	cin >> T;

	while (T--)
	{
		ans = 0;
		adj.assign(1001, vector<int>());
		visited.assign(1001, false);

		cin >> N;

		for (int i = 1; i <= N; ++i)
		{
			cin >> input;
			adj[i].push_back(input);
		}

		for (int i = 1; i < 1001; ++i)
		{
			if (!visited[i])
			{
				if (dfs(i))
					++ans;
			}
		}

		cout << ans << '\n';
	}
}