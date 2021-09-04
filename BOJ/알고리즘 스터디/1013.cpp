#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
bool isMatch;

void check(int pos)
{
	if (isMatch)
	{
		return;
	}

	if (pos == input.size())
	{
		cout << "YES\n";
		isMatch = true;
	}

	int tmp = pos;
	bool isEnd = false;

	if (pos < input.size() - 3 && input.substr(pos, 3) == "100")
	{
		tmp += 3;

		while (tmp < input.size())
		{
			if (input[tmp] == '0')
			{
				++tmp;
			}

			else
				break;
		}

		while (tmp < input.size())
		{
			if (input[tmp] == '1')
			{
				// ���� ������ �����ߴٸ� ������ ���ο� ������ ���� �� ����.
				if (isEnd)
				{
					check(tmp);
				}

				++tmp;
				isEnd = true;
			}

			else
				break;
		}

		if (isEnd)
			check(tmp);
	}

	if (pos < input.size() - 1 && input.substr(pos, 2) == "01")
		check(pos+2);
}

int main(void)
{
	int n;

	cin >> n;

	while (n--)
	{
		cin >> input;

		isMatch = false;

		check(0);

		if (!isMatch)
			cout << "NO\n";
	}
}

// ���� �ҽ� : https://www.acmicpc.net/source/32973010