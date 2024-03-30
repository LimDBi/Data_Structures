#include <stdio.h>
#include <stdlib.h>

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

// 반복되는 숫자 제거 함수
void remove_duplicates(int num) {
    StackType stack;
    init_stack(&stack);

    while (num > 0) {
        int digit = num % 10;
        if (is_empty(&stack) || peek(&stack) != digit) {
            push(&stack, digit);
        }
        num /= 10;
    }

    printf("출력: ");
    while (!is_empty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int num;

    printf("정수를 입력하시오: ");
    scanf("%d", &num);

    remove_duplicates(num);

    return 0;
}
