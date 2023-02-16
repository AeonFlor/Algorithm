#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void print_DFS(int current_vertex)
{
	visited[current_vertex] = true;
	cout << current_vertex << ' ';

	for (int edge_num = 0; edge_num < graph[current_vertex].size(); ++edge_num)
	{
		int next_vertex = graph[current_vertex][edge_num];

		if (visited[next_vertex])
			continue;

		print_DFS(next_vertex);
	}
}

void print_BFS(int start_vertex)
{
	queue<int> bfs;

	bfs.push(start_vertex);
	visited[start_vertex] = true;

	while (!bfs.empty())
	{
		int current_vertex = bfs.front();
		bfs.pop();
		cout << current_vertex << ' ';

		for (int edge_num = 0; edge_num < graph[current_vertex].size(); ++edge_num)
		{
			int next_vertex = graph[current_vertex][edge_num];

			if (visited[next_vertex])
				continue;

			bfs.push(next_vertex);
			visited[next_vertex] = true;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V, start, end;

	cin >> N >> M >> V;

	graph.resize(N + 1);
	visited.resize(N + 1);

	for (int edge_num = 0; edge_num < M; ++edge_num)
	{
		cin >> start >> end;

		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int vertex_num = 1; vertex_num <= N; ++vertex_num)
	{
		sort(graph[vertex_num].begin(), graph[vertex_num].end());
		graph[vertex_num].erase(unique(graph[vertex_num].begin(), graph[vertex_num].end()), graph[vertex_num].end());
	}
	
	fill(visited.begin(), visited.end(), false);
	print_DFS(V);
	cout << '\n';

	fill(visited.begin(), visited.end(), false);
	print_BFS(V);

	return 0;
}