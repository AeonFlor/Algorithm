#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int N, M, ans=0, pSize;
	string S, P;
	
	cin>>N>>M>>S;
	
	for(int i=0; i<N; ++i)
		P+="IO";
	P+='I';
	
	pSize = P.size();
	
	for(int begin=0; begin <= M - pSize;)
	{
		int i, next;
		bool isMatched = true;
		
		for(i=0; i<pSize; ++i)
			if(S[begin+i] != P[i])
			{
				isMatched = false;
				break;
			}
		
		if(isMatched)
		{
			next = begin + i - 1;
			
			++ans;
			
			while(true)
			{
				if(next+2 < S.size() && S.substr(next+1,2) == "OI")
				{
					++ans;
					next+=2;
				}
				
				else
				{
					begin = next+1;
					break;
				}
			}
		}
		
		else
			++begin;
	}
	
	
	cout<<ans<<'\n';
}
