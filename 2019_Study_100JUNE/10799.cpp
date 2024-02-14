#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	stack<char> line;
	char *c4se = new char[100000]; // 이러면 동적 할당 쓰는 이유가 없자너..
	int shard = 0;
	
	cin>>c4se;

	for(int i=0; i<strlen(c4se); i++)
	{
		if(c4se[i]=='(' && c4se[i+1]==')')
		{
			shard+=line.size();
			i++;
		}

		else if(c4se[i]=='(')
			line.push('(');

		else if(c4se[i]==')')
		{
			line.pop();
			shard++;
		}
	}

	cout<<shard<<endl;

	delete[] c4se;
}

/*
	for(int i = 0; i<10; i++)
	{
		if(i==5)
			i++;
		cout<<i<<endl;
	}

	return 0;
*/
// 반복문 내부에서 반복 변수(?) 접근 가능.