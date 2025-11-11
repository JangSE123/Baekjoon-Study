#include <stdio.h>

#define MAX 1001

// --------- Stack ----------
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// --------- Queue ----------
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    if (front == rear) return -1;
    return queue[front++];
}

int peekQueue() {
    if (front == rear) return -1;
    return queue[front];
}

int isEmptyQueue() {
    return front == rear;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        enqueue(num);
    }

    int cur = 1;

    while (!isEmptyQueue()) {
        int now = peekQueue();

        if (now == cur) {
            dequeue();
            cur++;
        } else if (!isEmpty() && peek() == cur) {
            pop();
            cur++;
        } else {
            push(dequeue());
        }
    }

    while (!isEmpty() && peek() == cur) {
        pop();
        cur++;
    }

    if (cur == N + 1) printf("Nice\n");
    else printf("Sad\n");

    return 0;
}