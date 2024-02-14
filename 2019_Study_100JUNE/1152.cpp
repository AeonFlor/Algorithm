#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string input;
	int cnt=0;

	getline(cin,input);

	while(input[0]==' ') // 앞 공백 있으면 제거
		input.erase(0,1);

	while(input[input.length()-1]==' ') // 뒤 공백 있으면 제거
		input.erase(input.length()-1,input.length());

	for(int i=0; i<input.length(); i++) // 공백 개수 세는 반복문
	{
		if(input[i]==' ')
			cnt++;
	}

	if(!input.empty())
		cout<<cnt+1<<endl; // 단어수 = 공백 개수 + 1
	else
		cout<<"0"<<endl;

	return 0;
}

// 16 행에 find 로 찾으면 중간 공백으로 인식하기에 오른쪽부터 판단하는 rfind 함수를 사용해서 오른쪽 공백을 인식해야 한다.
// Test 한 코드들은 제출할 때 빼자..
// 여러 반례를 찾자 EX) 공백을 입력할 경우

/*
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string input;
	int cnt=0;

	getline(cin,input);

	while(input.find(' ')==0) // 일단 공백을 찾고 index 가 0 인지 판단하기에 0 에서만 판단하도록 바꿨다.
		input.erase(0,1);

	while(input.rfind(' ')==input.length()-1)
		input.erase(input.length()-1,input.length());

	for(int i=0; i<input.length(); i++)
	{
		if(input[i]==' ')
			cnt++;
	}

	cout<<cnt+1<<endl;

	return 0;
}
*/