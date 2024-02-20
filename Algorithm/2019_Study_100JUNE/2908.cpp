#include <iostream>

using namespace std;

int reverse(int x)
{
	int h,o;
	o=x/100;
	h=x%10*100;
	x=h+o+x/10%10*10;

	return x;
}

int main(void)
{
	int x1,x2;

	cin>>x1>>x2;

	x1=reverse(x1);
	x2=reverse(x2);

	cout<<((x1>x2)?x1:x2)<<endl;

	return 0;
}

// 출력에 3항 연산자 넣으면 () 로 감싸도록 하자!