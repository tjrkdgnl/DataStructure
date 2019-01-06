#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define MAX_LEN	100


typedef struct _node
{
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct _que
{
	int front;
	int rear;
	element arr[MAX_LEN];
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

double random()
{
	return rand() / (double)RAND_MAX;

}

int duation = 10;
double arrival_prob = 0.7;
int max_serv_time = 5;
int clock;
int customers;
int served_customers;
int waited_time;


void Enqueue(Queue *pq, element data)
{
	if (is_full(pq))
		printf("�����߻�");
	else
		pq->arr[++pq->rear] = data;
}

element Dequeue(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("���� �������� ����");
		exit(-1);
	}

	pq->front++;

	return pq->arr[pq->front] ;
}

element peek(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("Q�� �����!");
		exit(-1);
	}
	return pq->arr[1];
}

int is_customer_arrived()
{
	if (random() < arrival_prob)
		return TRUE;
	else
		return FALSE;
}

void insert_customer(Queue *pq,int arrival_time)
{
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time *random()) + 1;
	Enqueue(pq, customer);
	printf("�� %d�� %d�п� ���ɴϴ�. ���񽺽ð��� %d���Դϴ�.\n", customer.id, customer.arrival_time, customer.service_time);
}

int remove_customer(Queue* pq)
{
	element customer;

	int service_time = 0;

	if (QisEmpty(pq))
		return 0;

	customer = Dequeue(pq);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += clock - customer.arrival_time;
	printf("�� %d�� %d�п� ���񽺸� �����մϴ�.���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);

	return service_time;
}

void print_stat()
{
	printf("���꽺���� ���� = %d\n", served_customers);
	printf("��ü ��� �ð� =%d��\n", waited_time);
	printf("1�δ� ��� ��� �ð� = %f��\n", (double)waited_time/served_customers);
	printf("���� ������� �� ��: %d\n", customers - served_customers);
}


int main(void)
{
	int service_time = 0;
	Queue q;

	init(&q);

	clock = 0;

	while (clock < duation) {
		clock++;
		printf("����ð� =%d\n", clock);

		if (is_customer_arrived())
			insert_customer(&q,clock);

		if (service_time > 0)
			service_time--;
		else 
			service_time = remove_customer(&q);
	}
	print_stat();

	system("pause");
	return 0;
}