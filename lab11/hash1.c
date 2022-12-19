#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEXTSIZE 21

typedef struct item{
    char *text;
    struct item *next;
} item_t;

typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
}hash_t;

hash_t * init_hashtable(int m,int hash_key){
    item_t **ntable = (item_t**)malloc(sizeof(item_t*)*m);
    hash_t *new = (hash_t*)malloc(sizeof(hash_t));
    new->hash_key=hash_key;
    new->size=m;
    for(int i=0;i<m;i++)
        ntable[i]=NULL;
    new->table= ntable;
    return new;
}

unsigned int f(int hash_key,char*text,int n){
    if (n==1)
        return text[0];
    return hash_key*f(hash_key,text,n-1)+text[n-1];
}
int hash_table(hash_t* hashtable,char* text,int size){
    //printf("%u",f(hashtable->hash_key,text,strlen(text)-1));
    return f(hashtable->hash_key,text,strlen(text))%(size);
}
void insert(hash_t *hashtable,char *text){
    char *str = (char* )malloc(sizeof(char)*20);
    strcpy(str,text);
    item_t *new = (item_t*)malloc(sizeof(item_t));
    new->text=str;
    new->next =NULL;
    int num_table = hash_table(hashtable,text,hashtable->size);
    if (hashtable->table[num_table]==NULL)
    {
        hashtable->table[num_table]= new;
        return;
    }
    item_t *current= hashtable->table[num_table];
    while(current->next !=NULL)
        current = current->next;
    current->next = new;
}
void printhash(hash_t *hashtable){
    for(int i=0;i<hashtable->size;i++){
        item_t *current = hashtable->table[i];
        while(current!=NULL)
        {   
        printf("%s",current->text);
        current=current->next;
        }
        printf("\n");
    }
}
int search(hash_t *hashtable,char *text){
    int index = -1;
    int num_table = hash_table(hashtable,text,hashtable->size);
    item_t *current = hashtable->table[num_table];
    while(current!=NULL)
    {   //printf("%s,%s",current->text,text);
        if (strcmp(current->text,text)==0)
        {
            index=num_table;
            break;
        }
        current=current->next;
    }
    return index;
}
int main(void){
    hash_t *hashtable =NULL;
    char *text =NULL;
    int m,n,i, hash_key;
    int command;
    
    scanf("%d %d %d", &m,&n,&hash_key);
    hashtable = init_hashtable(m,hash_key);
    text = (char*)malloc(sizeof(char)*TEXTSIZE);

    for(i=0;i<n;i++){
        scanf("%d %s",&command,text);
        switch (command)
        {
        case 1:
            insert(hashtable,text);
            break;
        case 2:
            printf("%d\n",search(hashtable,text));
            break;
            
        }

    }
    return 0;
}