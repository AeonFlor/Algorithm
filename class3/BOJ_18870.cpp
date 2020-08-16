#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	int N, input;
	set<int> coor;
	vector<int> seq;
	
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		coor.insert(input);
		seq.push_back(input);
	}
	
	for(int i=0; i<seq.size(); ++i)
	{
		cout<<coor.find(seq[i])-coor.begin()<<' ';
	}
	cout<<'\n';
}
