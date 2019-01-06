
#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define MAX_LEN	100

typedef struct _node
{
	int data;
}Node;

typedef struct _que
{
	int front;
	int rear;
	int arr[MAX_LEN];
}Queue;

void init(Queue *pq)
{
	pq->front = pq->rear = 0;
}

int QisEmpty(Queue *pq)
{
	return (pq->front == pq->rear);
}

int is_full(Queue *pq)
{
	return ((pq->rear + 1) % MAX_LEN == pq->front);
}

void Enqueue(Queue *pq, int data)
{
	if (is_full(pq))
		printf("에러발생");
	else
		pq->arr[++pq->rear] = data;

}

int Dequeue(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("값이 존재하지 않음");
		return FALSE;
	}
	
	pq->front++;

	return pq->arr[pq->front];
}

int peek(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("Q가 비었음!");
		exit(-1);
	}
	return pq->arr[1];
}

int main(void)
{
	Queue pq;
	init(&pq);

	Enqueue(&pq, 1); Enqueue(&pq, 2);
	Enqueue(&pq, 3); Enqueue(&pq, 4);
	Enqueue(&pq, 5);

	printf("첫번째 요소: %d \n", peek(&pq));

	Dequeue(&pq);

	printf("삭제 이후: ");

	while (!QisEmpty(&pq))
	{
		printf("%d ", pq.arr[++pq.front]);

	}

	return 0;
}