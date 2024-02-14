// 00:35 ~ 01:40
// 14:00 ~ 14:55

#include <iostream>
#include <list>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void)
{
	int N, M;
	double input,  min_diff;
	tuple<double, double, int> temp, div;

	list<tuple<double, double, int>> cake;
	list<tuple<double, double, int>>::iterator first, last, pos;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		cake.push_back({ input, input, 1 });
	}

	cake.sort();

	first = cake.begin();
	last = cake.end();
	--last;

	min_diff = get<0>(*last) - get<0>(*first);

	cin >> M;

	while (M--)
	{
		temp = *last;
		--last;
		cake.pop_back();

		get<0>(temp) = get<1>(temp) / ++get<2>(temp);

		pos = upper_bound(cake.begin(), cake.end(), temp);
		cake.insert(pos, temp);

		first = cake.begin();
		last = cake.end();
		--last;

		min_diff = (min_diff < get<0>(*last) - get<0>(*first)) ? min_diff : get<0>(*last) - get<0>(*first);
	}

	cout << fixed;
	cout.precision(30);
	cout << min_diff << '\n';

	return 0;
}

// 균일하게 나누지 않아도 된다.
// 하나의 조각을 꼭 2개로 나누는 게 아니라 여러 개로 나눌 수 있다.