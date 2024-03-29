//포인터를 이용한 스택 구현
#include <stdio.h>
#include <stdlib.h>

//차후에 스택이 필요하면 여기만 복사하여 붙인다.
#define MAX_STACK_SIZE 100


//스택에 저장되는 데이터를 구조체로 정의.
typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

//모든 연산자는 구조체의 포인터를 받는다.
//공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE -1);
}

//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
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

//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}

int main() {
	StackType s; // 스택 정적으로 생성

	init_stack(&s);
	// 함수를 호출할 때 스택의 주소를 전달.
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s)); // 3
	printf("%d\n", pop(&s)); // 2
	printf("%d\n", pop(&s)); // 1
	return 0;
}
