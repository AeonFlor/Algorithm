// 00:35

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	double input,  min_diff, temp, div;

	list<double> cake;
	list<double>::iterator first, last, pos;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		cake.push_back(input);
	}

	cake.sort();

	first = cake.begin();
	last = cake.end();
	--last;

	min_diff = *last - *first;

	cin >> M;

	while (M--)
	{
		temp = *last;
		--last;
		cake.pop_back();

		/*
		// ���� ���� ������ ���� ũ��� �������� �߶��� ���, �������� ���� ū ������ ū �� Ȯ��.
		if (temp - *first > *last)
		{
			// ���� ���� ������ �������� ���� ū ���� ���̸�ŭ ���� ���Է� ������. div �� ���Ӱ� ������ �� ��� �� ���� �����̴�.
			// ����� *last �� (*first + ����)�̴�.
			div = *first + (temp - *first - *last);

			// ���� ������ ���� ū ������ Ŀ���ٸ�, ���̰� �ּҰ� �ǵ��� �ٽ� ������. (���� ������ ū �������� �� Ŀ���� �� ��������� ������ ������ ���� ū ������ Ŀ���� �� ��.)
			if (div > *last)
			{
				// temp �� �߰����̾�� �ϴ� ������ �ϳ��� �����̶� �� �۾�����, �ٸ� �� Ŀ�� �ᱹ ������ �о�����. ������ ���̴� �� ����. 
				div = temp / 2;
			}
		}

		else
		{
			if (temp - *first < *first)
			{
				div = temp / 2;
			}

			else
			{
				div = *first;
			}
		}
		*/

		div = temp / 2;

		pos = upper_bound(cake.begin(), cake.end(), div);
		cake.insert(pos, div);

		pos = upper_bound(cake.begin(), cake.end(), temp - div);
		cake.insert(pos, temp-div);

		first = cake.begin();
		last = cake.end();
		--last;

		min_diff = (min_diff < *last - *first) ? min_diff : *last - *first;
	}

	cout << min_diff << '\n';

	return 0;
}

// �����ϰ� ������ �ʾƵ� �ȴ�.
// �ϳ��� ������ �� 2���� ������ �� �ƴ϶� ���� ���� ���� �� �ִ�.