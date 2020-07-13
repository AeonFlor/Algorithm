#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, num=666;
	string snum;
	
	cin>>N;
	
	while(N!=0)
	{
		snum=to_string(num++);
		if(snum.find("666")!=std::string::npos)
			--N;
	}
	
	cout<<snum<<'\n';
	
	return 0;
}
