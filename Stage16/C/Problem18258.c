#include <stdio.h>
#include <string.h>

#define MAX 2000000

int queue[MAX];
int front = 0, back = 0;

int empty() {
    return front == back;
}

int size() {
    return back - front;
}

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    char cmd[20];
    char output[8000000];
    int out_idx = 0;

    for (int i = 0; i < N; i++) {
        fgets(cmd, sizeof(cmd), stdin);

        if (strncmp(cmd, "push", 4) == 0) {
            int x;
            sscanf(cmd + 5, "%d", &x);
            queue[back++] = x;
        }
        else if (strncmp(cmd, "pop", 3) == 0) {
            if (empty())
                out_idx += sprintf(output + out_idx, "-1\n");
            else
                out_idx += sprintf(output + out_idx, "%d\n", queue[front++]);
        }
        else if (strncmp(cmd, "size", 4) == 0) {
            out_idx += sprintf(output + out_idx, "%d\n", size());
        }
        else if (strncmp(cmd, "empty", 5) == 0) {
            out_idx += sprintf(output + out_idx, "%d\n", empty());
        }
        else if (strncmp(cmd, "front", 5) == 0) {
            if (empty())
                out_idx += sprintf(output + out_idx, "-1\n");
            else
                out_idx += sprintf(output + out_idx, "%d\n", queue[front]);
        }
        else if (strncmp(cmd, "back", 4) == 0) {
            if (empty())
                out_idx += sprintf(output + out_idx, "-1\n");
            else
                out_idx += sprintf(output + out_idx, "%d\n", queue[back - 1]);
        }
    }

    fwrite(output, 1, out_idx, stdout);
    return 0;
}