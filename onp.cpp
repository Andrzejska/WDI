#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
	int* elements;
	int top;
	int max_size;
} stack;

/***************************************
* paste here your stack implementation *
***************************************/

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


typedef enum entry_type { number, add, subtract, multiply, divide } entry_type;

entry_type parse(char* raw) {
	if (raw[0] == '+') return add;
	if (raw[0] == '-') return subtract;
	if (raw[0] == '*') return multiply;
	if (raw[0] == '/') return divide;
	return number;
}

/****************************
* implement functions below *
****************************/

void do_add(stack* s) {
    int x=pop(s);
	s->elements[s->top]+=x;
}

void do_subtract(stack* s) {
    int x=pop(s);
	s->elements[s->top] -= x;
}

void do_multiply(stack* s) {
    int x=pop(s);
	s->elements[s->top] *=x;
}

void do_divide(stack* s) {
    int x=pop(s);
	s->elements[s->top] /= x;
}

int read_and_calculate(int operands_count, int max_entry_size) {
	stack* operands = new_stack(operands_count);
	char* entry = malloc((max_entry_size + 1) * sizeof(char));
	int result;
	int m = 0;
	while (((operands_count * 2) - 1) != m) {
		for (int i = 0; i < max_entry_size; i++) entry[i] = '\0';
		scanf("%s", entry);
		switch (parse(entry)) {
		case add: {
			do_add(operands);
			break;
		}
		case subtract: {
			do_subtract(operands);
			break;
		}
		case multiply: {
			do_multiply(operands);
			break;
		}
		case divide: {
			do_divide(operands);
			break;
		}
		default: {
			int tmp = atoi(entry);
			push(operands, tmp);
		}

		}
		m++;
		
	}
	result = pop(operands);

	return result;
}

int main() {
	int operands_count, max_entry_size;
	scanf("%d", &operands_count);
	scanf("%d", &max_entry_size);
	printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}
