#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string in;

	for(int i=0; i<100; i++)
	{
		getline(cin,in);
		cout<<in<<endl;
	}
	return 0;
}