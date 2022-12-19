#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char        data;
    struct node *next; 
} node_t;

typedef node_t stk;

void push(stk **s, char value) {
    stk *node = (stk *)malloc(sizeof(stk));
    node -> data = value;
    node -> next = NULL;

    node -> next = *s;
    *s = node;  
}

stk *pop(stk *s) {
    if (s == NULL) {
        return s;
    }
    else {
        stk *tmp = s;
        s = s -> next;
        free(tmp);
    }
    return s;
}

char top(stk *s) {
    if(s == NULL) {
      return 0;
    }
    return s -> data;
}

int size(stk *s) {
    int c = 0;
    while (s != NULL) {
        c++;
        s = s -> next;
    }
    return c;
}

int main(void) {
    stk *s = NULL;
    int final_size;
    char pass, t;

    scanf(" %c", &pass);
    while (pass != 'x') {
        push(&s, pass);
        scanf(" %c", &pass);
    }


    scanf(" %c", &pass);
    while (pass != 'y') {
        if (pass == 'y'){
            break;
        }
        t = top(s);
        if (pass != t) {
            printf("0");
            return 0;
        }
        else {
            s = pop(s);
        }
        scanf(" %c", &pass);
    }
    final_size = size(s);
    if (final_size == 0) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}