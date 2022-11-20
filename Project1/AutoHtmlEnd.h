#pragma once
typedef char element[10];

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;
int isStackEmpty(void);
void push(element item);
void pop(void);