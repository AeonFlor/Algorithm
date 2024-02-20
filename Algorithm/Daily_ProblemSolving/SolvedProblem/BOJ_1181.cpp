#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	string word;
	cin>>N;
	multimap<int,string> words;
	
	for(int i=0; i<N; ++i)
	{
		cin>>word;
		words.insert(pair<int,string>(word.size(),word));
	}
	
	multimap<int,string>::iterator iter1;
	multimap<int,string>::iterator iter2;
	
	for(int i=1; i<51; ++i)
	{
		iter1 = words.find(i);
		iter2 = words.find(i+1);
		for(multimap<int,string>::iterator iter=iter1; iter1!=iter2; ++iter)
		{
			cout<<iter->second<<'\n';
		}
	}
	cout<<'\n';
	
	return 0;
}

/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/
