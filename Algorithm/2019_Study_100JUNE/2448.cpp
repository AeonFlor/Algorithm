#include <iostream>

using namespace std;

char plane[1025][6125];

void draw(int n)
{
	int i,j,k;

	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
			continue;
		plane[i][j]='*';

		for(k=j; k<j+i*2; k++)
		{
			if(i==n-1)
				plane[i][k]='*';
			else
				continue;
		}

		if(i!=0)
			plane[i][k]='*';
	}
}

int main(void)
{
	int n;
	
	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<6*n; j++)
			plane[i][j]=' ';

	draw(n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<6*n; j++)
			printf("%c",plane[i][j]);
		printf("\n");
	}

	return 0;
}