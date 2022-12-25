#include <iostream>
#include <vector>

using namespace std;
typedef struct node{
    int data;
    struct node *next;
} node_t;

void show(node_t *head) {
   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }
   return;
}
void new_necklace(vector<node_t*>&neck,vector<node_t*>&all_add,int x,int y){
    node_t *tmp = neck[x-1];
    node_t *last_x=tmp;
    while (last_x->next!=NULL)
        last_x=last_x->next;
    neck[x-1]=NULL;
    node_t *tmp2 = all_add[y-1]->next;
    if(tmp2==NULL){
        all_add[y-1]->next=tmp;
        last_x->next=tmp2;
    }
    else if(tmp2!=NULL){
        all_add[y-1]->next=tmp;
        last_x->next=tmp2;
    }
}

int main(void){
    vector<node_t*> necklace;
    vector<node_t*> all_add;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        node_t *new_node = new node_t;
        necklace.push_back(new_node);
        all_add.push_back(new_node);
        necklace[i]->data = i+1;
        necklace[i]->next = NULL;  
    }
    int x,y;
    for (int i = 0; i < n-1; i++)
    {
        cin>>x>>y;
        new_necklace(necklace,all_add,x,y);
    
    }
     for (int i = 0; i < n; i++)
    {
        if(necklace[i]!= NULL){
            show(necklace[i]);
        }
    }
    cout<<"\n";
    
}