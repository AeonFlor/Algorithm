#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N : A �迭�� ũ��
// A : �α� ������ ��Ÿ���� �迭
int N;
vector<vector<int>> A;

// min_diff : �α��� ���� ���� ���ű��� ���� ���� ���ű��� �α� ���� �� �ּڰ�.
// population : ���ű� �� �α� ���� ��Ÿ���� �迭
// partSum : A �� �κ��� �迭
int min_diff;
vector<int> population;
vector<vector<int>> partSum;

void cal_population(int x, int y, int d1, int d2)
{
	// 1+d1 <= y, d2 <= N-x-d1 ���� ó��.
	if (x + d1 + d2 > N || y + d1 + d2 > N || y - d1 < 2 || x + d2 > N || y + d2 > N)
		return;

	// �� ���ű� �� �α����� ������ ���� ���Ҵ� -> ���� ���� �ʱ�ȭ �� �ϳ�?
	population.assign(6, 0);

	// {0, 0} �� i �� ���ű� ��ȣ�� �����ַ��� ���� ��.
	vector<pair<int, int>> start = { {0, 0}, {1, 1}, {1, y}, {x + d1, 1}, {x + d2, y + d2 - d1} };
	vector<pair<int, int>> end = { {0, 0}, {x + d1, y}, {x + d2, N}, {N, y + d2 - d1}, {N, N} };

	for (int i = 1; i <= 4; ++i)
	{
		population[i] = partSum[end[i].first][end[i].second] + partSum[start[i].first - 1][start[i].first - 1];
	}

	population[2] -= partSum[x + d2][y];
	population[3] -= partSum[x + d1][y + d2 - d1];
	population[4] -= partSum[end[2].first][end[2].second] - partSum[end[3].first][end[3].second];

	int sum, std_x, std_y;

	for (int k = 0; k < 2; ++k)
	{
		sum = 0;

		// �ﰢ���� ����� ���ٴ� �� �̿��ؼ� k �� 0 �� �� 1 ���� �ﰢ�� ó��, k �� 1 �� �� 4 ���� �ﰢ�� ó���ϵ��� �ߴ�.
		std_x = x + d2 * k;
		std_y = y + d2 * k;

		for (int i = std_x; i <= std_x + d1; ++i)
		{
			// �� ���ó�� �����ؼ� �ﰢ�� ���� ���� ���� �� �ߴ�.
			for (int j = std_y; j >= std_y - (i - std_x); --j)
			{
				sum += A[i][j];
			}
		}

		population[1 + 3 * k] -= k ? (partSum[std_x + d1][std_y + d1] - partSum[std_x][std_y] - partSum[std_x][std_y - d1] + partSum[std_x][std_y - d1] - sum) : sum;
		population[5] += k ? (partSum[std_x + d1][std_y + d1] - partSum[std_x][std_y] - partSum[std_x][std_y - d1] + partSum[std_x][std_y - d1] - sum) : sum;

		sum = 0;

		// �ﰢ���� ����� ���ٴ� �� �̿��ؼ� k �� 0 �� �� 2 ���� �ﰢ�� ó��, k �� 1 �� �� 3 ���� �ﰢ�� ó���ϵ��� �ߴ�.
		std_x = x + d1 * k;
		std_y = y - d1 * k;

		for (int i = std_x; i <= std_x + d1; ++i)
		{
			// �� ���ó�� �����ؼ� �ﰢ�� ���� ���� ���� �� �ߴ�.
			for (int j = std_y + (i - std_x); j <= std_y + d2; ++j)
			{
				sum += A[i][j];
			}
		}

		population[1 + 1 * k] -= k? (partSum[std_x + d2][std_y + d2] - partSum[std_x][std_y+d2] - partSum[std_x+d2][std_y] + partSum[std_x][std_y] - sum) : sum;
		population[5] += k ? partSum[std_x + d2][std_y + d2] - partSum[std_x][std_y + d2] - partSum[std_x + d2][std_y] + partSum[std_x][std_y] - sum : sum;
	}

	population[5] += partSum[x + d1][y + d2 - d1] - partSum[x + d2][y + d2 - d1] - partSum[x + d1][y + d1] + partSum[x + d2][y];

	// ���ű� �ȿ� �α��� ������ ��ǥ �߸� ������ ���� �Ǵ��ϰ� ����.
	// ������ ����Ǵ� ��찡 �־ == 0 �� �ƴ� <= 0���� �ٲ���� ������ �� �ȴ�.
	for (int i = 1; i < 6; ++i)
		if (population[i] <= 0)
			return;

	sort(population.begin(), population.end());

	// �׽�Ʈ
	if (min_diff > population[5] - population[1])
	{
		cout << x << ' ' << y << ' ' << d1 << ' ' << d2 << " -> " << population[5] << '-' << population[1] << " = " << population[5] - population[1] << '\n';
	}

	min_diff = (min_diff < population[5] - population[1])? min_diff : population[5] - population[1];
}

int main(void)
{
	// Ž���غ� ���� �����ϴ� ������.
	int x, y, d1, d2;

	cin >> N;

	min_diff = 40001;
	A.assign(N + 1, vector<int>(N + 1, 0));
	partSum.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> A[i][j];

			if (i - 1 > 0)
				partSum[i][j] += A[i - 1][j];

			if (j - 1 > 0)
				partSum[i][j] += A[i][j - 1];

			if (i - 1 > 0 && j - 1 > 0)
				partSum[i][j] += A[i - 1][j - 1];
		}
	}

	for (x = 1; x <= N; ++x)
	{
		for (y = 1; y <= N; ++y)
		{
			for (d2 = 1; d2 <= N; ++d2)
			{
				for (d1 = 1; d1 <= N; ++d1)
				{
					cal_population(x, y, d1, d2);
				}
			}
		}
	}

	cout << min_diff << '\n';
}

// 17:50 ~ 19:25 ����