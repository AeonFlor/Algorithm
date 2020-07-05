#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string input,cmp;
	
	while(true)
	{
		cin>>input;
		
		if(input=="0")
			break;
		
		cmp = input;
		
		reverse(cmp.begin(),cmp.end());
		
		if(input==cmp)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	
	return 0;
}
