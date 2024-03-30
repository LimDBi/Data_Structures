// 스택의 응용: 중위 표기 수식을 후위 표기 수식을 변환하여 계산
// 알고리즘: 문자열로 수식을 읽어들여 왼쪽에서 오른쪽으로 스캔하여 피연산자이면 스택에 저장하고 연산자이면 필요한 수만큼의 피연산자를 스택에서 꺼내 연산을 실행한다. 연산의 결과를 스택에 다시 저장한다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// 스택 코드 추가 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

//모든 연산자는 구조체의 포인터를 받는다.
//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
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
// 스택 코드 추가 끝 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 중위 표기 수식을 후위 표기 수식으로 변환 함수
// 연산자의 우선순위를 반환한다. 
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[]) {
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			//왼쪽 괄호를 만날 때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:	// 피연산자
			printf("%c", ch);
			break;
		}
	}
}

// 후위 표기 수식 계산 함수
int eval(char exp[]) {
	int op1, op2, value;
	int len = strlen(exp);
	char ch;
	StackType s;	// 스택 초기화 top = -1

	init_stack(&s);
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // 입력이 피연산자라면
			value = ch - '0';	// 문자열로 읽어들인 숫자를 정수로 바꿔서 스택에 삽입
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s); // 결과값을 리턴
}

int main() {
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);

	char* s = "(2+3)*4+9";
	printf("중위표기수식 %s =\n", s);
	printf("후위표기수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}
