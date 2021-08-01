#include <iostream>
#include <cstring>

using namespace std;

int cache[101][101];
string w,s;

int correspond_check(int wi, int si)
{
	int& ret = cache[wi][si];
	
	if(ret!=-1)
		return ret;
	
	if((w[wi]=='?' || w[wi]==s[si]) && wi<w.size() && si<s.size())
		// * 일 때 for 문 안 쓰려면 이런 식으로 구현해야함.
		return ret = correspond_check(wi+1,si+1);
	
	if(wi==w.size()) // si 랑 같이 확인 하면 다른 경우 논리적으로 지나칠 수도 있음.
		return ret = (si == s.size());
	
	if(w[wi]='*')//위에서 범위 check 다 하므로 안 해도 됨. // s 범위는 확인해줘야 됨.
		if((si<s.size() && correspond_check(wi,si+1)) || correspond_check(wi+1,si))
			return ret = 1;
	 
	return ret=0;
}

int main(void)
{
	int c,n;
	
	cin>>c;
	
	while(c--)
	{
		cin>>w;
		cin>>n;
		
		string file[n];
		
		for(int i=0; i<n; ++i)
			cin>>file[i];
		
		for(int i=0; i<n; ++i)
		{
			s=file[i];
			memset(cache,-1,sizeof(cache));
			if(correspond_check(0,0))
				cout<<file[i]<<"\n";
		}
	}
}
