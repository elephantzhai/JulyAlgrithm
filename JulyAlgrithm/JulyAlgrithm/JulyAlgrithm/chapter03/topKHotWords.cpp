#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>
#include <stdio.h>
using namespace std;

#define HASHLEN 2807303
#define WORDLEN 30

typedef struct node_no_space *ptr_no_space;
typedef struct node_has_space *ptr_has_space;
ptr_no_space head[HASHLEN];

struct node_no_space
{
    char *word;
    int count;
    ptr_no_space next;
};

struct node_has_space
{
    char word[WORDLEN];
    int count;
    ptr_has_space next;
};

int hash_function(char const *p){
    int value = 0;
    while(*p != '/0'){
        value = value*31+*p++;
        if(value > HASHLEN)
            value = value % HASHLEN;

    }
    return value;
}

void append_word(char const *str){
    int index = hash_function(str);
    ptr_no_space p = head[index];
    while(p != NULL){
        if(strcmp(str,p->word)==0){
            (p->count)++;
            return;
        }
        p = p->next;
    }

    ptr_no_space q = new node_no_space;
    q->count = 1;
    q->word = new char[strlen(str)+1];
    strcpy(q->word,str);
    q->next = head[index];
    head[index] = q;

}

void write_to_file(){
    FILE *fp = fopen("reaulst.txt","w");
    assert(fp);

    int i= 0;
    while(i < HASHLEN){
        for(ptr_no_space p = head[i];p != NULL;p=p->next)
            fprintf(fp, "%s %d\n", p->word,p->count);
        i++;
    }
    fclose(fp);
}

void sift_down(node_has_space heap[],int i,int len){
    int min_index = -1;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=len && heap[left].count<heap[i].count)
        min_index = left;
    else
        min_index = i;

    if(right<=len && heap[right].count<heap[min_index].count)
        min_index = right;
    if(min_index != i){
        swap(heap[i].count,heap[min_index].count);

        char buffer[WORDLEN];
        strcpy(buffer,heap[i].word);
        strcpy(heap[i].word,heap[min_index].word);
        strcpy(heap[min_index].word,buffer);

        sift_down(heap,min_index,len);
    }

}

int main(){
    return 0;
}
