#include <stdio.h>
#include <string.h>

int prefix[26][200001];

int main(void) {
    char S[200001];
    scanf("%s", S);

    int n = strlen(S);

    for (int i = 0; i < n; i++) {
        int c = S[i] - 'a';

        for (int j = 0; j < 26; j++) {
            prefix[j][i + 1] = prefix[j][i];
        }

        prefix[c][i + 1]++;
    }

    int q;
    scanf("%d", &q);

    while(q--) {
        char ch;
        int l, r;
        scanf(" %c %d %d", &ch, &l, &r);

        int idx = ch - 'a';
        printf("%d\n", prefix[idx][r + 1] - prefix[idx][l]);
    }

    return 0;
}