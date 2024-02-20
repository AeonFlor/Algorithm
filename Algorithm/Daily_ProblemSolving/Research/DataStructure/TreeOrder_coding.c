#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 26, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void inorder(TreeNode* root){
	if (root!=NULL){
		inorder(root->left);
		printf("%d -> ",root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root){
	if (root != NULL) {
		printf("%d -> ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root){
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d -> ", root->data);
	}
}

void main() {
	printf("inorder: ");
	inorder(root);
	printf("\n");
	
	printf("preorder: ");
	preorder(root);
	printf("\n");
	
	printf("postorder: ");
	postorder(root);
	printf("\n");
}