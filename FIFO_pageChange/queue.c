#include "queue.h"
//ť�� �ʱ�ȭ��
void queue_init(void) {
	front = rear = 0;
	for (int i = 0; i < MAX; i++)
		queue[i] = -1;
}

//ť�� ���
void queue_clear(void) {
	front = rear;
}

//���������� 1, �ƴϸ� 0
int queue_isFull(void) {
	if ((rear + 1) % MAX == front)
		return 1;
	else
		return 0;
}

//ť�� �����͸� ����
int queue_put(int k) {
	if (queue_isFull()) {
		printf("\n   Queue overflow.");
		return -1;
	}

	queue[rear] = k;
	rear = ++rear % MAX;
	return k;
}

//ť���� �����͸� ��
int queue_get(void) {
	int i;
	if (front == rear) {
		printf("\n  Queue underflow.");
		return -1;
	}

	i = queue[front];
	front = ++front % MAX;
	return i;
}

//ť�� �ִ� �����͸� ���
void queue_print(void) {
	int i;
	printf("\n Frame contents : ");
	/*
	for (i = front; i != rear; i = ++i%MAX)
		printf("%d", queue[i]);
	*/
	for (i = 0; i < MAX; i++)
		printf("%d ", queue[i]);
	printf("\n");
}
