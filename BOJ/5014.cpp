// �ʱ⿡ �־��� S �� G �� ���� ��� ���������͸� �̿��� �ʿ䰡 ������ use the stairs ����ϵ��� �ߴµ� ã�ƺ��� 0 ����ؾߵǴ°ſ���.

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int F, S, G, U, D, ans = -1;

	queue<pair<int, int>> q;
	vector<bool> visited;

	cin >> F >> S >> G >> U >> D;

	visited.assign(F + 1, false);

	q.push({ S, 0 });
	visited[S] = true;

	while (!q.empty())
	{
		int here = q.front().first;
		int cnt = q.front().second;

		if (here == G)
		{
			ans = cnt;
			break;
		}
		
		q.pop();

		if (here + U <= F && !visited[here + U])
		{
			q.push({ here + U, cnt + 1 });
			visited[here + U] = true;
		}

		if (here - D >= 1 && !visited[here - D])
		{
			q.push({ here - D, cnt + 1 });
			visited[here - D] = true;
		}
	}

	if (ans == -1)
		cout << "use the stairs\n";

	else
		cout << ans << '\n';
}
