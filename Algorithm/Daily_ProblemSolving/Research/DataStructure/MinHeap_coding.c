#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i/=2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child+1].key))
			child++;

		if (temp.key <= h->heap[child].key) 
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_modify(HeapType *h, int key, int output)
{
	int parent, child;
	element item, temp;
	parent = h->heap_size;

	//search correct key, and modify
	while (h->heap[parent].key != key)
		parent--;
	h->heap[parent].key = output;

	//sorting
	// 자식 확인
	child = parent * 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;

		if (h->heap[parent].key > h->heap[child].key) // parent > child
		{
			temp = h->heap[parent];
			h->heap[parent] = h->heap[child];
			h->heap[child] = temp;
			parent = child;
			child *= 2;
		}

		else
			break;
		
	}

	// 부모 확인
	while (parent <= h->heap_size)
	{
		if (h->heap[parent/2].key > h->heap[parent].key)
		{	// grandparent > parent
			if (parent == 1)break;
			temp = h->heap[parent / 2];
			h->heap[parent / 2] = h->heap[parent];
			h->heap[parent] = temp;
			parent /= 2; //value need check
		}
		else
			break;
	}
}

void main()
{
	int i;
	element e1 = { 10 }, e2 = { 30 }, e3 = { 15 }, e4 = { 16 }, e5 = { 20 };
	HeapType heap;
	init(&heap);
	insert_min_heap(&heap, e1);
	insert_min_heap(&heap, e2);
	insert_min_heap(&heap, e3);
	insert_min_heap(&heap, e4);
	insert_min_heap(&heap, e5);

	for (i = 1; i <= heap.heap_size; i++)
		printf("<%d> ", heap.heap[i].key);
	printf("\n");

	heap_modify(&heap, 30, 14);

	for (i = 1; i <= heap.heap_size; i++)
		printf("<%d> ", heap.heap[i].key);
	printf("\n");
}