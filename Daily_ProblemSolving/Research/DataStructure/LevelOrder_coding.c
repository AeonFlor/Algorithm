#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct TreeNode{
	int data;
	struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;

typedef struct{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 26, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void error(char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q){
	q->front = q->rear = 0;
}

int is_empty(QueueType* q){
	return (q->front == q->rear);
}

int is_full(QueueType* q){
	return (abs(q->front - q->rear) + 1 == MAX_QUEUE_SIZE);
}

void enqueue(QueueType* q, element item){
	if (is_full(q))
		error("Queue is full");

	q->queue[q->rear++] = item;
	q->rear %= MAX_QUEUE_SIZE;
}

element dequeue(QueueType* q){
	if (is_empty(q))
		error("Queue is empty");

	element temp = q->queue[q->front++];
	q->front %= MAX_QUEUE_SIZE;
	return temp;
}

void level_order(TreeNode* ptr){
	QueueType q;
	init(&q);
	if (ptr == NULL)
		return;

	enqueue(&q, ptr);

	while (!is_empty(&q)){
		ptr = dequeue(&q);
		printf("%d -> ",ptr->data);

		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	printf("\n");
}

void main() {
	level_order(root);
}