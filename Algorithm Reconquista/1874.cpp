#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size, input_flag = 0, inc_seq = 1;
	vector<int> input, stack;
	vector<char> result;

	cin >> size;
	input.resize(size);

	while (input_flag != size)
		cin >> input[input_flag++];

	input_flag = 0;

	while (input_flag != size)
	{
		if (!stack.empty() && stack.back() == input[input_flag])
		{
			result.push_back('-');
			stack.pop_back();
			++input_flag;
		}

		else if (inc_seq <= size)
		{
			stack.push_back(inc_seq++);
			result.push_back('+');
		}

		else
			break;
	}

	if (stack.empty())
		for (auto iter : result)
			cout << iter << '\n';
		
	else
		cout << "NO\n";

	return 0;
}