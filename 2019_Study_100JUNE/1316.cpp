#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int n,flag,cnt=0;
	string word;

	cin>>n;

	for(int i=0;i<n;i++)
	{
		bool alp[26]= { false };
		flag = 1;

		cin>>word;

		alp[word[0]-97] = true;

		for(int j=1; j<word.length(); j++)
		{
			if(!alp[word[j]-97] || word[j]==word[j-1])
				alp[word[j]-97]=true;

			else
			{
				flag=0;
				break;
			}
		}

		if(flag)
			cnt++;
	}

	cout<<cnt<<endl;

	return 0;
}

// bool 형은 false 로 초기화
// 변수 초기화 위치 잘 따져보자.