#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string word;
	int alphabet[26];
	
	cin>>word;
	
	for(int i=0; i<26; ++i)
	{
		string::size_type res;
		res=word.find(char(i+97));
		if(res==string::npos)
			res=-1;
		alphabet[i]=res;
	}
	
	for(int i=0; i<26; ++i)
		cout<<alphabet[i]<<" ";
	
	cout<<'\n';
	
	return 0;
}
