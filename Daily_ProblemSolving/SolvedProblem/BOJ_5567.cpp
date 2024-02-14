#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
vector<vector<int>> relation;
vector<bool> visited;

int main(void)
{
	int ans = 0;
	queue<pair<int, int>> q;

	cin >> n >> m;

	relation.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty())
	{
		int here = q.front().first;
		int bridge = q.front().second;

		q.pop();

		if (bridge > 2)
			break;

		++ans;

		for (int i = 0; i < relation[here].size(); ++i)
		{
			if (!visited[relation[here][i]])
			{
				q.push({ relation[here][i], bridge + 1 });
				visited[relation[here][i]] = true;
			}
		}
	}

	cout <<ans - 1<< '\n';
}