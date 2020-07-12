#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,cnt;
	string input;
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		cnt=0;
		
		for(int j=0; j<input.size() && cnt>=0; ++j)
		{
			if(input[j]=='(')
				++cnt;
			else if(input[j]==')')
				--cnt;
		}
		
		if(cnt==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	
	return 0;
}
