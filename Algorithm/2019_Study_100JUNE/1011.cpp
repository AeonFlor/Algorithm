#include <iostream>

using namespace std;

int main(void)
{
	int t;

	cin>>t;

	for(int i=0; i<t; i++)
	{
		int x,y,j,dis,flag=2, minus=2,count=3,share;
		cin>>x>>y;

		dis = y-x;

		if(dis<4)
			cout<<dis<<endl;

		else
		{
			dis-=2;

			if(dis >= flag)
			{
				share = dis/flag;
				
			}

			//minus += 2*flag;
		}

	}

	return 0;
}

/* 시간 초과
#include <iostream>

using namespace std;

int main(void)
{
	int t;

	cin>>t;

	for(int i=0; i<t; i++)
	{
		int x,y,dis,move=0, cnt=1;
		cin>>x>>y;

		dis = y-x-1;

		while(dis!=0)
		{
			if(move+1 <= dis)
			{
				dis -= ++move;
				cnt++;
			}

			else if(move <= dis)
			{
				dis -= move;
				cnt++;
			}

			else
			{
				dis -= --move;
				cnt++;
			}
		}

		cout<<cnt<<endl;

	}

	return 0;
}
*/

/* 반 나누는 것보다 더 좋은 풀이가 있을 것 같다.
#include <iostream>

using namespace std;

int main(void)
{
	int t;

	cin>>t;

	for(int i=0; i<t; i++)
	{
		int x,y,j,dis,cnt=0;
		cin>>x>>y;

		dis = (y-x)/2;
		
		for(j=1; 0<=dis-j; j++)
			dis-=j;

		cout<<j*2-1<<endl;
	}

	return 0;
}
*/