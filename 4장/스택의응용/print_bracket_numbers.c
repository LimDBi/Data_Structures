#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

// 삽입 함수
void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

// 삭제 함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

// 피크 함수
element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

// 괄호 번호 출력 함수
void print_bracket_numbers(char* exp) {
    StackType s;
    init_stack(&s);

    int number = 1;
    printf("괄호 수: ");

    while (*exp != '\0') {
        if (*exp == '(') {
            push(&s, number);
            printf("%d ", number++);
        }
        else if (*exp == ')') {
            printf("%d ", pop(&s));
        }
        exp++;
    }

    printf("\n");
}

int main() {
    char exp[MAX_STACK_SIZE];

    printf("수식 입력: ");
    fgets(exp, sizeof(exp), stdin);

    // '\n' 문자 제거 (fgets()로 문자열 입력받을 때 '\n'이 추가되어 출력됨. -> 다음 문자열 입력받을 때 '\n'이 자동으로 입력되어 빈 문자열 출력.)
    exp[strlen(exp) - 1] = '\0';

    print_bracket_numbers(exp);

    return 0;
}
