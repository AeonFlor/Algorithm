#include <iostream>

using namespace std;

int main(void)
{
	double a,b;

	cin>>a>>b;

	cout<<fixed;// 소수점 아래 자리수 조정
	cout.precision(9);// 9자리 까지
	cout<<a/b<<endl;

	return 0;
}