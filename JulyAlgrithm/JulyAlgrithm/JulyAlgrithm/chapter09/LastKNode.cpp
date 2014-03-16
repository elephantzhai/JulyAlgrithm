#include <iostream>
using namespace std;

struct ListNode{
	char data;
	ListNode* next;
};

ListNode *head,*p,*q;
ListNode *pone,*ptwo;

ListNode* fun(ListNode *head,int k){
	assert(k>=0);
	pone = ptwo = head;

	for(;k>0 && ptwo != NULL;k--)
		ptwo = ptwo->next;

	if(k>0) return NULL;

	while(ptwo!=NULL){
		pone = pone->next;
		ptwo = ptwo->next;
	}
	return pone;
}


