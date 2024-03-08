#include <iostream>

using namespace std;

int main(void)
{
	// remove below line when code copy
	freopen("input.txt", "r", stdin);

	string input;
	int i;

	cin >> input >> i;

	cout << input[i - 1];

	return 0;
}