#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;

typedef struct treeNode* treePointer;

typedef struct treeNode {
	treePointer leftChild;
	element data;
	int bf;
	treePointer rightChild;
} treeNode;

void preorder(treePointer root){
	if (root){
		printf("%d ", root->data.key);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void leftRotation(treePointer* parent, int* unbalanced) {
	treePointer grandChild, child;
	child = (*parent)->leftChild;

	if (child->bf == 1) {
		/* LL Rotation */
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}

	else {
		/* LR Roatation */
		grandChild = child->rightChild;
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;

		switch (grandChild->bf) {
			case 1:
				(*parent)->bf = -1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = child->bf = 0;
				break;
			case -1:
				(*parent)->bf = 0;
				child->bf = 1;
				break;
		}
		*parent = grandChild;
	}

	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

void rightRotation(treePointer* parent, int* unbalanced) {
	treePointer grandChild, child;
	child = (*parent)->rightChild;

	if (child->bf == -1) {
		/* RR Rotation */
		(*parent)->rightChild = child->leftChild;
		child->leftChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}

	else {
		/* RL Rotataion */
		grandChild = child->leftChild;
		child->leftChild = grandChild->rightChild;
		grandChild->rightChild = child;
		(*parent)->rightChild = grandChild->leftChild;
		grandChild->leftChild = *parent;
		switch (grandChild->bf) {
			case -1:
				(*parent)->bf = 1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = child->bf = 0;
				break;
			case 1:
				(*parent)->bf = 0;
				child->bf = -1;
				break;
		}
		*parent = grandChild;
	}

	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

void avlInsert(treePointer* parent, element x, int* unbalanced) {
	if (!*parent) { /*insert element into null tree*/
		*unbalanced = TRUE;
		*parent = (treePointer)malloc(sizeof(treeNode));
		(*parent)->leftChild = (*parent)->rightChild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}

	else if (x.key < (*parent)->data.key) {
		avlInsert(&((*parent)-> leftChild), x, unbalanced);
		if (*unbalanced) {
			/*left branch has grown higher*/
			switch ((*parent)->bf) {
				case -1:
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
				case 0:
					(*parent)->bf = 1;
					break;
				case 1:
					leftRotation(parent, unbalanced);
					break;
			}
		}
	}

	else if(x.key > (*parent)->data.key){
		avlInsert(&((*parent)-> rightChild), x, unbalanced);
		if(*unbalanced){
			/*right barnch has grown higher*/
			switch((*parent)->bf){
				case 1:
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
				case 0:
					(*parent)->bf = -1;
					break;
				case -1:
					rightRotation(parent, unbalanced);
					break;
			}
		}
	}

	else {
		*unbalanced = FALSE;
		printf("The key is already in the tree\n");
	}
}

int avlFindMin(treePointer* parent){ /* Find minimum node */
	treePointer current, pre;

	if ((*parent)->leftChild){
		current = pre = (*parent)->leftChild;
		while (current != NULL){
			pre = current;
			current = current->rightChild;
		}
	}

	else{
		current = pre = (*parent)->rightChild;
		while (current != NULL){
			pre = current;
			current = current->leftChild;
		}
	}

	return pre->data.key;
}

int isLeaf(treePointer* parent){
	if ((*parent)->leftChild || (*parent)->rightChild)
		return FALSE;

	return TRUE;
}

void delLeftRotation(treePointer* parent, int* unbalanced){
	treePointer grandChild, child;
	child = (*parent)->leftChild;

	if (child->bf == 1){
		/* LL Rotation */
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
		(*parent)->bf = 0;
	}

	else{
		/* LR Roatation */
		grandChild = child->rightChild;
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;

		switch(grandChild->bf){
			case -1:
				(*parent)->bf = -1;
				child->bf = 0;
				break;
			case 1:
				(*parent)->bf = child->bf = 0;
				break;
			case 0:
				(*parent)->bf = 0;
				child->bf = 1;
				grandChild->bf = 1;
				break;
		}
		*parent = grandChild;
	}

	*unbalanced = TRUE;
}
void delRightRotation(treePointer* parent, int* unbalanced){
	treePointer grandChild, child;
	child = (*parent)->rightChild;

	if (child->bf == -1){
		/* RR Rotation */
		(*parent)->rightChild = child->leftChild;
		child->leftChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
		(*parent)->bf = 0;
	}

	else{
		/* RL Roatation */
		grandChild = child->leftChild;
		child->leftChild = grandChild->rightChild;
		grandChild->rightChild = child;
		(*parent)->rightChild = grandChild->leftChild;
		grandChild->leftChild = *parent;

		switch(grandChild->bf){
			case -1:
				(*parent)->bf = 1;
				child->bf = 0;
				break;
			case 1:
				(*parent)->bf = child->bf = 0;
				break;
			case 0:
				(*parent)->bf = 0;
				child->bf = -1;
				grandChild->bf = -1;
				break;
		}
		*parent = grandChild;
	}

	*unbalanced = TRUE;
}

void avlDelete(treePointer* parent, element x, int* unbalanced){
	int parentKey;

	if (!*parent){ /*No Node in tree*/
		*unbalanced = FALSE;
		printf("The Tree is empty or NOT Found\n\n");
		return;
	}

	parentKey = (*parent)->data.key;

	if ((x.key == (*parent)->data.key) && isLeaf(parent)){
		free(*parent);
		*parent = NULL;
		*unbalanced = TRUE;
		return;
	}

	if ((x.key == (*parent)->data.key) && !isLeaf(parent)){
		parentKey = (*parent)->data.key;
		x.key = avlFindMin(parent);
		(*parent)->data.key = x.key;
	}
	
	if (x.key < parentKey){
		avlDelete(&(*parent)->leftChild , x, unbalanced);
		if (*unbalanced){
			switch ((*parent)->bf){
				case 1:
					(*parent)->bf = 0;
					break;
				case 0:
					(*parent)->bf = -1;
					*unbalanced = FALSE;
					break;
				case -1:
					delRightRotation(parent, unbalanced);
					*unbalanced = TRUE;
					break;
			}
		}
	}

	else if (x.key > parentKey){
		avlDelete(&(*parent)->rightChild , x, unbalanced);
		if (*unbalanced){
			switch ((*parent)->bf){
				case -1:
					(*parent)->bf = 0;
					break;
				case 0:
					(*parent)->bf = 1;
					*unbalanced = FALSE;
					break;
				case 1:
					delLeftRotation(parent, unbalanced);
					*unbalanced = TRUE;
					break;

			}
		}
	}
}

void menu() {
	printf("Insert 'i'\n");
	printf("Delete 'd'\n");
	printf("Preorder Show 's'\n");
	printf("EXIT 'e'\n");
}

int main(void) {
	int unbalanced;
	char input;
	treePointer root = NULL;
	element x;

	while (1) {
		menu();
		scanf("%s", &input);
		system ("clear");
		
		switch (input) {
			case 'i':
				printf("Please enter a number to i: \n");
				scanf("%d", &x.key);
				system ("clear");
				avlInsert(&root, x, &unbalanced);
				break;
			case 'd':
				printf("Please enter a number to d: \n");
				scanf("%d", &x.key);
				system ("clear");
				avlDelete(&root, x, &unbalanced);
				break;
			case 's':
				printf("Preorder: ");
				preorder(root);
				printf("\n\n");
				break;
			case 'e':
				return 0; 
			default:
				printf("Unknow Command\n");
		}
	}

	return 0;
}