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
		printf("에러발생");
	else
		pq->arr[++pq->rear] = data;
}

element Dequeue(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("값이 존재하지 않음");
		exit(-1);
	}

	pq->front++;

	return pq->arr[pq->front] ;
}

element peek(Queue *pq)
{
	if (QisEmpty(pq))
	{
		printf("Q가 비었음!");
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
	printf("고객 %d이 %d분에 들어옵니다. 서비스시간은 %d분입니다.\n", customer.id, customer.arrival_time, customer.service_time);
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
	printf("고객 %d이 %d분에 서비스를 시작합니다.대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);

	return service_time;
}

void print_stat()
{
	printf("서브스받은 고객수 = %d\n", served_customers);
	printf("전체 대기 시간 =%d분\n", waited_time);
	printf("1인당 평균 대기 시간 = %f분\n", (double)waited_time/served_customers);
	printf("아직 대기중인 고객 수: %d\n", customers - served_customers);
}


int main(void)
{
	int service_time = 0;
	Queue q;

	init(&q);

	clock = 0;

	while (clock < duation) {
		clock++;
		printf("현재시각 =%d\n", clock);

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