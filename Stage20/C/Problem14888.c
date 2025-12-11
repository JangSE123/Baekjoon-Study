#include <stdio.h>
#include <limits.h>

int N;
int nums[12];
int op[4];
int max = INT_MIN;
int min = INT_MAX;

void dfs(int idx, int current) {
    if (idx == N) {
        if (current > max) max = current;
        if (current < min) min = current;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            if (i == 0) {
                dfs(idx + 1, current + nums[idx]);
            } else if (i == 1) {
                dfs(idx + 1, current - nums[idx]);
            } else if (i == 2) {
                dfs(idx + 1, current * nums[idx]);
            } else {
                int next;
                if (current < 0) {
                    next = - ( (-current) / nums[idx] );
                } else {
                    next = current / nums[idx];
                }
                dfs(idx + 1, next);
            }

            op[i]++;
        }
    }
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &op[i]);

    dfs(1, nums[0]);

    printf("%d\n%d\n", max, min);
    return 0;
}