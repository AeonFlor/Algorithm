#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, A, B, trace;
	string ans;

	vector<int> visited(10000);
	vector<char> ans_cmd(10000);
	queue<int> bfs;

	int cmd_result[5];
	char cmd_text[5] = { '.', 'D', 'S', 'L', 'R' };

	cin >> T;

	while (T--)
	{
		fill(visited.begin(), visited.end(), -1);
		fill(ans_cmd.begin(), ans_cmd.end(), '.');
		while (!bfs.empty()) bfs.pop();

		cin >> A >> B;

		bfs.push(A);


		while (!bfs.empty())
		{
			int source = bfs.front();

			bfs.pop();

			if (source == B)
				break;

			cmd_result[1] = source * 2 % 10000;
			cmd_result[2] = (source == 0) ? 9999 : source - 1;
			cmd_result[3] = source % 1000 * 10 + source / 1000;
			cmd_result[4] = source % 10 * 1000 + source / 10;


			for (int check = 1; check < 5; ++check)
			{
				if (visited[cmd_result[check]] == -1)
				{
					bfs.push(cmd_result[check]);
					visited[cmd_result[check]] = source;
					ans_cmd[cmd_result[check]] = cmd_text[check];
				}
			}
		}

		trace = B;
		ans = "";

		while (trace != A)
		{
			ans += ans_cmd[trace];
			trace = visited[trace];
		}

		reverse(ans.begin(), ans.end());

		cout << ans << '\n';
	}


	return 0;
}