#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,cnt,age,priority=1;
	string name;
	vector<tuple<int,int,string>> list;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>age>>name;
		list.push_back(make_tuple(age,priority++,name));
	}
	
	sort(list.begin(),list.end());
	
	for(int i=0; i<N; ++i)
		cout<<get<0>(list[i])<<" "<<get<2>(list[i])<<'\n';
	
	return 0;
}
