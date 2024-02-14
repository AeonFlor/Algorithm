#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n,x,max=0;
	float res=0;

	cin>>n;

	vector<int> grade;

	for(int i=0; i<n; i++)
	{
		cin>>x;
		grade.push_back(x);
	}

	max=*max_element(grade.begin(),grade.end());

	for(int i=0; i<n; i++)
	{
		res+=grade.back()/float(max)*100;
		grade.pop_back();
	}

	printf("%f\n",res/n);

	return 0;
}
// 26: float/int 하면 그냥 몫만 따진다. 따라서 형변환 해줘야 한다.
// 22: iterator 를 이용하여 grade vector 에서 가장 큰 값이 iterator 를 반환. 따라서. * 를 통해 iterator 의 값에 접근해야 한다.

