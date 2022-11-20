#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AutoHtmlEnd.h"

int isStackEmpty(void) {
	if(top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	int i = 0;
	if (temp != NULL) {
		while (item[i] != '\0')
		{
			temp->data[i] = item[i];
			i++;
		}
		temp->data[i] = '\0';
		temp->link = top;
		top = temp;
	}
}
void pop(void) {
	element item;
	stackNode* temp = top;
	int i = 0;
	if (isStackEmpty()) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		printf("</%s>", top->data);
		top = temp->link;
		free(temp);
	}
}