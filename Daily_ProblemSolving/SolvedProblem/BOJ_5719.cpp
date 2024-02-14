#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int S, D;
int U, V, P;
int ans;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> parent;
vector<bool> check;

int shortestRoad()
{
	vector<int> dist(N + 1, 10000001);
	priority_queue<pair<int, int>> q;

	dist[S] = 0;
	q.push({ 0, S });

	while (!q.empty())
	{
		int here = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (adj[here][i].second == -1)
				continue;

			if (nextDist == dist[there])
			{
				parent[there].push_back(here);
			}

			else if (nextDist < dist[there])
			{
				parent[there].clear();
				parent[there].push_back(here);

				dist[there] = nextDist;
				q.push({ -nextDist, there });
			}
		}
	}

	return dist[D];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin>>N>>M && (N||M))
	{
		adj.assign(N + 1, vector<pair<int, int>>());
		parent.assign(N + 1, vector<int>());
		check.assign(N + 1, false);

		cin >> S >> D;

		while (M--)
		{
			cin >> U >> V >> P;
			adj[U].push_back({ V, P });
		}

		if (shortestRoad() == 10000001)
		{
			cout << "-1\n";
			continue;
		}

		queue<int> erase;

		erase.push(D);

		while (!erase.empty())
		{
			int place = erase.front();
			erase.pop();

			if (check[place])
				continue;

			check[place] = true;

			for (int i = 0; i < parent[place].size(); ++i)
			{
				for (int j = 0; j < adj[parent[place][i]].size(); ++j)
				{
					if (adj[parent[place][i]][j].first == place)
					{
						erase.push(parent[place][i]);
						adj[parent[place][i]][j].second = -1;
					}
				}
			}
		}

		ans = shortestRoad();

		if (ans == 10000001)
			cout << "-1\n";

		else
			cout << ans << '\n';
	}
}