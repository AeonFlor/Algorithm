#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int score,T,delta;
	string errata;
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cin>>errata;
		
		score=delta=0;
		
		for(int j=0; j<errata.size(); ++j)
		{
			if(errata[j]=='O')
				score+=(++delta);
			else
				delta=0;
		}
		
		cout<<score<<'\n';
	}
	
	return 0;
}
