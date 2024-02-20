#include <iostream>

using namespace std;

char plane[3073][18438];

void draw(int n, int x, int y)
{
	if( n == 3 )
	{
		plane[x][y]='*';
		plane[x+1][y-1]='*';
		plane[x+1][y+1]='*';
		plane[x+2][y-2]='*';
		plane[x+2][y-1]='*';
		plane[x+2][y]='*';
		plane[x+2][y+1]='*';
		plane[x+2][y+2]='*';
	}

	else
	{
		draw(n/2,x,y);
		draw(n/2,x+(n/2),y-(n/2));
		draw(n/2,x+(n/2),y+(n/2));
	}
}

int main(void)
{
	int n;

	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<6*n; j++)
			plane[i][j]=' ';

	draw(n, 0, n-1);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n-1; j++)
			printf("%c",plane[i][j]);
		printf("\n");
	}

	return 0;
}