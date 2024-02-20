#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct threadedTree{
	short int leftThread;
	short int rightThread;
	struct threadTree* leftChild;
	struct threadTree* rightChild;
	char data;
} Thread;

Thread* Tcreate(){
	Thread* newThread = (Thread* ) malloc(sizeof(Thread));

	newThread->leftChild = NULL;
	newThread->leftThread = FALSE;
	newThread->rightChild = NULL;
	newThread->rightThread = FALSE;

	return newThread;
}

Thread* insucc(Thread* tree){
	Thread *temp = tree->rightChild;

	if (!tree->rightThread)
		while (!temp->leftThread)
			temp = temp->leftChild;
	return temp;
}

Thread* inpred(Thread* tree){
	Thread* temp = tree->leftChild;

	if (!tree->leftThread)
		while (!temp->rightThread)
			temp = temp->rightChild;
	return temp;
}

void Tinorder(Thread* tree){
	Thread* temp = tree;

	while (1){
		temp = insucc(temp);

		
		if(temp == tree)
			break;
		printf("%c ", temp->data);
	}
	printf("\n");
}

void InsertRight(Thread* tree, Thread* rightTree){
	Thread* temp;
	
	rightTree->rightChild = tree->rightChild;
	rightTree->rightThread = tree->rightThread;
	rightTree->leftChild = tree;
	rightTree->leftThread = TRUE;
	tree->rightChild = rightTree;
	tree->rightThread = FALSE;

	if(!rightTree->rightThread)
	{
		temp = insucc(rightTree);
		temp->leftChild = rightTree;
	}
}
void InsertLeft(Thread* tree, Thread* leftTree){
	Thread* temp;

	leftTree->leftChild = tree->leftChild;
	leftTree->leftThread =  tree->leftThread;
	leftTree->rightChild = tree;
	leftTree->rightThread = TRUE;
	tree->leftChild = leftTree;
	tree->leftThread = FALSE;

	if (!leftTree->leftThread){
		temp = inpred(leftTree);
		temp->rightChild = leftTree;
	}
}

int main(){
	Thread* root = Tcreate();
	Thread* tree = Tcreate();
	Thread* temp;

	root->leftChild = tree;
	root->leftThread = FALSE;
	root->rightChild = root;
	root->rightThread = FALSE;

	tree->data = 'A';
	tree->rightChild = root;
	tree->rightThread = TRUE;
	tree->leftChild = root;
	tree->leftThread = TRUE;

	temp = Tcreate();
	temp->data = 'B';
	InsertLeft(tree, temp);

	temp = Tcreate();
	temp->data = 'C';
	InsertLeft(tree, temp);

	temp = Tcreate();
	temp->data = 'D';
	InsertRight(tree, temp);

	temp = Tcreate();
	temp->data = 'E';
	InsertRight(tree, temp);

	Tinorder(root);

	return 0;
}