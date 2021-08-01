#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int N,M,cnt=0;
	string temp;
	vector<string> name;
	vector<string> result;
	
	cin>>N>>M;
	
	for(int i=0; i<N+M; ++i)
	{
		cin>>temp;
		name.push_back(temp);
	}
	
	sort(name.begin(), name.end());
	
	for(int i=0; i<name.size()-1; ++i)
	{
		if(name.at(i)==name.at(i+1))
		{
			cnt++;
			result.push_back(name.at(i));
		}
	}
	
	cout<<cnt<<endl;
	
	for(auto i:result)
		cout<<i<<endl;
	
	return 0;
}
