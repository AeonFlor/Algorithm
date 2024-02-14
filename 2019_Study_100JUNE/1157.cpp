#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string input;
	int alphabet[26]={0,};
	int max=-1,max_cnt=0;
	char res;

	cin>>input;

	for(int i=0; i<input.length(); i++)
	{
		if(input[i]>96)
			input[i]-=32;
		alphabet[input[i]-65]+=1;
	}

	for(int i=0; i<26; i++)
	{
		if(alphabet[i]>max)
		{
			max=alphabet[i];
			res=char(i+65);
			max_cnt=1;
		}
		else if(alphabet[i]==max)
			max_cnt++;
		else
			continue;
	}

	if(max_cnt==1)
		cout<<res<<endl;
	else
		cout<<"?"<<endl;

	return 0;
}