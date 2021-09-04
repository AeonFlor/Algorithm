#include <iostream>

using namespace std;

struct Node
{
	int num;
	
	Node* left;
	Node* right;
};

Node* push(Node* node, int num)
{
	if (node == NULL)
	{
		node = new Node();
		node->num = num;
		node->left = NULL;
		node->right = NULL;
	}

	else
	{
		if (num < node->num)
		{
			node->left = push(node->left, num);
		}

		else
		{
			node->right = push(node->right, num);
		}
	}

	return node;
}

void postorder(Node* node)
{
	if (node->left != NULL)
		postorder(node->left);

	if (node->right != NULL)
		postorder(node->right);

	cout << node->num << '\n';
}

int main(void)
{
	int input;

	Node* root = NULL;

	while (cin >> input)
	{
		root = push(root, input);
	}

	postorder(root);
}

// 좋은 코드 참조 : https://www.acmicpc.net/source/32954636