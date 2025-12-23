#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
	struct List * next;
	int data;
};

// void func(int *a) {
// 	int b = 5;
// 	const int *const ptr = &b;
// 	ptr++;
// }

void add_item(struct List **item, int value) {
	struct List *new_node = (struct List *)malloc(sizeof(struct List));
	new_node->data = value;
	new_node->next = NULL;

	if (*item == NULL) {
		*item = new_node;
	} else {
		struct List *current = *item;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
	printf("Added number: %d\n", value);
}

void remove_item(struct List **item, int value) {
	struct List *temp = *item;
	struct List *prev = NULL;

	if (temp != NULL && temp->data == value) {
		*item = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	prev->next = temp->next;
	free(temp);
}

void get_by_index_item(struct List **item, int index) {
	struct List *current = *item;
	int counter = 0;
	while (current != NULL) {
		if (counter == index) {
			printf("This is yor number: %d\n", current->data);
			return;
		}
		counter++;
		current = current->next;
	}
	printf("Index %d out of bounds\n", index);
}

int main()
{
	struct List *item = NULL;
	//struct List *temp = item;
	int number;
	char buffer[10];

	printf("You can do this operations: \n"); 
	printf("add: to add number to list\n");
	printf("get: to get number from list using index\n");
	printf("del: to delete number from list\n");

	while (1) {
		scanf("%s", buffer);
		if (strcmp(buffer, "add") == 0) {
			scanf("%d", &number);
			add_item(&item, number);
			printf("List after adding: ");
			struct List *temp = item;
			while (temp != NULL)
			{
				printf("%d -> ", temp->data);
				temp = temp->next;
			}
			printf("NULL\n");
		} else if (strcmp(buffer, "get") == 0) {
			scanf("%d", &number);
			get_by_index_item(&item, number);
		} else if (strcmp(buffer, "del") == 0) {
			scanf("%d", &number);
			remove_item(&item, number);
			printf("List after deleting: ");
			struct List *temp = item;
			while (temp != NULL)
			{
				printf("%d -> ", temp->data);
				temp = temp->next;
			}
			printf("NULL\n");
		} else if (strcmp(buffer, "exit") == 0) {
			break;
		}
	}

	free(item);
	return 0;
}