#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string input;

	cin>>input;

	for(int i=97; i<123; i++)
	{
		if(input.find(char(i))==string::npos)
			cout<<"-1 ";
		else
			cout<<input.find(char(i))<<" ";
	}

	cout<<endl;

	return 0;
}