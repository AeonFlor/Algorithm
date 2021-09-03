#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> post_order, pre_order, parent;
	vector<vector<int>> child;

	// check - 0: 기본 상태, 1: 부모 혹은 자식을 탐색하는 경우
	int input, pos, check, tmp;

	while (cin >> input)
	{
		pre_order.push_back(input);
	}

	parent.assign(1000001, 0);
	child.assign(1000001, vector<int>(2,0));
	post_order.assign(1, pre_order[0]);

	post_order.push_back(1000000);
	parent[pre_order[0]] = 1000000;
	pos = 0;
	check = 0;

	for (int i = 1; i < pre_order.size(); ++i)
	{
		if (pre_order[i] < post_order[pos])
		{
			parent[pre_order[i]] = post_order[pos];

			if (child[post_order[pos]][0] == 0 || check == 4)
			{
				if (child[post_order[pos]][0] == 0)
					child[post_order[pos]][0] = pre_order[i];
				post_order.insert(post_order.begin() + pos, pre_order[i]);
				pos = find(post_order.begin(), post_order.end(), pre_order[0]) - post_order.begin();
				check = 0;
			}

			else
			{
				--i;
				check = 1;
				tmp = pos;
				pos = find(post_order.begin(), post_order.end(), child[post_order[pos]][0]) - post_order.begin();
			}
		}

		else
		{
			if (child[post_order[pos]][1] == 0)
			{
				parent[pre_order[i]] = post_order[pos];
				child[post_order[pos]][1] = pre_order[i];
				post_order.insert(post_order.begin() + pos, pre_order[i]);
				pos = find(post_order.begin(), post_order.end(), pre_order[0]) - post_order.begin();
				check = 0;
			}

			else
			{
				if (check == 1)
				{
					--i;
					pos = tmp;
				}

				else if (pre_order[pos] < child[post_order[pos]][1])
				{
					tmp = pos;
					pos = find(post_order.begin(), post_order.end(), child[post_order[pos]][1]) - post_order.begin();
					--i;
					check = 1;
				}

				else
				{
					pos = find(post_order.begin(), post_order.end(), child[post_order[pos]][1]) - post_order.begin();
					--i;
				}
			}
		}
	}

	for (int i = 0; i < post_order.size() - 1; ++i)
	{
		cout << post_order[i] << '\n';
	}
}