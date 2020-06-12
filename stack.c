

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define ALLOC_SIZE 512

typedef int KEY_TYPE;

typedef struct _stack {

	KEY_TYPE *base;
	int top;
	int stack_size;
	
} stack;


void init_stack(stack *s) {

	s->base = (KEY_TYPE*)calloc(ALLOC_SIZE, sizeof(KEY_TYPE));
	assert(s->base);

	s->top = 0;
	s->stack_size = ALLOC_SIZE;

}

void destroy_stack(stack *s) {

	assert(s);

	free(s->base);
	s->base = NULL;
	s->stack_size = 0;
	s->top = 0;

}

void push_stack(stack *s, KEY_TYPE data) {

	assert(s);

	if (s->top >= s->stack_size) {
		s->base = realloc(s->base, (s->stack_size + ALLOC_SIZE) * sizeof(KEY_TYPE));
		assert(s->base);

		s->stack_size += ALLOC_SIZE;
	}

	s->base[s->top] = data;
	s->top ++;
}

void pop_stack(stack *s, KEY_TYPE *data) {

	assert(s);

	*data = s->base[--s->top];

}

int empty_stack(stack *s) {
	return s->top == 0 ? 0 : 1; 
}

int size_stack(stack *s) {
	return s->top;
}

int main() {

	stack s;

	init_stack(&s);

	int i = 0;
	for (i = 0;i < 1000;i ++) {
		push_stack(&s, i+1);
	}

	while (empty_stack(&s)) {
		int data;

		pop_stack(&s, &data);
		printf("%4d", data);
	}
	printf("\n");

	destroy_stack(&s);

}



