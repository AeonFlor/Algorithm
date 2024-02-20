#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, host, trust, cnt;
bool visited[10001];

vector<vector<int>> adj(10001);
vector<int> ans;
vector<pair<int, int>> max_com;

void dfs(int vertex)
{
	++cnt;
	visited[vertex] = true;

	for (int i = 0; i < adj[vertex].size(); ++i)
		if (!visited[adj[vertex][i]])
			dfs(adj[vertex][i]);
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> trust >> host;

		adj[host].push_back(trust);
	}

	for (int i = 1; i <= N; ++i)
	{
		cnt = 0;
		
		for (int i = 0; i <= N; ++i)
			visited[i] = false;

		dfs(i);

		max_com.push_back({ cnt, i });
	}

	sort(max_com.begin(), max_com.end(), greater<>());

	for (int i = 0; i < max_com.size(); ++i)
		if (max_com[i].first == max_com[0].first)
			ans.push_back(max_com[i].second);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
}