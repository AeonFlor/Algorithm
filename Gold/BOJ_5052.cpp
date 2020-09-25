#include <iostream>

using namespace std;

const int NUM = 10;

struct TrieNode
{
	TrieNode* children[NUM];
	bool terminal;
	
	TrieNode():terminal(false)
	{
		for(int i=0; i<NUM; ++i)
			children[i] = nullptr;
	}
	
	~TrieNode()
	{
		for(int i=0; i<NUM; ++i)
			if(children[i] != nullptr)
				delete children[i];
	}
	
	void insert(char* s)
	{
		if(*s == '\0')
			terminal = true;
		
		else
		{
			int next = *s - '0';
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(s+1);
		}
	}
	
	int find(char* s)
	{
		if(*s == 0)
			return 0;
		
		if(terminal)
			return 1;
		
		int next = *s -'0';
		return children[next]->find(s+1);
	}
};

int main(void)
{
	int t, n;
	char phoneNum[10001][11];
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		TrieNode* root = new TrieNode();
		
		for(int i=0; i<n; ++i)
		{
			cin>>phoneNum[i];
			root->insert(phoneNum[i]);
		}
		
		bool flag = true;
		
		for(int i=0; i<n; ++i)
			if(root->find(phoneNum[i]))
			{
				flag = false;
				break;
			}
		
		if(flag)
			cout<<"YES\n";
		
		else
			cout<<"NO\n";
		
		delete root;
	}
}
