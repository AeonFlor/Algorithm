#include <iostream>

using namespace std;

int main(void)
{
	int ans=0;
	char board[8][8];
	
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			cin>>board[i][j];
	
	/*
	for(int i=0; i<8; ++i)
	{
		for(int j=0; j<8; ++j)
			printf("%c",board[i][j]);
		printf("\n");
	}
	*/
	
	for(int i=0; i<8; ++i)
		for(int j=i%2; j<8; j+=2)
		{
			if(board[i][j]=='F')
			{
				ans++;
			}
		}
	
	printf("%d",ans);
}

/*
1 3 5 7
0 2 4 6
	
(0 2 4 6) + row num%2 -> 하얀 칸 위치
*/
