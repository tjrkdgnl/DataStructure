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

void insert(ListNode *plist, int data) //����Ʈ ����
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

int list_add(ListNode *plist, int p, int newdata) //����� ����Ʈ �߰��� �� ����
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

		else if (plist->cur->data == p) { // �� ������ ���� ���� ��Ʈ�� ã�� ����

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

int first(ListNode *plist) // cur �� before�� head�� ��ġ�� �ʱ�ȭ
{
	plist->before = plist->cur = plist->head;

	if (!is_Empty(plist))
		return TRUE;
	else
		return FALSE;

}

int Next(ListNode *plist, int *data) // list���� ���������� �Ѿ�鼭 ���� ����� �ִ� �Լ�
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


	printf("�ʱ� ����Ʈ: ");
	if (first(&list))
	{
	while (Next(&list, &data))
	printf("%d ", data);
	}

	printf("\n���԰�: %d\n",list_add(&list, 5,7));

	printf("���� �� ����Ʈ: ");
	if (first(&list)) {
		while (Next(&list, &data))
			printf("%d ", data);
	}

	printf("\n���԰�: %d\n", list_add(&list, 2, 10));

	printf("���� �� ����Ʈ: ");
	if (first(&list)) {
		while (Next(&list, &data))
			printf("%d ", data);
	}


	printf("\n���� ��: %d\n",Delete(&list, 0));

	printf("���� ���� ����Ʈ: ");
	if (first(&list))
	{
		while (Next(&list, &data))
			printf("%d ", data);
	}

	return 0;
}
