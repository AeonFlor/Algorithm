#include <iostream>
#include <stack>

using namespace std;

void PrintPostfixExpression(string unit)
{
	stack<char> stack;

	for (int i = 0; i < unit.size(); ++i)
	{
		if (unit[i] == '+' || unit[i] == '-')
		{
			if (!stack.empty() && (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/'))
			{
				while (!stack.empty() && stack.top() != '(')
				{
					cout << stack.top();
					stack.pop();
				}
			}

			stack.push(unit[i]);
		}

		else if (unit[i] == '*' || unit[i] == '/')
		{
			if (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
			{
				while (!stack.empty() && !(stack.top() == '(' || stack.top() == '+' || stack.top() == '-'))
				{
					cout << stack.top();
					stack.pop();
				}
			}

			stack.push(unit[i]);
		}

		else if (unit[i] == '(')
		{
			stack.push(unit[i]);
		}

		else if (unit[i] == ')')
		{
			while (stack.top() != '(')
			{
				cout << stack.top();
				stack.pop();
			}

			stack.pop();
		}

		else
		{
			cout << unit[i];
		}
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