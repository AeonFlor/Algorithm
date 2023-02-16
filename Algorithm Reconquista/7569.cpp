#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N, H, remain_tomato = 0, ans = -1;
	int box[102][102][102];

	int dwidth[6] = { 0, 0, -1, 1, 0, 0 };
	int dlength[6] = { 0, 0, 0, 0, -1, 1 };
	int dheight[6] = { 1, -1, 0, 0, 0, 0 };

	queue<tuple<int, int, int, int>> ripe_tomato_about_time;

	cin >> M >> N >> H;

	for (int height = 1; height <= H; ++height)
	{
		for (int length = 1; length <= N; ++length)
		{
			for (int width = 1; width <= M; ++width)
			{
				cin >> box[width][length][height];

				if (box[width][length][height] == 0)
					++remain_tomato;

				else if (box[width][length][height] == 1)
					ripe_tomato_about_time.push(make_tuple(0, width, length, height));
			}
		}
	}

	while (!ripe_tomato_about_time.empty())
	{
		tuple<int, int, int, int> current_tomato = ripe_tomato_about_time.front();
		ripe_tomato_about_time.pop();

		if (ans < get<0>(current_tomato))
			ans = get<0>(current_tomato);

		for (int direction_idx = 0; direction_idx < 7; ++direction_idx)
		{
			if (get<1>(current_tomato) + dwidth[direction_idx] < 1 || get<1>(current_tomato) + dwidth[direction_idx] > M || get<2>(current_tomato) + dlength[direction_idx] < 1 || get<2>(current_tomato) + dlength[direction_idx] > N || get<3>(current_tomato) + dheight[direction_idx] < 1 || get<3>(current_tomato) + dheight[direction_idx] > H)
				continue;

			int next_tomato_state = box[get<1>(current_tomato) + dwidth[direction_idx]][get<2>(current_tomato) + dlength[direction_idx]][get<3>(current_tomato) + dheight[direction_idx]];

			if (next_tomato_state != 0)
				continue;

			box[get<1>(current_tomato) + dwidth[direction_idx]][get<2>(current_tomato) + dlength[direction_idx]][get<3>(current_tomato) + dheight[direction_idx]] = 1;
			ripe_tomato_about_time.push(make_tuple(get<0>(current_tomato) + 1, get<1>(current_tomato) + dwidth[direction_idx], get<2>(current_tomato) + dlength[direction_idx], get<3>(current_tomato) + dheight[direction_idx]));
			--remain_tomato;
		}
	}

	if (remain_tomato == 0)
		cout << ans << '\n';

	else
		cout << "-1\n";

	return 0;
}