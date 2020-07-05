#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int rev_int(string s)
{
	reverse(s.begin(),s.end());
	return atoi(s.c_str());
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s[2];
	
	cin>>s[0]>>s[1];
	
	if(rev_int(s[0])>rev_int(s[1]))
		cout<<rev_int(s[0]);
	else
		cout<<rev_int(s[1]);
	
	return 0;
}
