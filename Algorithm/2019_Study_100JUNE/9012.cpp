#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int T,c,l,j;
	char c4se[20];
	cin>>T;

	for(int i=0; i<T; i++)
	{
		c=0;
		j=0;
		cin>>c4se;
		l = strlen(c4se);
		
		while(c>=0 && j<l)
		{
			if(c4se[j]=='(')
				c++;
			else if(c4se[j]==')')
				c--;
			j++;
		}

		if(c==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}

// 시작이 ) 이거나 끝이 ( 면 안 됨. 그런 NON-VPS
// 아예 c 가 0 미만으로 내려가면 안 된다.