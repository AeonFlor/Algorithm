#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N : A 배열의 크기
// A : 인구 분포를 나타내는 배열
int N;
vector<vector<int>> A;

// min_diff : 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이 중 최솟값.
// population : 선거구 별 인구 수를 나타내는 배열
// partSum : A 의 부분합 배열
int min_diff;
vector<int> population;
vector<vector<int>> partSum;

void cal_population(int x, int y, int d1, int d2)
{
	// 1+d1 <= y, d2 <= N-x-d1 예외 처리.
	if (x + d1 + d2 > N || y + d1 + d2 > N || y - d1 < 2 || x + d2 > N || y + d2 > N)
		return;

	// 각 선거구 별 인구수를 저장한 벡터 재할당 -> 변수 값만 초기화 못 하나?
	population.assign(6, 0);

	// {0, 0} 은 i 랑 선거구 번호랑 맞춰주려고 넣은 것.
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

		// 삼각형의 모양이 같다는 걸 이용해서 k 가 0 일 때 1 영역 삼각형 처리, k 가 1 일 때 4 영역 삼각형 처리하도록 했다.
		std_x = x + d2 * k;
		std_y = y + d2 * k;

		for (int i = std_x; i <= std_x + d1; ++i)
		{
			// 별 찍기처럼 색각해서 삼각형 영역 안의 값을 더 했다.
			for (int j = std_y; j >= std_y - (i - std_x); --j)
			{
				sum += A[i][j];
			}
		}

		population[1 + 3 * k] -= k ? (partSum[std_x + d1][std_y + d1] - partSum[std_x][std_y] - partSum[std_x][std_y - d1] + partSum[std_x][std_y - d1] - sum) : sum;
		population[5] += k ? (partSum[std_x + d1][std_y + d1] - partSum[std_x][std_y] - partSum[std_x][std_y - d1] + partSum[std_x][std_y - d1] - sum) : sum;

		sum = 0;

		// 삼각형의 모양이 같다는 걸 이용해서 k 가 0 일 때 2 영역 삼각형 처리, k 가 1 일 때 3 영역 삼각형 처리하도록 했다.
		std_x = x + d1 * k;
		std_y = y - d1 * k;

		for (int i = std_x; i <= std_x + d1; ++i)
		{
			// 별 찍기처럼 색각해서 삼각형 영역 안의 값을 더 했다.
			for (int j = std_y + (i - std_x); j <= std_y + d2; ++j)
			{
				sum += A[i][j];
			}
		}

		population[1 + 1 * k] -= k? (partSum[std_x + d2][std_y + d2] - partSum[std_x][std_y+d2] - partSum[std_x+d2][std_y] + partSum[std_x][std_y] - sum) : sum;
		population[5] += k ? partSum[std_x + d2][std_y + d2] - partSum[std_x][std_y + d2] - partSum[std_x + d2][std_y] + partSum[std_x][std_y] - sum : sum;
	}

	population[5] += partSum[x + d1][y + d2 - d1] - partSum[x + d2][y + d2 - d1] - partSum[x + d1][y + d1] + partSum[x + d2][y];

	// 선거구 안에 인구가 없으면 좌표 잘못 설정된 경우로 판단하고 종료.
	// 음수가 저장되는 경우가 있어서 == 0 이 아닌 <= 0으로 바꿨더니 실행이 안 된다.
	for (int i = 1; i < 6; ++i)
		if (population[i] <= 0)
			return;

	sort(population.begin(), population.end());

	// 테스트
	if (min_diff > population[5] - population[1])
	{
		cout << x << ' ' << y << ' ' << d1 << ' ' << d2 << " -> " << population[5] << '-' << population[1] << " = " << population[5] - population[1] << '\n';
	}

	min_diff = (min_diff < population[5] - population[1])? min_diff : population[5] - population[1];
}

int main(void)
{
	// 탐색해볼 값을 저장하는 변수들.
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

// 17:50 ~ 19:25 실패