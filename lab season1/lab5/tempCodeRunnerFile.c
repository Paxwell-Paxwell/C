 node_t *current =head;
    int c= 0;
    while(current != NULL){
        if (c== index)
        {
            printf("%d\n",current->data);
        }
        c++;
        current = current->next;
    }
    return;