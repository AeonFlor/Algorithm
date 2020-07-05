#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string S;
	int T,R;
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cin>>R>>S;
		
		for(int j=0; j<S.length(); ++j)
			for(int k=0; k<R; ++k)
				cout<<S[j];
		
		cout<<'\n';
	}
	
	return 0;
}
