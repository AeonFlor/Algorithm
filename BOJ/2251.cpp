#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int vol[3], current[3];
vector<int> ans;
queue<tuple<int, int, int>> q;
int visited[201][201][201] = { false, };

void move_water(int origin, int target, int none)
{
	int check_size = current[origin] + current[target];
	int check[3];

	check[origin] = 0;
	check[target] = check_size;
	check[none] = current[none];

	if (check_size <= vol[target] && !visited[check[0]][check[1]][check[2]])
	{
		q.push({ check[0],check[1],check[2] });
		visited[check[0]][check[1]][check[2]] = true;
	}

	check[origin] = check_size - vol[target];
	check[target] = vol[target];

	if (check_size > vol[target] && !visited[check[0]][check[1]][check[2]])
	{
		q.push({ check[0],check[1],check[2] });
		visited[check[0]][check[1]][check[2]] = true;
	}
}

int main(void)
{
	cin >> vol[0] >> vol[1] >> vol[2];

	visited[0][0][vol[2]] = true;
	ans.push_back(vol[2]);

	q.push({ 0, 0, vol[2] });

	while (!q.empty())
	{
		tie(current[0], current[1], current[2]) = q.front();
		q.pop();

		if (current[0] == 0)
			ans.push_back(current[2]);

		move_water(0, 1, 2);
		move_water(0, 2, 1);
		move_water(1, 0, 2);
		move_water(1, 2, 0);
		move_water(2, 0, 1);
		move_water(2, 1, 0);
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}