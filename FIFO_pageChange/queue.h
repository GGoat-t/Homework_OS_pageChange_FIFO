#pragma once
#include <stdio.h>
#define MAX 3

int queue[MAX];
int front, rear;

void queue_init(void);
void queue_clear(void);
int queue_isFull(void);
int queue_put(int k);
int queue_get(void);
void queue_print(void);