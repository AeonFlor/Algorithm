#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, sum=0;	
	cin>>N;
	
	string num,temp;
	cin>>num;
	
	for(int i=0; i<N; ++i)
	{
		temp = num[i];
		sum+=atoi(temp.c_str());
	}
	
	cout<<sum<<'\n';
	
	return 0;
}
