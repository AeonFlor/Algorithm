#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, num, sum=0;
	
	cin>>N;
	cin>>num;
	
	while(num)
	{
		sum+=num%10;
		num/=10;
	}
	
	cout<<sum<<'\n';
	
	return 0;
}
