#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
};

void add_node(struct Tree **root, int value) {
	struct Tree *new_node = (struct Tree *)malloc(sizeof(struct Tree));
	new_node->data = value;

	new_node->right = NULL;
	new_node->left = NULL;

	if (*root == NULL) {
		*root = new_node;
		printf("Added number: %d\n", value);
		return;
	}

	struct Tree *current = *root;
	while (current != NULL) {
		if (value < current->data && current->left == NULL) {
			current->left = new_node;
			printf("Added number: %d\n", value);
			return;
		} else if (value < current->data && current->left != NULL) {
			current = current->left;
		} else if (value > current->data && current->right != NULL) {
			current = current->right;
		} else if (value > current->data && current->right == NULL) {
			current->right = new_node;
			printf("Added number: %d\n", value);
			return;
		} else if (value == current->data) {
			return;
		}
	}
}

void print_tree(struct Tree *root) {
	if (root != NULL)
	{
		print_tree(root->right);
		printf("%d-", root->data);
		print_tree(root->left);
	}
}

int main()
{
	struct Tree *root = NULL;
	int number;
	char buffer[10];

	printf("Welcome to tree, you can do this operations: \n"); 
	printf("add: to add number to tree\n");
	printf("print: to print whole tree\n");

	while (1) {
		scanf("%s", buffer);
		if (strcmp(buffer, "add") == 0) {
			scanf("%d", &number);
			add_node(&root, number);
			printf("Tree after adding: ");
			print_tree(root);
			printf("\n");
		} else if (strcmp(buffer, "print") == 0) {
			print_tree(root);
		} else if (strcmp(buffer, "exit") == 0) {
			break;
		}
	}

	free(root);
	return 0;
}