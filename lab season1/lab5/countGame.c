#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    int position;
    struct node *next;
} node_t;
void append(node_t** head_ref, int new_data,int position)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    node_t *last = *head_ref;  
    new_node->position = position;
    new_node->data  = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }  

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;    
}
void showPosition(node_t *head) {
   node_t*ptr = head;
   while(ptr != NULL) {
      printf("%d ",ptr->position);
      ptr = ptr->next;
   }
   printf("\n");
   return;
}
void showdata(node_t *head) {
   node_t*ptr = head;
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }
   printf("\n");
   return;
}
void deleteNode(node_t **head_ref, int position)
{
   if (*head_ref == NULL)
      return;
   node_t* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;   
        free(temp);               
        return;
    }
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return;
    node_t *next = temp->next->next;
    free(temp->next);  
    temp->next = next; 
}
int getCount(node_t* head)
{
    int count = 0; 
    node_t* current = head; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int check_k(int num,int k){
    if (num%k == 0)
    {
        return 1;
    }
    char miko[1000];
    sprintf(miko,"%d",num);
    for(int i=0;i<strlen(miko);i++)
    {
        if ((k+'0')==miko[i])
        {
            return 1;
        }
    }
    return 0;
}
int getNowPosition(node_t *head,int val)
{
     node_t *current =head;
    int c= 0;
    while(current != NULL){
        if (current->position == val)
        {
            break;
        }
        c++;
        current = current->next;
    }
    return c;
}
int main(void){
    node_t *head;
    head = NULL;
    int n,k;
    int mik;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mik);
        append(&head,mik,i+1);
    }
    int number = 1;
    while(getCount(head) != 1)
    {
        node_t *ky = head;
        while(ky != NULL) {
            if(getCount(head)==1)
                break;
            if (check_k(number,k))
            {
                //printf("%d,%d,drink\n",ky->position,number);
                ky->data= ky->data-1;}
            //else
                //printf("%d,%d,not drink\n",ky->position,number);
            if(ky->data<0)
            { 
                //printf("%d %d\n",ky->position,getNowPosition(head,ky->position));
                deleteNode(&head,getNowPosition(head,ky->position));
                //showPosition(head);
            }
            ky = ky->next;
            number++;
         }
         if(getCount(head)==1)
            break;
   }
   showPosition(head);
 }
 
