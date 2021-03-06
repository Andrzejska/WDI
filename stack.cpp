#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
	int* elements;
	int top;
	int max_size;
} stack;


bool is_empty(stack* s) {
	return s->top == -1;
}

void push(stack* s, int n) {
	s->elements[++s->top] = n;
}

int pop(stack* s) {
	if (is_empty(s))
		return -1;
	return s->elements[s->top--];
}

stack* new_stack(int size) {
	stack* stack = (struct stack*) malloc(sizeof(struct stack));
	stack->max_size = size;
	stack->top = -1;
	stack->elements = (int*)malloc(stack->max_size * sizeof(int));
	return stack;
}

void delete_stack(stack* s) {
    free(s->elements);
	s->max_size = 0;
	s->top = 0;
}

int main() {
	int size;
	scanf("%d", &size);
	struct stack* s = new_stack(size);
	int tmp;

	for (int i = 1; i <= size; i++) {
		int n;
		scanf("%d", &n);
		push(s, n);
	}

	while (!is_empty(s)) {
		printf("%d\n", pop(s));
		
	}
	delete_stack(s);
}
