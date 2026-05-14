#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void add(char* name, int score) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->score = score;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = n;
}

void delete(char* name) {
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void print() {
    Node* cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void quit() {
    Node* cur = head;
    while (cur != NULL) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main() {
    char cmd[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } else if (strcmp(cmd, "print") == 0) {
            print();
        } else if (strcmp(cmd, "quit") == 0) {
            quit();
            break;
        }
    }

    return 0;
}
