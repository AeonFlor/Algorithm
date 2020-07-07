#include <iostream>
#include <cmath>

using namespace std;

int dx[4] = {0,0,1,0};
int dy[4] = {0,1,-1,1};
int N,r,c,cnt=-1;

void recursive(int length, int x, int y)
{
	cout<<"recursive("<<length<<", "<<x<<", "<<y<<")\n";
		
	if(length == 1)
	{
		cnt++;
		
		if(x==r && y==c)
		{
			cout<<"Find it!!! -> "<<cnt<<'\n';
			return;
		}
		
		cout<<"?\n";
	}
	
	else
	{
		for(int i=0; i<4; ++i)
		{
			x += length/2 * dx[i%4];
			y += length/2 * dy[i%4];

			recursive(length/2,x,y);
		}
	}
}

int main(void)
{
	cin>>N>>r>>c;
	recursive(pow(2,N),0,0);
	
	cout<<cnt<<'\n';
	
	return 0;
}
