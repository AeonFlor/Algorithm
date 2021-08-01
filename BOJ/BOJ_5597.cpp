#include <iostream>

using namespace std;

int main(void)
{
	bool RB[31]={false,};
	int n;
	
	for(int i=1; i<29; ++i)
	{
		cin>>n;
		RB[n]=true;
	}
	
	for(int i=1; i<31; ++i)
		if(!RB[i])
			cout<<i<<endl;
	
	return 0;
}
