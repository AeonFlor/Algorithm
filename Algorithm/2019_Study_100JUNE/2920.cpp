#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int n[8],c=0;

	cin>>n[0];

	for(int i=1; i<8; i++)
	{
		cin>>n[i];

		if(n[i]==n[i-1]+1)
			c++;
		else if(n[i]==n[i-1]-1)
			c--;
		else
			break;
	}

	if(c==7)
		cout<<"ascending"<<endl;
	else if(c==-7)
		cout<<"descending"<<endl;
	else
		cout<<"mixed"<<endl;

	return 0;
}