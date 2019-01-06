#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *removed;
	Node *before;
	Node *cur;
}ListNode;

void init(ListNode *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
}

int is_Empty(ListNode *plist)
{
	if (plist->head->next == NULL)
		return TRUE;
	else
		return FALSE;
}

void insert(ListNode *plist, int data) //리스트 삽입
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;


	if (plist->head == NULL)
	{
		plist->head = newNode;
		plist->tail = newNode;
	}

	else
	{
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
}

int list_add(ListNode *plist, int p, int newdata) //연결된 리스트 중간에 값 삽입
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = newdata;
	newNode->next = NULL;

	plist->cur = plist->before = plist->head;

	while (plist->cur != NULL) {

		if (plist->head == NULL)
		{
			plist->head = newNode;
			break;
		}
		else if (p == NULL || p == 0) {
			newNode->next = plist->head;
			plist->head = newNode;
			break;
		}

		else if (plist->cur->data == p) { // 값 대입을 위해 이전 노트를 찾는 과정

			newNode->next = plist->cur->next;
			plist->cur->next = newNode;

			break;

		}

		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	}
	return newdata;
}

int Delete(ListNode *plist, int p)
{
	plist->removed = plist->before = plist->head;
	int data = plist->removed->data;

	while (plist->removed != NULL)
	{
		if (plist->removed->data == p)
		{
			plist->before->next = plist->removed->next;
			break;
		}
		else if (p == NULL || p == 0)
		{
			plist->head = plist->head->next;
			break;
		}
		plist->before = plist->removed;
		plist->removed = plist->removed->next;
	}

	free(plist->removed);
	return data;
}

int first(ListNode *plist) // cur 과 before를 head의 위치로 초기화
{
	plist->before = plist->cur = plist->head;

	if (!is_Empty(plist))
		return TRUE;
	else
		return FALSE;

}

int Next(ListNode *plist, int *data) // list들을 순차적으로 넘어가면서 값을 출력해 주는 함수
{

	if (plist->cur == NULL)
		return FALSE;

	*data = plist->cur->data;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	return TRUE;
}

int main(void)
{
	ListNode list;
	int data;

	init(&list);


	insert(&list, 1); insert(&list, 2);
	insert(&list, 3); insert(&list, 4);
	insert(&list, 5);


	printf("초기 리스트: ");
	if (first(&list))
	{
	while (Next(&list, &data))
	printf("%d ", data);
	}

	printf("\n대입값: %d\n",list_add(&list, 5,7));

	printf("대입 후 리스트: ");
	if (first(&list)) {
		while (Next(&list, &data))
			printf("%d ", data);
	}

	printf("\n대입값: %d\n", list_add(&list, 2, 10));

	printf("대입 후 리스트: ");
	if (first(&list)) {
		while (Next(&list, &data))
			printf("%d ", data);
	}


	printf("\n삭제 값: %d\n",Delete(&list, 0));

	printf("삭제 이후 리스트: ");
	if (first(&list))
	{
		while (Next(&list, &data))
			printf("%d ", data);
	}

	return 0;
}
