#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
	friend class Tree<T>; // Tree always can access TreeNode;

private: // Define Node Element
	T data;
	TreeNode* left;
	TreeNode* right;
	
public: // Define Node Method
	TreeNode(T data, TreeNode* left = NULL, TreeNode* right = NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <typename T>
class Tree
{
	
private:
	TreeNode<T>* root;

public:
	Tree(T data = 0)
	{
		root = new TreeNode<T>(data);
	}
	
	TreeNode<T>* getRoot()
	{
		return root;
	}
	
	TreeNode<T>* CreateNode(int data)
	{
		TreeNode<T>* node = new TreeNode<T>(data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	
	TreeNode<T>* SearchNode(TreeNode<T>* node, T data)
	{
		if(node==NULL)
			return NULL;
		
		if(data==node->data)
			return node;
		
		else if(data<node->data)
			SearchNode(node->left,data);
		
		else
			SearchNode(node->right,data);
	}
	
	bool CheckDuplicates(T data)
	{
		if(SearchNode(root,data)!=NULL)
			return true;
		else
			return false;
	}
	
	void InsertNode(TreeNode<T>* node)
	{
		TreeNode<T>* current = root;
		
		while(true)
		{
			if(node->data<current->data)
			{
				if(current->left != NULL)
					current=current->left;
				else
					break;
			}

			else if(current->data<node->data)
			{
				if(current->right != NULL)
					current=current->right;
				else
					break;
			}
		}
		
		if(node->data<current->data)
			current->left=node;
		else
			current->right=node;
	}
	
	void DeleteNode(TreeNode<T>* node,T data)
	{
		if(node==NULL)
			return;
		
		if(node->data==data)
		{
			if(node->left!=NULL)
			{
				DeleteNode(node->left,data);
				node->left = NULL;
			}
			if(node->right!=NULL)
			{
				DeleteNode(node->right,data);
				node->right = NULL;
			}
		}
		
		else if(node->data<data)
			DeleteNode(node->right,data);
		
		else
			DeleteNode(node->left,data);

		delete node;
	}
	
	void PrintTree(TreeNode<T>* node, TreeNode<T>* current)
	{
		if(node != NULL)
		{
			if(node==current)
				cout<<"->"<<node->data<<" ";
			else
				cout<<node->data<<" ";
			PrintTree(node->left,current);
			PrintTree(node->right,current);
		}
	}
	
	//Admin Command
	void BuildTree()
	{
		InsertNode(new TreeNode<int>(7));
        InsertNode(new TreeNode<int>(3));
        InsertNode(new TreeNode<int>(9));
        InsertNode(new TreeNode<int>(13));
        InsertNode(new TreeNode<int>(11));
        InsertNode(new TreeNode<int>(15));
	}
};

int main(void)
{
	int input, data;
	
	cout<<"Please input root data : ";
	cin>>input;
	Tree<int> tree(input);
	TreeNode<int>* current = tree.getRoot();
	TreeNode<int>* temp;
	
	do
	{
		cout<<"\n==== < Tree > ====\n";
		cout<<"1. Print Tree (Preorder)\n";
		cout<<"2. Insert Node\n";
		cout<<"3. Delete Node\n";
		cout<<"4. Move Current\n"; 
		cout<<"0. Quit\n";
		cout<<"==================\nInput : ";
		cin>>input;
		
		switch(input)
		{
			case 1:
				tree.PrintTree(tree.getRoot(),current);
				break;
				
			case 2:
				cout<<"Input Data : ";
				cin>>data;
				
				if(tree.CheckDuplicates(data))
				{
					cout<<"[Fail] Already Tree include Node which has "<<data<<".\n";
				}
				
				else
				{
					tree.InsertNode(tree.CreateNode(data));
					cout<<"[Success] Node which has "<<data<<" is created\n";
				}
				break;
				
			case 3:
				cout<<"Input Data : ";
				cin>>data;
				
				if(!tree.CheckDuplicates(data))
				{
					cout<<"[Fail] Can't Find Node which has "<<data<<".\n";
				}
				
				else
				{
					tree.DeleteNode(tree.getRoot(),data);
					cout<<"[Success] Node which has "<<data<<" is deleted\n";
				}
				break;
				
			case 4:
				cout<<"Input Data : ";
				cin>>data;
				
				 temp = tree.SearchNode(tree.getRoot(),data);
				
				if(temp==NULL)
				{
					cout<<"[Fail] Can't Find Node which has "<<data<<".\n";
				}
				
				else
				{
					current = temp;
					cout<<"[Success] Current Node is changed to Node which has "<<data<<"\n";
				}
				break;
				
			case 0:
				cout<<"Bye Bye~\n";
				break;
				
			case 9:
				tree.BuildTree();
				break;
				
			default:
				cout<<"[Error] Wrong Input!\n";
		}
		
	}while(input!=0);
	
	return 0;
}
