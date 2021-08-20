#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans, temp;
vector<int> A;

int main(void)
{
	ans = -1;
	cin >> N;

	A.assign(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A.begin(), A.end());

	// ó���� next_permutation ���� �Ѿ�� �ʰ� �Ϸ��� ���� ����
	while (ans == -1 || next_permutation(A.begin(), A.end()))
	{
		temp = 0;

		for (int i = 0; i < A.size() - 1; ++i)
			temp += abs(A[i] - A[i + 1]);

		ans = max(ans, temp);
	}

	cout << ans << '\n';
}