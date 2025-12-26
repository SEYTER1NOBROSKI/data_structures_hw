#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int data;
	struct Stack *top;
};

void push(struct Stack **top, int value) {
	struct Stack *new_top = (struct Stack *)malloc(sizeof(struct Stack));
	new_top->data = value;
	new_top->top = *top;
	*top = new_top;
}

void pop(struct Stack **top) {
	if (*top != NULL) {
		struct Stack *temp = *top;
		*top = temp->top;
		int val = temp->data;
		printf("Popped number: %d\n", val);
		free(temp);
	}
}

void peek(struct Stack *top) {
	if (top != NULL) {
		int val = top->data;
		printf("Top number is: %d\n", val);
	} else {
		printf("Stack is empty\n");
	}
}

void isEmpty(struct Stack *top) {
	if (top != NULL) {
		printf("Stack is not empty\n");
	} else {
		printf("Stack is empty\n");
	}
}

int main()
{
	struct Stack *top = NULL;
	int number;
	char buffer[10];

	printf("You can do this operations with Stack: \n"); 
	printf("push: to push number to stack\n");
	printf("peek: to peek number from top of stack\n");
	printf("pop: to delete number from top of stack\n");
	printf("empty: to check is stack empty\n");

	while (1) {
		scanf("%s", buffer);
		if (strcmp(buffer, "push") == 0) {
			scanf("%d", &number);
			push(&top, number);
			printf("Stack after adding: \n");
			struct Stack *temp = top;
			while (temp != NULL)
			{
				printf("%d\n", temp->data);
				temp = temp->top;
			}
		} else if (strcmp(buffer, "peek") == 0) {
			peek(top);
		} else if (strcmp(buffer, "pop") == 0) {
			pop(&top);
			printf("Stack after deleting: \n");
			struct Stack *temp = top;
			while (temp != NULL)
			{
				printf("%d\n", temp->data);
				temp = temp->top;
			}
		} else if (strcmp(buffer, "empty") == 0) {
			isEmpty(top);
		} else if (strcmp(buffer, "exit") == 0) {
			break;
		}
	}

	free(top);
	return 0;
}