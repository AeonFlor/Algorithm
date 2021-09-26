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
		// 가장 작은 조각과 같은 크기와 나머지로 잘랐을 경우, 나머지가 가장 큰 값보다 큰 지 확인.
		if (temp - *first > *last)
		{
			// 가장 작은 조각에 나머지와 가장 큰 값의 차이만큼 더한 무게로 나눈다. div 가 새롭게 나뉘어 진 경우 중 작은 조각이다.
			// 결과는 *last 와 (*first + 차이)이다.
			div = *first + (temp - *first - *last);

			// 작은 조각이 가장 큰 값보다 커진다면, 차이가 최소가 되도록 다시 나눈다. (작은 조각이 큰 조각보다 더 커지는 건 상관없지만 원래의 목적인 가장 큰 값보다 커지면 안 됨.)
			if (div > *last)
			{
				// temp 의 중간값이어야 하는 이유는 하나가 조금이라도 더 작아지면, 다른 게 커져 결국 범위가 넓어진다. 범위를 줄이는 게 목적. 
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

// 균일하게 나누지 않아도 된다.
// 하나의 조각을 꼭 2개로 나누는 게 아니라 여러 개로 나눌 수 있다.