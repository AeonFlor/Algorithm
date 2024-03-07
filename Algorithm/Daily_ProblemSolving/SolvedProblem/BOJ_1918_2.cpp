#include <iostream>
#include <stack>

using namespace std;

int SetRank(char a)
{
	if (a == '(')
		return 2;

	else if (a == '*' || a == '/')
		return 1;

	else
		return 0;
}

bool IsRankHigh(char target, char check)
{
	if (target == '(')
		return true;

	return SetRank(target) < SetRank(check);
}

void PrintPostfixExpression(string unit)
{
	stack<char> stack;

	for (int i = 0; i < unit.size(); ++i)
	{
		if (unit[i] == ')')
		{
			while (stack.top() != '(')
			{
				cout << stack.top();
				stack.pop();
			}
			stack.pop();
			continue;
		}

		if (unit[i] >= 'A' && unit[i] <= 'Z')
		{
			cout << unit[i];
			continue;
		}

		while (!stack.empty() && !IsRankHigh(stack.top(), unit[i]))
		{
			cout << stack.top();
			stack.pop();
		}

		stack.push(unit[i]);
	}

	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
}

int main(void)
{
	// remove below line when code copy
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;

	cin >> input;

	PrintPostfixExpression(input);

	return 0;
}