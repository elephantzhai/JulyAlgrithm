#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node *next;

};

bool isCircle(Node *head,Node *& circleNode,Node *& lastNode){
	Node *fase = head;
	Node *slow = head->next;

	while(fast == slow & fast & slow){
		if(fast->next!=NULL)
			fast = fast->next;

		if(fast->next == NULL)
			lastNode = fast;
		if(slow->next == NULL)
			lastNode = slow;

		fast = fast->next;
		slow = slow->next;
	}
	if(fast == slow & slow & fast){
		circleNode = fast;
		return true;
	}else{
		return false;
	}
}