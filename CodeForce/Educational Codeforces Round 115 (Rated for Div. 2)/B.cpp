#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, input;
	bool flag;
	vector<int> student;
	vector<int> day_count;

	cin >> t;

	while (t--)
	{
		flag = false;

		cin >> n;

		if (n % 2 == 1)
		{
			cout << "NO\n";
			continue;
		}

		student.assign(n, 0);
		day_count.assign(5, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cin >> input;

				if (input == 1)
				{
					++day_count[j];
					student[i] += 1 << j;
				}
			}
		}

		for (int i = 0; i < 5 && !flag; ++i)
		{
			if (day_count[i] >= n / 2)
			{
				vector<int> count(5, 0);
				vector<int> both(5, 0);

				for (int j = 0; j < 5 && !flag; ++j)
				{
					if (i == j)
						continue;

					for (int k = 0; k < student.size(); ++k)
					{
						if ((student[k] & 1 << j) == 1 << j)
						{
							if ((student[k] & 1 << i) == 0)
								++count[j];

							else if ((student[k] & 1 << i) == 1 << i)
								++both[j];
						}
					}
				}

				for (int j = 0; j < 5 && !flag; ++j)
				{
					if (i == j)
						continue;

					int supplement = n / 2 - count[j];

					if (count[j] >= n / 2)
						flag = true;

					else if (both[j] >= supplement && day_count[i] - n / 2 >= supplement)
						flag = true;
				}
			}
		}

		if (flag)
			cout << "YES\n";

		else
			cout << "NO\n";
	}
}