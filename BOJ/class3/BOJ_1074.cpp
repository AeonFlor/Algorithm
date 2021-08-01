#include <iostream>
#include <cmath>

using namespace std;

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};
int N,r,c,cnt=0;
bool isFind=false;

int check_div(int length,int x,int y)
{
	if(r<x+length)
	{
		if(c<y+length)
			return 0;
		else
			return 1;
	}
	
	else
	{
		if(c<y+length)
			return 2;
		else
			return 3;
	}
}

void recursive(int length, int x, int y)
{
	if(length==1)
		return;
	
	int div=check_div(length/2,x,y);
	x += length/2 * dx[div];
	y += length/2 * dy[div];
		
	cnt+=pow(length/2,2)*div;
	//cout<<"Length : "<<length<<" Div : "<<div+1<<" cord("<<x<<","<<y<<") -> "<<cnt<<'\n';
	recursive(length/2,x,y);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>N>>r>>c;
	recursive(pow(2,N),0,0);
	
	cout<<cnt<<'\n';
	
	return 0;
}
