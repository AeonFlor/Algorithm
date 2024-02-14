#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int T, n;
bool isError, isReverse;
string p, input, trans;
deque <int> seq;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		isError = isReverse = false;

		cin >> p >> n >> input;

		seq.clear();
		trans = "";

		input = input.substr(1, input.size() - 2);

		for (int i = 0; i < input.size(); ++i)
		{
			if (input.substr(i,1).compare(","))
				trans += input[i];

			else
			{
				if(trans.compare(""))
					seq.push_back(stoi(trans));
				trans = "";
			}
		}

		if(trans.compare(""))
			seq.push_back(stoi(trans));

		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i] == 'R')
			{
				isReverse = !isReverse;
			}

			else if (p[i] == 'D')
			{
				if (seq.empty())
				{
					isError = true;
					break;
				}

				if (isReverse)
					seq.pop_back();

				else
					seq.pop_front();
			}
		}

		if (isError)
			cout << "error\n";
		
		else
		{
			cout << '[';

			while (!seq.empty())
			{
				if (isReverse)
				{
					cout << seq[seq.size() - 1];
					seq.pop_back();
				}

				else
				{
					cout << seq[0];
					seq.pop_front();
				}
				
				if (seq.size())
					cout << ',';
			}

			cout << "]\n";
		}
	}
}