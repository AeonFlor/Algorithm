#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node{
	int data;
	treePointer leftChild, rightChild;
} node;

void preorder(treePointer root){
	if (root){
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

treePointer search(treePointer root, int key){
	if (!root)
		return NULL;
	else if (key == root->data)
		return root;
	else if (key < root->data)
		return search(root->leftChild, key);
	else
		return search(root->rightChild, key);
}

treePointer iterSearch(treePointer root, int key){
	while (root){
		if(key == root->data)
			return root;
		
		else if(key < root->data)
			root = root->leftChild;
		
		else
			root = root->rightChild;
	}

	return NULL;
}

treePointer modifiedSearch(treePointer root, int key){
	treePointer temp = root;
	while (root){
		temp = root;
		if (key < root->data)
			root = root->leftChild;
		else if (key > root->data)
			root = root->rightChild;
		else
			return NULL;
	}

	return temp;
}

int delete(treePointer root, int key){
	int temp;
	treePointer current, target, previous;
	current = root;
	target = NULL;
	previous = current;

	if (!current)
		return 0;
	while (1){
		if (key > current->data){
			if (current->rightChild == NULL)
				break;
			previous = current;
			current = current->rightChild;
		}
		else{
			if(key== current->data)
				target = current;
			if (current->leftChild == NULL)
				break;
			previous = current;
			current = current->leftChild;
		}
	}

	if (target == NULL)
		return 0;
	else{
		if (previous == NULL){
			temp = current->data;
			free(current);
			root = NULL;
			return temp;
		}
		else{
			temp = target->data;
			target->data = current->data;

			if (previous->leftChild == current) {
				if (current == target)
					previous->leftChild = current->rightChild;
				else
					previous->leftChild = current->leftChild;
			}
			else {
				if (current == target)
					previous->rightChild = current->rightChild;
				else
					previous->rightChild = current->leftChild;
			}

			free(current);
			return temp;
		}
	}
}

void insert(treePointer* root, int key){
	treePointer ptr;
	treePointer temp = modifiedSearch(*root, key);

	if (temp || !(*root)){
		ptr = (treePointer) malloc(sizeof(*ptr));
		ptr->data = key;
		ptr->leftChild = ptr->rightChild = NULL;
		if (*root){
			if(temp->data > key)
				temp->leftChild = ptr;
			
			else if(temp->data < key)
				temp->rightChild = ptr;
		}
		else
			*root = ptr;
	}
}

int main(){
	int item;
	treePointer root = NULL;
	insert(&root, 27);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 23);
	insert(&root, 38);
	insert(&root, 30);
	insert(&root, 34);
	insert(&root, 55);


	printf("Preorder traversal: ");
	preorder(root);
	item = delete(root, 30);
	printf("\ndeleted item: %d\n", item);

	printf("Preorder traversal: ");
	preorder(root);
	printf("\n");
}