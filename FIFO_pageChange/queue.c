#include "queue.h"
//큐를 초기화함
void queue_init(void) {
	front = rear = 0;
	for (int i = 0; i < MAX; i++)
		queue[i] = -1;
}

//큐를 비움
void queue_clear(void) {
	front = rear;
}

//꽉차있으면 1, 아니면 0
int queue_isFull(void) {
	if ((rear + 1) % MAX == front)
		return 1;
	else
		return 0;
}

//큐에 데이터를 삽입
int queue_put(int k) {
	if (queue_isFull()) {
		printf("\n   Queue overflow.");
		return -1;
	}

	queue[rear] = k;
	rear = ++rear % MAX;
	return k;
}

//큐에서 데이터를 뺌
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

//큐에 있는 데이터를 출력
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
