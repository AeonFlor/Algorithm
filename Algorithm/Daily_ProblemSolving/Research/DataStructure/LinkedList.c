#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[20];
	int dist;
	struct ListNode* link;
}ListNode;

ListNode* create_node(char* data, int dist) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));

	strcpy(new_node->data, data);
	new_node->dist = dist;

	new_node->link = NULL; // NULL 링크 입력

	return new_node;
}

// phead: 리스트의 헤드 포인터의 포인터
// p: 선행 노드
// new_node: 삽입될 노드

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node, int alterDist) {
	if (*phead == NULL) { // 공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		p = *phead;

		while (p->link)
			p = p->link;

		p->dist = alterDist;
		new_node->link = NULL;
		p->link = new_node;
	}
	else {               // p 다음에 삽입
		p->dist = alterDist;
		new_node->link = p->link;
		p->link = new_node;
	}
}

// phead: 헤드 포인터에 대한 포인터
// p: 삭제될 노드의 선행 노드
// removed: 삭제될 노드

void remove_node(ListNode** phead, ListNode* p, ListNode* removed, int alterDist) {
	if (p == NULL) // 공백리스트인 경우
		*phead = (*phead)->link;
	else           // p 다음 노드 제거
	{
		p->dist = alterDist;
		p->link = removed->link;
	}
	free(removed);
}

void display(ListNode* head) {
	ListNode* p = head;

	while (p != NULL) {
		printf("%s(%d)", p->data, p->dist);
		printf(" -> ");
		p = p->link; // p를 다음 노드로 이동
	}
	printf("\n");
}

void display_recur(ListNode* head) {
	ListNode* p = head;

	if (p != NULL) {
		printf("%s(%d)", p->data, p->dist);
		printf(" -> ");
		display_recur(p->link);
	}
}

void time(ListNode** phead, ListNode* from, ListNode* to) {
	ListNode* p = from;
	int require = 0;

	while (p != NULL) {
		if (!strcmp(p->data, to->data))
		{
			printf("From %s to %s : %d\n", from->data, to->data, require);
			return;
		}
		require += p->dist;
		p = p->link; // p를 다음 노드로 이동
	}

	printf("It is impossible to reach %s station.\n", to->data);
}

ListNode* search(ListNode* head, char* x) {
	ListNode* p;
	p = head;

	while (p != NULL) {
		if (!strcmp(p->data, x)) return p; // 탐색 성공
		p = p->link;
	}

	return p; // 탐색 실패일 경우 NULL 반환
}

ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;

	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;

		return head1;
	}
}

ListNode* reverse(ListNode* head) {
	// 순회 포인터로 p, q, r을 사용
	ListNode* p;
	ListNode* q;
	ListNode* r;
	p = head; // p는 아직 처리되지 않은 노드
	q = NULL; // q는 역순으로 만들 노드

	while (p != NULL) {
		r = q; // r 은 역순으로 된 노드.
		q = p;// r은 q, q는 p를 차례로 따라간다
		p = p->link; // p를 다음 노드로 이동
		q->link = r; // q의 링크 방향을 바꾼다
	}

	return q; // q는 역순으로 된 리스트의 헤드 포인터
}

int main()
{
	ListNode* homework = NULL;

	insert_node(&homework, NULL, create_node("Airport", 0), 0);
	display(homework);
	insert_node(&homework, NULL, create_node("Aewol", 0), 20);
	display(homework);
	insert_node(&homework, NULL, create_node("Seogwipo", 0), 40);
	display(homework);
	insert_node(&homework, NULL, create_node("Seongsan", 0), 30);
	display(homework);

	time(&homework, search(homework, "Aewol"), search(homework, "Seongsan"));

	insert_node(&homework, search(homework, "Aewol"), create_node("Moseulpo", 30), 30);
	display(homework);

	time(&homework, search(homework, "Aewol"), search(homework, "Seongsan"));

	remove_node(&homework, search(homework, "Aewol"), search(homework, "Moseulpo"), 40);
	display(homework);

	return 0;
}