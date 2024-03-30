//동적 배열을 이용한 스택 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100


typedef int element;
typedef struct{
	element *data;	// data를 포인터로 정의
	int capacity;	// 현재크기
	int top;
}StackType;

//스택 초기화 함수. 스택이 만들어질 때, 1개의 요소를 저장할 수 있는 공간을 일단 확보한다.
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity*sizeof(element));
}

//공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

//삽입 함수. 공간이 부족하면 메모리를 2배로 확보한다.
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = 
			(element*)realloc(s->data, s->capacity * sizeof(element));
			// relloc()은 동적 메모리의 크기를 변경하는 함수로서 현재 내용은 유지하면서 주어진 크기로 동적 메모리를 다시 할당한다.
	}
	
	s->data[++(s->top)] = item;
	
}

//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}


int main() {

	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s)); // 3
	printf("%d\n", pop(&s)); // 2
	printf("%d\n", pop(&s)); // 1
	free(s.data);
	return 0;
}
