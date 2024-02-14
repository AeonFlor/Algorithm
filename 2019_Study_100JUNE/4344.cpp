#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float ave;

bool isOver(int x)
{
	return (x>ave);
}

int main(void)
{
	int c,n,x;
	vector<int> grade;
	
	cin>>c;

	for(int i = 0; i<c; i++)
	{
		ave=0;
		cin>>n;

		for(int j = 0; j<n; j++)
		{
			cin>>x;
			grade.push_back(x);
			ave+=x;
		}
		ave/=float(n);
		printf("%.3f%%\n",float(count_if(grade.begin(),grade.end(),isOver))/float(n)*100);
		grade.clear();
	}

	return 0;
}

// 새로 배운 것 : count_ if (조건 함수 어떻게 구성되는 지 다시 볼 필요 있다.)