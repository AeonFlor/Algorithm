#include <iostream>

using namespace std;

char side[6][3][3];
char color[6] = { 'r', 'w', 'b', 'o', 'y', 'g' };
char com[6] = { 'F', 'U', 'R', 'B', 'D', 'L' };
// up, right, down, left, 추후 -1 -> 돌아가는 위치
int part[6][4] = { {5, 6, 2, 3}, {1346, -1, -1, -1}, {-1, 125, -1, 4}, {2, 3, 5, 6}, {-1, -1, 1346, -1}, {-1, 4, -1, 125} };
// up, right, down, left, 추후 -1 -> 돌아가는 순서
int direction[6][4] = { {2, 3, 5, 6}, {4, 3, 1, 6}, {2, 4, 5, 1}, {2, 6, 5, 3}, {1, 3, 4, 6}, {2, 1, 5, 4} };
// 돌아가면서 역순이 되는 조합
bool rev[6][6];
int rev_check[6];

void Initialize()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				side[i][j][k] = color[i];
			}
		}
	}
}

void rotate_cube(int std, char dir)
{
	int pos, cur, next;
	char temp[6][3];
	char temp_rot[3][3];

	//기준면 회전
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (dir == '+')
				temp_rot[i][j] = side[std][2 - j][i];

			else
				temp_rot[2 - j][i] = side[std][i][j];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			side[std][i][j] = temp_rot[i][j];
		}
	}

	fill(&temp[0][0], &temp[5][3], '-');

	fill(&rev_check[0], &rev_check[5], 0);

	// 돌아가는 순서
	for (int i = 0; i < 4; ++i)
	{
		cur = direction[std][i] - 1;

		if(dir == '+')
			next = direction[std][(i + 1) % 4] - 1;

		// -1 인데 음수가 될 수 있으니 +4 까지 해줘서 +3 이다.
		else
			next = direction[std][(i + 3) % 4] - 1;

		// 어디가 돌아가야 되는지 확인
		for (int j = 0; j < 4; ++j)
		{
			int pos = part[std][j];

			if (pos == -1)
				continue;

			for (int k = pos; k > 0; k /= 10)
			{
				if (k % 10 - 1 == cur)
				{
					rev_check[next] = (rev[cur][next]) ? 1 : 0;

					for (int l = 0; l < 3; ++l)
					{
						if (j == 0)
							temp[next][l] = side[cur][0][l];

						else if (j == 1)
							temp[next][l] = side[cur][l][2];

						else if (j == 2)
							temp[next][l] = side[cur][2][l];

						else if (j == 3)
							temp[next][l] = side[cur][l][0];
					}
				}
			}
		}
	}

	// 돌아가는 순서
	for (int i = 0; i < 4; ++i)
	{
		cur = direction[std][i] - 1;

		// 어디가 돌아가야 되는지 확인
		for (int j = 0; j < 4; ++j)
		{
			int pos = part[std][j];

			if (pos == -1)
				continue;

			for (int k = pos; k > 0; k /= 10)
			{
				if (k % 10 - 1 == cur)
				{
					for (int l = 0; l < 3; ++l)
					{
						if (j == 0)
							side[cur][0][l] = temp[cur][l + (2 - 2 * l) * rev_check[cur]];

						else if (j == 1)
							side[cur][l][2] = temp[cur][l + (2 - 2 * l) * rev_check[cur]];

						else if (j == 2)
							side[cur][2][l] = temp[cur][l + (2 - 2 * l) * rev_check[cur]];

						else if (j == 3)
							side[cur][l][0] = temp[cur][l + (2 - 2 * l) * rev_check[cur]];
					}
				}
			}
		}
	}
}

int main(void)
{
	int T, n;
	// command[2] 로 하면 런타임 에러남. 마지막 버퍼까지 읽어와서 그런가..?
	char command[3];

	fill(&rev[0][0], &rev[5][6], false);
	rev[1][5] = rev[1][3] = rev[2][4] = rev[3][1] = rev[3][4] = rev[4][2] = rev[4][3] = rev[5][1] = true;

	cin >> T;

	while (T--)
	{
		Initialize();

		cin >> n;

		while (n--)
		{
			cin >> command;

			for (int i = 0; i < 6; ++i)
				if (com[i] == command[0])
					rotate_cube(i, command[1]);
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << side[1][i][j];
			}
			cout << '\n';
		}
	}
}