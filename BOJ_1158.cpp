#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> num(25,0);
	string input;
	int ans_idx,max=-1;
	
	cin>>input;
	
	for(int i=0;i<input.length();++i)
	{
		if(input[i]>96)
			input[i]-=32;
		input[i]-=65;
		++num[input[i]];
	}
	
	for(int i=0; i<26; ++i)
	{
		if(num[i]==max)
			ans_idx=26;
		else if(num[i]>max)
		{
			ans_idx=i;
			max=num[i];
		}
	}
	
	if(ans_idx==26)
		cout<<"?"<<'\n';
	else
		cout<<char(ans_idx+65)<<'\n';
	
	return 0;
}
