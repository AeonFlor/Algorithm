#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int i, cnt=0;
	
	getline(cin,str);
	
	for(i=0; i<str.length();++i)
		if(str[i]!=32)
			break;
	
	if(i!=str.length())
		++cnt;
	
	for(; i<(int)str.length()-1;++i)
		if(str[i]==32 && str[i+1]!=32)
			++cnt;
	
	cout<<cnt<<endl;
	
	return 0;
}
