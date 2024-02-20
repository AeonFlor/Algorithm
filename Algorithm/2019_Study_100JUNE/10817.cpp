#include <iostream>

using namespace std;

int main(void)
{
	int a,b,c,res;

	cin>>a>>b>>c;

	res=(a>b) ? ((b>c) ? b:((a>c) ? c:a)):((a>c) ? a:((b>c) ? c:b));
	cout<<res<<"\n";

	return 0;
}