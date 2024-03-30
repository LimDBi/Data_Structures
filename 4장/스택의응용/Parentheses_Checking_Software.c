// 스택의 응용: 괄호 검사 문제
// 조건 1: 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
// 조건 2: 같은 종류의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
// 조건 3: 서로 다른 종류의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로를 교차하면 안된다.
// 한 문자열에서 왼쪽 괄호를 만나면 스택에 계속 삽입하다가 오른쪽 괄호를 만나면 스택에서 가장 최근에 삽입된 괄호를 꺼내어 타입을 맞추어본다.
// 고려 사항: 스택이 비어 있으면 조건 1, 2 위배. 괄호의 짝이 맞지 않으면 조건 3 위배. 조사 후에도 괄호가 남아있으면 조건 1 위배.
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


int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int n = strlen(in); // n은 문자열의 길이
	init_stack(&s); // 스택의 초기화

	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch); // s라는 stack에 ch를 삽입.
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) {	// 스택이 비어있으면
				return 0;	// 오류
			}
			else { // 스택에서 open_ch를 꺼낸다.
				open_ch = pop(&s); // 닫는 괄호일 때 스택에서 top에 해당하는 값을 꺼내서 if문 수행
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) { // ch와 open_ch가 같은 짝이 아니라면
					return 0; // 오류 보고
				}
				break;

			}
		}
		
	}
	if (!is_empty(&s)) {	// stack에 남아있는 문자가 있다면
		return 0; // 오류
	}
	return 1; // 검사에 성공하면 1반환
}
int main() {
	char* p = "{ A[(i+1)]=0 }";
	if (check_matching(p) == 1) {
		printf("%s 괄호검사성공\n", p);
	}
	else {
		printf("%s 괄호검사실패\n", p);
	}
	return 0;
}
