#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, check, numOf2, numOf5;

    numOf2 = numOf5 = 0;

    cin >> N;

    while (N)
    {
        check = N--;

        while (check % 5 == 0)
        {
            ++numOf5;
            check /= 5;
        }

        while (check % 2 == 0)
        {
            ++numOf2;
            check /= 2;
        }
    }

    cout << ((numOf5 < numOf2) ? numOf5 : numOf2);
}