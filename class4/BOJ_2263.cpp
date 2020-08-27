#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> inorder, preorder;
stack<int> postorder;

void build_pre(int prePos, int start, int end)
{
	if(postorder.empty())
		return;
	
	if(start==end)
		return;
	
	int root = postorder.top();
	postorder.pop();
	
	int pos = find(inorder.begin()+start, inorder.begin()+end, root) - inorder.begin();
	
	if(pos==end)
		return;
	
	preorder.insert(preorder.begin()+prePos, root);
	
	build_pre(prePos+1, pos+1, end);
	
	build_pre(prePos+1, start, pos);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, input;
	
	cin>>n;
	
	for(int i=0; i<n; ++i)
	{
		cin>>input;
		inorder.push_back(input);
	}
	
	for(int i=0; i<n; ++i)
	{
		cin>>input;
		postorder.push(input);
	}
	
	build_pre(0, 0, n);
	
	for(int i=0; i<preorder.size(); ++i)
		cout<<preorder[i]<<' ';
	cout<<'\n';
}
