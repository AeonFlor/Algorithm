#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> inorder, preorder;
stack<int> postorder;

void build_pre(int inPos, int prePos, int start, int end)
{
	if(postorder.empty())
		return;
	
	int root = postorder.top();
	int pos = find(inorder.begin()+inPos+1, inorder.begin()+end, root) - inorder.begin();
	
	cout<<"[Recursion] root is "<<root<<" ("<<start<<", "<<end<<") -> PrePos : "<<prePos<<'\n';
	cout<<"Right pos is "<<pos<<", and end is "<<end<<'\n';
	
	if(pos!=end)
	{
		cout<<"[R] root is "<<root<<" and prePos is "<<prePos<<'\n';
		preorder.insert(preorder.begin()+prePos+1, root);
		postorder.pop();
		
		build_pre(pos, prePos+1, inPos+1, end);
		cout<<"[R - out]\n";
		root = postorder.top();
	}
	
	pos = find(inorder.begin()+start, inorder.begin()+inPos, root) - inorder.begin();
	cout<<"Left pos is "<<pos<<", and inPos is "<<inPos<<'\n';
	
	if(pos!=inPos)
	{
		cout<<"[L] root is "<<root<<" and prePos is "<<prePos<<'\n';
		preorder.insert(preorder.begin()+prePos+1,root);
		postorder.pop();
		
		build_pre(pos, prePos, start, inPos);
		cout<<"[L - out]\n";
	}
}

int main(void)
{
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
	
	preorder.push_back(postorder.top());
	postorder.pop();
	
	build_pre(find(inorder.begin(), inorder.end(), preorder.front()) - inorder.begin(), 0, 0, n);
	
	for(int i=0; i<preorder.size(); ++i)
		cout<<preorder[i]<<' ';
	cout<<'\n';
}

/*
13
1 3 2 4 5 6 7 8 9 10 11 12 13
1 2 3 6 5 4 9 8 11 13 12 10 7
*/
