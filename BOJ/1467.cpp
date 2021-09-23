// 1:45 ~ 3:10
// 17:35 ~ 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int erase_cnt, cur;
// �־��� ����
vector<int> sejun_num;
// �� ���ں� ������ �ϴ� ����
int erase_num[10] = { 0, };

void search(int pos)
{
	int i, j, temp_cnt = 0;
	bool possible;
	// temp[x][n] : x �� ����������� n�� ����
	int temp[11][11] = { 0, };
	// isIn[x] : x �� sejun_num ���� �����ϴ��� Ȯ��
	bool isIn[11] = { false, };

	for (i = 0; i <= 10; ++i)
	{
		isIn[i] = false;

		for (j = pos; j < sejun_num.size(); ++j)
		{
			if (sejun_num[j] == i)
			{
				isIn[i] = true;
				break;
			}

			++temp[i][sejun_num[j]];
		}

		if (!isIn[i])
		{
			for (j = 0; j <= 10; ++j)
				temp[i][j] = -1;
		}
	}

	for (i = 10; i >= 0; --i)
	{
		if (!isIn[i])
			continue;

		// �� ���ڸ��� 0�� ���� �� ������ ����
		if (i == 0 && pos == 0)
			break;

		possible = true;

		for (j = 0; j < 10; ++j)
		{
			if (erase_num[j] < temp[i][j])
			{
				possible = false;
				break;
			}
		}

		if (possible)
		{
			// �� ���ڸ��� �� �� �ִ� �ĺ� ���ڰ� ������ �ϴ� ������ ������ �ʿ������� ���� �� �ۿ� ����.
			if (i == sejun_num[pos])
			{
				if (temp[10][sejun_num[pos]] == erase_num[sejun_num[pos]])
				{
					temp_cnt = 1;
					--erase_num[sejun_num[pos]];
					--erase_cnt;
				}

				else
					continue;
			}

			else
			{
				for (j = 0; j < 10; ++j)
				{
					erase_num[j] -= temp[i][j];
					erase_cnt -= temp[i][j];
					temp_cnt += temp[i][j];
				}
			}
			
			sejun_num.erase(sejun_num.begin() + pos, sejun_num.begin() + pos + temp_cnt);

			break;
		}
	}
}

int main(void)
{
	int i;
	string input;

	erase_cnt = cur = 0;

	cin >> input;

	for (i = 0; i < input.size(); ++i)
	{
		sejun_num.push_back(input[i] - '0');
	}

	// �������� ���� �ϳ��� ���� ��� �����ϱ� ���� �ӽ÷� 10 �߰�.
	sejun_num.push_back(10);

	cin >> input;

	for (i = 0; i < input.size(); ++i)
	{
		++erase_cnt;
		++erase_num[input[i] - '0'];
	}

	while (erase_cnt)
	{
		search(cur++);
	}

	for (i = 0; i < sejun_num.size() - 1; ++i)
	{
		cout << sejun_num[i];
	}

	cout << '\n';

	return 0;
}