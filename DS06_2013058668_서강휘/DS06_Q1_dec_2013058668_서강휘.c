#include<stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

typedef struct _node
{
	int data;
	struct _node *right;
	struct _node *left;
}Node;

typedef struct _dec
{
	Node *head;
	Node *tail;
	Node *cur;
	int len;
}Dec;

void init(Dec *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
	dq->cur = NULL;
	dq->len = 0;
}

int QisEmpty(Dec *dq)
{
	if (dq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void add_rear(Dec *dq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (dq->head == NULL)
	{
		dq->head = newNode;
	}
	else
	{
		newNode->left = dq->tail;
		dq->tail->right = newNode;
	}
	dq->tail = newNode;
	dq->len++;
}

void add_front(Dec *dq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (dq->tail == NULL)
	{
		dq->tail = newNode;
	}
	else
	{
		newNode->right = dq->head;
		dq->head->left = newNode;
	
	}
	dq->head = newNode;
	dq->len++;
}

int delete_front(Dec *dq)
{
	int rdata;
	Node *rnode;

	if (QisEmpty(dq)) {
		printf("오류발생\n");
		exit(-1);
	}
	else
	{
		rnode = dq->head;
		rdata = rnode->data;
		dq->head = dq->head->right;
	}

	free(rnode);
	return rdata;
}

int delete_rear(Dec *dq)
{
	int rdata;
	Node *rnode;

	if (QisEmpty(dq))
	{
		printf("에러발생");
		exit(-1);
	}
	else
	{
		rnode = dq->tail;
		rdata = dq->tail->data;
		dq->tail = dq->tail->left;
	}
		
	free(rnode);
	return rdata;
}

int get_front(Dec *dq)
{
	return dq->head->data;
}

int get_rear(Dec *dq)
{
	return dq->tail->data;
}


int  main(void)
{
	Dec dq;
	int data;
	init(&dq);
	Node *cur = dq.head;
	int len = dq.len + 1;
	add_front(&dq, 3); add_front(&dq, 2);
	add_front(&dq, 1);

	add_rear(&dq, 4); add_rear(&dq, 5);
	add_rear(&dq, 6);
	

	printf("시작 , 처음 : %d, %d\n", get_front(&dq), get_rear(&dq));

	printf("뒷쪽 삭제: %d\n", delete_rear(&dq));
	printf("앞쪽 삭제: %d\n", delete_front(&dq));
	while (!QisEmpty(&dq))
	{

		printf("%d ", dq.head->data);
		if (dq.tail == dq.head)
			break;
		dq.head = dq.head->right;
		len--;
	}

	return 0;
}