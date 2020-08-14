#include <iostream>
#include <vector>

using namespace std;	

vector<pair<char,char>> vertex(26,make_pair('.','.'));

void preorder(char v)
{
	cout<<v;
	
	if(vertex[v-65].first!='.')
		preorder(vertex[v-65].first);
	
	if(vertex[v-65].second!='.')
		preorder(vertex[v-65].second);
}

void inorder(char v)
{
	if(vertex[v-65].first!='.')
		inorder(vertex[v-65].first);
	
	cout<<v;
	
	if(vertex[v-65].second!='.')
		inorder(vertex[v-65].second);
}

void postorder(char v)
{
	if(vertex[v-65].first!='.')
		postorder(vertex[v-65].first);
	
	if(vertex[v-65].second!='.')
		postorder(vertex[v-65].second);
	
	cout<<v;
}

int main(void)
{
	int N;
	char root, left, right;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>root>>left>>right;
		vertex[root-65].first = left;
		vertex[root-65].second = right;
	}
	
	preorder('A');
	cout<<'\n';
	inorder('A');
	cout<<'\n';
	postorder('A');
	cout<<'\n';
}
