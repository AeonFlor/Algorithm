#include <iostream>

using namespace std;

void draw(int n) //한 변이 n 개인 삼각형 그리기
{
	int i,j;

	for(i=0; i<n; i++)
	{
		for(j=1; j<n-i; j++)
			printf(" ");
		
		printf("*");

		for(j=0; j<i*2-1; j++)
		{
			if(i!=n-1)
				printf(" ");
			else
				printf("*");
		}

		if(i!=0)
			printf("*\n");
		else
			printf("\n");
	}
}

int main(void)
{
	int n;
	
	cin>>n;

	draw(n);

	return 0;
}