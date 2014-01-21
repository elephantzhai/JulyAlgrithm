#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#define HASHLEN 2807303
#define WORDLEN 30;

typedef struct node_no_space *ptr_no_space;
typedef struct node_has-space *ptr_has_space;
ptr_no_space head[HASHLEN];

struct node_no_space{
    char *word;
    int count;
    ptr_no_space next;
};

struct node_has_space{
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
    while(p != null){
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
    File *fp = fopen("reaulst.txt","w");
    assert(fp);

    int i= 0;
    while(i < HASHLEN){
        for(ptr_no_space p = head[i];p != null;p=p->next)
            fprintf(fp, "%s %d\n", p->word,p->count);
        i++;
    }
    fclose(fp);

}
