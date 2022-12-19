#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node *next;
} node_t;

typedef node_t stk_t;

stk_t *push(stk_t **s, char value) {
    stk_t *add = (stk_t*)malloc(sizeof(stk_t));
    add -> data = value;
    add -> next = NULL;

    add -> next = *s;
    *s = add;
}

char top(stk_t *s) {
    return s->data;
}

stk_t *pop(stk_t *s) {
    if (s == NULL) return s;
    return s->next;
}

int check(char *text) {
    stk_t *s = (stk_t*)malloc(sizeof(stk_t));
    int i,lent = strlen(text),c=0;
    for (i=0;i<lent-1;i++) {
        //printf("%c\n", text[i]);
        if (text[i] == 'x') {
            if (c) return 0;
            c = 1;
        }
        else if (text[i] == 'y' && i!=lent-1) {
            return 0;
        }
        else if (c) {
            if (top(s) != text[i]) return 0;
            s = pop(s);
        }
        else if(!c) {
            push(&s, text[i]);
        };
    }
    return 1;
}

void main() {
    char *text = (char*)malloc(sizeof(char) * 1000000);
    scanf("%s", text);
    printf("%d\n", check(text));
    free(text);
}