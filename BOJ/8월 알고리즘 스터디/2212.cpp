#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K, ans;
	deque<int> sensor, dist;

	cin >> N >> K;

	sensor.assign(N, 0);
	dist.assign(N - 1, 0);
	ans = 0;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> sensor[i];
	}

	if (K < N)
	{
		sort(sensor.begin(), sensor.end());

		for (int i = 0; i < N - 1; ++i)
		{
			dist[i] = sensor[i + 1] - sensor[i];
		}

		sort(dist.begin(), dist.end(), greater<int>());

		// ���̰� ���� �� �� �ϳ� ������ ���ı� 2��, x�� ������ ���ı� x+1 ��
		// k �� �ִ� ���ı� ����. k = x + 1, x = k - 1.
		for (int i = 1; i < K; ++i)
		{
			dist.pop_front();
		}

		for (int i = 0; i < dist.size(); ++i)
		{
			ans += dist[i];
		}
	}

	cout << ans << '\n';
}