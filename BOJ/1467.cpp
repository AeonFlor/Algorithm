// 1:45 ~ 3:10
// 17:35 ~ 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int erase_cnt, cur;
// 주어진 수열
vector<int> sejun_num;
// 각 숫자별 지워야 하는 개수
int erase_num[10] = { 0, };

void search(int pos)
{
	int i, j, temp_cnt = 0;
	bool possible;
	// temp[x][n] : x 가 나오기까지의 n의 개수
	int temp[11][11] = { 0, };
	// isIn[x] : x 가 sejun_num 내에 존재하는지 확인
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

		// 맨 앞자리에 0이 나올 수 없으니 멈춤
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
			// 맨 앞자리에 올 수 있는 후보 숫자가 지워야 하는 개수와 같으면 필연적으로 지울 수 밖에 없음.
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

	// 마지막에 문자 하나만 남는 경우 배제하기 위해 임시로 10 추가.
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