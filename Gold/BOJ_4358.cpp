#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;

const int STR = 95;

struct TrieNode
{
	TrieNode* children[STR];
	bool terminal;
	int count;
	
	TrieNode():terminal(false),count(0)
	{
		for(int i=0; i<STR; ++i)
			children[i] = nullptr;
	}
	
	~TrieNode()
	{
		for(int i=0; i<STR; ++i)
			if(children[i] != nullptr)
				delete children[i];
	}
	
	void insert(char* s)
	{
		if(*s == '\0')
		{
			terminal = true;
			++count;
		}
		
		else
		{
			int next = *s - 32;
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(s+1);
		}
	}
	
	int find(char* s)
	{
		if(terminal && *s == '\0')
			return count;
		
		int next = *s - 32;
		return children[next]->find(s+1);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int total = 0;
	char treeSpecies[30];
	set<string> treeList;
	
	TrieNode* root = new TrieNode();
	
	while(cin.getline(treeSpecies, 30))
	{
		treeList.insert(treeSpecies);
		root->insert(treeSpecies);
		++total;
	}
	
	for(auto iter = treeList.begin(); iter != treeList.end(); ++iter)
	{
		string s = *iter;
		
		double rate = (double)root->find(strcpy(treeSpecies,s.c_str()))/(double)total * 100;
		
		cout<<fixed;
		cout.precision(4);
		cout<<s<<' '<<rate<<'\n';
	}
	
	delete root;
}
