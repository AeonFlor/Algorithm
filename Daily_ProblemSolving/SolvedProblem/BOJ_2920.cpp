#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int scale[8];
	bool mixed=false;
	
	for(int i=0; i<8; ++i)
		cin>>scale[i];
	
	for(int i=0; i<7; ++i)
		if(pow(scale[i]-scale[i+1],2)!=1)
		{
			mixed = true;
			break;
		}
			
	if(mixed)
		cout<<"mixed\n";
	else if(scale[0]==1)
		cout<<"ascending\n";
	else
		cout<<"descending\n";
	
	return 0;
}
