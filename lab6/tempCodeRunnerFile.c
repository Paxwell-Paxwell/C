stack_t *push(stack_t*s,int v){
    stack_t *node =(stack_t*)malloc(sizeof(stack_t));
    node->data = v;
    node->next =NULL;

    node->next = s;
    s = node;
    return s;
}