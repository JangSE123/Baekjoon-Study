#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode* child[26];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) node->child[i] = NULL;
    return node;
}

int insert(TrieNode* root, char* str, int* cnt) {
    TrieNode* node = root;
    int newNodeAdded = 0;
    for (int i = 0; str[i]; i++) {
        int idx = str[i] - 'a';
        if (!node->child[idx]) {
            node->child[idx] = createNode();
            (*cnt)++;
        }
        node = node->child[idx];
    }
    return *cnt;
}

int main() {
    char s[1001];
    scanf("%s", s);

    TrieNode* root = createNode();
    int count = 0;
    int len = 0;
    while (s[len]) len++;

    for (int i = 0; i < len; i++) {
        insert(root, s + i, &count);
    }

    printf("%d\n", count);
    return 0;
}