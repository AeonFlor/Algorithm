#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int left, int right, int pos)
{
	int first, random;

	if (pos == 2)
	{
		random = rand() % (right - left + 1) + left;
		swap(arr[left], arr[random]);
	}

	else if (pos == 3)
	{
		random = left + (right - left) / 2;

		if (arr[left] > arr[random])
			swap(arr[left], arr[random]);

		if (arr[random] > arr[right])
			swap(arr[random], arr[right]);

		if (arr[left] > arr[random])
			swap(arr[left], arr[random]);

		if (right - left < 3)
			return -1;

		else
		{
			swap(arr[++left], arr[random]);
			--right;
		}
	}

	first = left;
	int pivot = arr[first];

	while (left <= right)
	{
		while (left <= right && arr[left] <= pivot)
			++left;

		while (left <= right && arr[right] >= pivot)
			--right;

		if (left <= right)
			swap(arr[left], arr[right]);

		else
			break;
	}

	swap(arr[first], arr[right]);

	return right;
}

void quick_sort(vector<int>& arr, int left, int right, int pos)
{
	if (left >= right)
		return;

	int index = partition(arr, left, right, pos);

	if (index == -1)
		return;

	quick_sort(arr, left, index - 1, pos);
	quick_sort(arr, index + 1, right, pos);
}

void print(vector<int>& arr)
{
	int i;

	for (i = 0; i < arr.size(); ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}

int main(void)
{
	int N, i, j, value, iter;
	clock_t start, finish;
	double duration;
	double sum[4] = { 0, };
	vector<int> arr, mirror;

	iter = 10;
	value = 10000000;

	srand((unsigned int)time(NULL));

	for(j=1; j<=iter; ++j)
	{
		cout << "[" << j << "번째 시행]\n\n";

		arr.assign(value, 0);

		for (i = 0; i < value; ++i)
		{
			arr[i] = rand();
		}

		cout << fixed;
		cout.precision(12);

		for (i = 1; i < 4; ++i)
		{
			mirror = arr;

			cout << i << " 번 수행 결과\n";

			start = clock();
			quick_sort(mirror, 0, value-1, i);
			finish = clock();

			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Duration : " << duration << "s\n";

			sum[i] += duration;
		}

		cout << '\n';
		cout << "===========================================\n";
	}

	for (i = 1; i < 4; ++i)
	{
		cout << i << "번 평균 수행 시간 : " << sum[i] / iter << '\n';
	}

	cout << '\n';

	return 0;
}

