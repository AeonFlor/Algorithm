#include <iostream>

using namespace std;	

int plane[128][128];
int blue=0, white=0;

void count(int x, int y, int n)
{
	bool check = true;
	
	for(int i=x; i<x+n; ++i)
		for(int j=y; j<y+n; ++j)
			if(plane[i][j]!=plane[x][y])
				check = false;
	
	if(check)
	{
		if(plane[x][y]==0)
			++white;
		else
			++blue;
	}
	
	else
	{
		count(x,y,n/2);
		count(x+n/2,y,n/2);
		count(x,y+n/2,n/2);
		count(x+n/2,y+n/2,n/2);
	}
}				

int main(void)
{
	int N;
	cin>>N;
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			cin>>plane[i][j];
	
	count(0,0,N);
	
	cout<<white<<'\n'<<blue<<'\n';
}
