#include <iostream>

using namespace std;

int main(void)
{
	int n,tar=1,cnt=1;

	cin>>n;

	while(tar<n)
	{
		tar+=6*cnt;
		cnt++;
	}

	cout<<cnt<<endl;

	return 0;
}