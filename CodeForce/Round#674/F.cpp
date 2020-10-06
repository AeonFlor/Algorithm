//55
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
const int MODULO = 1000000007;
vector<int> s;

// beforeA, beforeB 에 영향 많이 받는데 이건 안 됨.
// 함수의 인자랑 cache 랑 맞춰야 함.
int cache[200001][4];

int countSubseq(int index, int beforeA, int beforeB)
{
	if(index > n)
		return 0;
	
	int& res = cache[index][s[index]];
	
	if(res != -1)
		return res;
	
	cout<<"["<<index<<"] "<<beforeA<<", "<<beforeB<<'\n';
	
	if(s[index] == 0)
		return res = (countSubseq(index+1, beforeA+1, 0))%MODULO;
	
	else if(s[index] == 1)
		return res = (countSubseq(index+1, beforeA, beforeB+1))%MODULO;
	
	else if(s[index] == 2)
		return res = (min(beforeA, beforeB) + countSubseq(index+1, beforeA, beforeB))%MODULO;
	
	else if(s[index] == 3)
		return res = (countSubseq(index+1, beforeA+1, 0) + countSubseq(index+1, beforeA, beforeB+1) + beforeA*beforeB%MODULO + countSubseq(index+1, beforeA, beforeB))%MODULO;
	
	return 0;
}

int main(void)
{
	fill(&cache[0][0], &cache[200000][4], -1);
	
	char input;
	
	cin>>n;
	
	for(int i=0; i<n; ++i)
	{
		cin>>input;
		
		if(input == 'a')
			s.push_back(0);
		
		else if(input == 'b')
			s.push_back(1);
		
		else if(input == 'c')
			s.push_back(2);
		
		else if(input == '?')
			s.push_back(3);
	}
	
	cout<<countSubseq(0, 0, 0)<<'\n';
}
