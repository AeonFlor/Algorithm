#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> arr(5);
	string line;
	
	for(int i=0; i<5; ++i)
	{
		getline(cin,line);
		arr[i]=line;
	}
	
	for(int i=0; i<15; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			if(arr[j].length()>i)
				cout<<arr[j][i];
		}
	}
}

// printf 와 scanf 로도 풀 수 있었다.
// scanf 로만 풀 경우 char arr[5][16] 으로 선언하고 scanf("%s", arr[i]); 로 for 문 돌리면 됐다.
// 그리고 printf 의 경우 scanf 를 쓸 때 마지막에 자동으로 null 이 들어가므로 if(arr[j][i]) 있는지 판단하면 된다.

// 이렇게 되면 vector 를 쓰지않고 string 배열로만 풀 수 있었다.
