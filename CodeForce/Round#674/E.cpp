#include <iostream>
#include <vector>

using namespace std;

int minFront, minBack, max, value;
vector<int> tmpA, tmpB;

void calc(int A, int B)
{
	while(tmpB[B] && tmpA[A])
	{
		--tmpB[B];
		--tmpA[A];
		--value;
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, min, max;
	vector<int> a(3,0);
	vector<int> b(3,0);
	
	cin>>n;
	
	for(int i=0; i<3; ++i)
		cin>>a[i];
	
	for(int i=0; i<3; ++i)
		cin>>b[i];
	
	tmpA = a;
	tmpB = b;
	value = n;
	
	calc(0,2);
	calc(0,0);
	calc(1,0);
	calc(1,1);
	calc(2,1);
	calc(2,2);
	
	minFront = value;
	
	tmpA = a;
	tmpB = b;
	value = n;
	
	calc(2,2);
	calc(2,1);
	calc(1,1);
	calc(1,0);
	calc(0,0);
	calc(0,2);
	
	minBack = value;
	
	tmpA = a;
	tmpB = b;
	value = n;
	
	calc(0,1);
	calc(1,2);
	calc(2,0);
	
	if(minFront>minBack)
		minFront = minBack;
	
	cout<<minFront<<' '<<n-value<<'\n';
}
