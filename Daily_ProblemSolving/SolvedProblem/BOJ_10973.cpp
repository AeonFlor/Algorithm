#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> seq, swap_std;
	int N, i, j, swap_pos, max_pos;
	bool flag = true;

	cin >> N;
	seq.assign(N, 0);

	for (i = 0; i < N; ++i)
		cin >> seq[i];

	swap_pos = 0;
	swap_std.push_back(N - 1);

	for (i = 0; i < swap_std.size(); ++i)
	{
		//swap_pos : �ٲ� ���� �� + �ٲ� ū �� * 100000
		//swap_std : ���� ���� ���
		for (j = swap_std[i] - 1; j >= swap_pos%100000; --j)
		{
			if (seq[j] > seq[swap_std[i]])
			{
				swap_pos = j+i*100000;
				flag = false;
				break;
			}

			else
				if (swap_std[i] == N - 1 || swap_std[i] != 0)
					swap_std.push_back(j);
		}
	}

	if (flag)
		cout << "-1";

	else
	{
		//������ �Ŀ����� �ٲ� �� �ֵ��� swap
		swap(seq[swap_std[swap_pos / 100000]], seq[swap_pos % 100000]);

		// �������� ����
		for (i = swap_pos%100000 + 1; i < N; ++i)
		{
			max_pos = N-1;

			for (j = i; j < N; ++j)
			{
				if (seq[max_pos] < seq[j])
					max_pos = j;
			}

			swap(seq[i], seq[max_pos]);
		}

		for (i = 0; i < N; ++i)
			cout << seq[i] << ' ';
	}
}