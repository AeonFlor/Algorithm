#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string input;

	cin>>input;
	int l = input.length();

	for(int i=0; i<=l/10; i++)
	{
		if(i==l/10)
			for(int j=i*10; j<l; j++)
				cout<<input[j];
		else
			for(int j=i*10; j<i*10+10;j++)
				cout<<input[j];
		printf("\n");
	}

	return 0;
}