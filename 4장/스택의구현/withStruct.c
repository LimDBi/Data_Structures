//구조체 배열 스택 구현, 스택의 요소가 정수가 아니라 학생에 대한 정보일 때
#include <stdio.h>
#include <stdlib.h>
#define MAX_STAK_SIZE 100
#define MAX_STRING 100

//스택에 저장되는 데이터를 구조체로 정의.
typedef struct{
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STAK_SIZE];
}element;

element stack[MAX_STAK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

//포화 상태 검출 함수
int is_full() {
	return (top == MAX_STAK_SIZE -1);
}

//삽입 함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

//삭제 함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}

//피크 함수
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
	element ie = {20190001, "Hong", "Seoul"};
	element oe;

	push(ie);
	oe = pop();

	printf("학번: %d\n", oe.student_no);
	printf("이름: %s\n", oe.name);
	printf("주소: %s\n", oe.address);
	return 0;
}
