#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> arr(5);
	string line;
	
	for(int i=0; i<5; ++i)
	{
		getline(cin,line);
		arr[i]=line;
	}
	
	for(int i=0; i<15; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			if(arr[j].length()>i)
				cout<<arr[j][i];
		}
	}
}
