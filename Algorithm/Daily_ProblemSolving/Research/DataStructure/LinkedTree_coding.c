#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void main() {
	TreeNode *n1 = (TreeNode*)malloc(sizeof(TreeNode));  // 동적할당
	TreeNode *n2 = (TreeNode*)malloc(sizeof(TreeNode));  // 동적할당
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));  // 동적할당
	TreeNode *n4 = (TreeNode*)malloc(sizeof(TreeNode));  // 동적할당

	n1->data = 50;  // n1 정보 입력
	n1->left = NULL;
	n1->right = NULL; 

	n2->data = 20;  // n2 정보 입력
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 40;  // n3 정보 입력
	n3->left = NULL;
	n3->right = NULL;

	n4->data = 30;  // n1 정보 입력
	n4->left = NULL;
	n4->right = NULL;

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;

	printf("n1 child: %d %d\n", n1->left->data, n1->right->data);
	printf("n2 child: %d\n", n2->left->data);
}