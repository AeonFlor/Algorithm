#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num1,num2,num_gcd;
	
	cin>>num1>>num2;
	
	num_gcd = gcd(num1,num2);
	
	cout<<num_gcd<<'\n'<<num1*num2/num_gcd<<'\n';
	
	return 0;
}
