#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

vector<int> comb(int n, int m)
{
	cout<<"[Dive! ("<<n<<", "<<m<<")]\n";
	
	vector<int> res;
	vector<int> tmp;
	
	if(m==0)
	{
		for(int i=n; i>=0; --i)
			res.push_back(1<<i);
	}
	
	else
		for(int i=n; i>=m; --i)
		{
			tmp.clear();
			tmp = comb(i-1,m-1);
			cout<<"[OUT]\n";

			for(int j=0; j<tmp.size(); ++j)
				res.push_back(1<<i + tmp[j]);
		}
	
	// bitset 부분 프로그램 동작할 때 사이즈 지정해주기 때문에 runtime 에서 설정된 constant 못 씀.
	for(int i=0; i<res.size(); ++i)
		cout<<bitset<8>(res[i])<<'\n';
	
	return res;
}

int main(void)
{
	int N, M, input, num_store=0, num_house=0;
	vector<pair<int,int>> store_coor;
	vector<pair<int,int>> house_coor;
	
	cin>>N>>M;
	
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=N; ++j)
		{
			cin>>input;

			if(input==1)
				house_coor.push_back(make_pair(j,i));
			
			else if(input==2)
				store_coor.push_back(make_pair(j,i));
		}
	}
	
	int dist[house_coor.size()][store_coor.size()];
	
	for(int i=0; i<store_coor.size(); ++i)
		for(int j=0; j<house_coor.size(); ++j)
			dist[j][i] = abs(store_coor[i].first - house_coor[j].first) + abs(store_coor[i].second - store_coor[j].second);
	
	vector<int> combination = comb(store_coor.size()-1,M-1);
	
}

/*
5 3
0 2 0 1 2
0 1 0 0 0
0 0 2 0 1
1 1 0 0 2
2 0 1 0 1
*/
