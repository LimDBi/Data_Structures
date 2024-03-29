// 전역변수로 스택 구현
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

//포화 상태 검출 함수
int is_full() {
	return (top == MAX_STACK_SIZE-1);
}

//삽입함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

//삭제함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}

//피크함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

int main() {
	push(1); // stack[0] = 1, top = 0
	push(2); // stack[1] = 2, top = 1
	push(3); // stack[2] = 3, top = 2
	printf("%d\n", pop()); // stack[2] = 3 출력, top = 1
	printf("%d\n", pop()); // stack[1] = 2 출력, top = 0
	printf("%d\n", pop()); // stack[0] = 1 출력, top = -1
	return 0;
}
