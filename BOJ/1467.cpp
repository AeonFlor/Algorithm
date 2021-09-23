// 1:45 ~ 3:10
// 17:35 ~ 20:10
// 01:00 ~ 02:00

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

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
			// 앞 자리에 올 수가 무조건 지워야 하는 수라면 넘어감
			if(temp[10][i] == erase_num[i])
			{
				if (i == sejun_num[pos])
				{
					temp_cnt = 1;
					--erase_num[sejun_num[pos]];
					--erase_cnt;
					--cur;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i;
	string input;

	erase_cnt = cur = 0;

	/*
	* Testcase 확인해보는 코드
	* 
	int num = 0;
	string res;
	string file_in, file_out;
	int success = 0, total = 0;

	while (++num <= 100)
	{
		file_in = "";
		file_out = "";
		sejun_num.clear();

		if (num < 10)
			file_in = "00" + to_string(num);

		else if (num < 100)
			file_in = "0" + to_string(num / 10) + to_string(num % 10);

		else
			file_in = "100";

		file_out = "./testcases/output_" + file_in + ".txt";
		file_in = "./testcases/input_" + file_in + ".txt";

		ifstream in(file_in);
		ifstream out(file_out);

		input = "";
		in >> input;

		for (i = 0; i < input.size(); ++i)
		{
			sejun_num.push_back(input[i] - '0');
		}

		// 마지막에 문자 하나만 남는 경우 배제하기 위해 임시로 10 추가.
		sejun_num.push_back(10);
		input = "";
		in >> input;

		for (i = 0; i < input.size(); ++i)
		{
			++erase_cnt;
			++erase_num[input[i] - '0'];
		}

		cur = 0;

		while (erase_cnt)
		{
			search(cur++);
		}

		i = 0;

		res = "";

		for (; i < sejun_num.size() - 1; ++i)
		{
			res += (sejun_num[i] + '0');
		}
		input = "";
		out >> input;

		if (res == input)
		{
			cout << '[' << num << "] Clear!\n";
			++success;
		}

		else
		{
			cout << '[' << num << "] Fail!\n";
			cout << "Output : " << res << '\n';
			cout << "Answer : " << input << '\n';
		}

		++total;

		in.close();
		out.close();
	}

	cout << "Accuracy : " << (double)success / total * 100 << "%\n";
	*/

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

	i = 0;

	for (; i < sejun_num.size() - 1; ++i)
	{
		cout << sejun_num[i];
	}

	cout << '\n';

	return 0;
}