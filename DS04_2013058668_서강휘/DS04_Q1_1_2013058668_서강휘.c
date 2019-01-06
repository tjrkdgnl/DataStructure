#include <stdio.h>

#define FALSE	0
#define TRUE	1
#define MAX_LEN	100

typedef struct _node
{
	int StackArr[MAX_LEN];
	int Top;
}Stack;

void init(Stack *pstack)
{
	pstack->Top = -1;
}

int SisEmpty(Stack *pstack)
{
	if (pstack->Top == -1)
		return TRUE;
	else
		return FALSE;
}

int SisFull(Stack *pstack)
{
	if (pstack->Top == MAX_LEN)
		return TRUE;
	else
		return FALSE;
}

void push(Stack *pstack, int data)
{
	if (SisFull(pstack))
	{
		printf("오버헤드 발생");
		exit(-1);
	}
	else
	{
		pstack->Top++;
		pstack->StackArr[pstack->Top] = data;
	}
}

int pop(Stack *pstack, int position)
{
	int i, item;
	item = pstack->StackArr[position];

	if (SisEmpty(pstack))
	{
		printf("메모리 참조 오류");
		exit(-1);
	}
	for (i = position-1; i<MAX_LEN - 1; i++)
		pstack->StackArr[i] = pstack->StackArr[i + 1];

	pstack->Top--;
	return item;
}

int main(void)
{
	Stack stack;
	int len,i;
	init(&stack);

	push(&stack, 5); push(&stack, 4);
	push(&stack, 3); push(&stack, 2);
	push(&stack, 1);

	len = stack.Top;

	for (i = 0; i <= len; i++)
		printf("%d ", stack.StackArr[i]);

	pop(&stack, 3);

	len = stack.Top;

	printf("\n");
	for (i = 0; i <= len; i++)
		printf("%d ", stack.StackArr[i]);


	return 0;
}

