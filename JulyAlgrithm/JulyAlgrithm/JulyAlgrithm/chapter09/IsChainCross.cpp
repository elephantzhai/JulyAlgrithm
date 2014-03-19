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

bool detect(Node *head1,Node *head2){
	Node *circleNode1;
	Node *cilcleNode2;
	Node *lastNode1;
	Node *lastNode2;

	bool isCircle1 = isCircle(head1,circleNode1,lastNode1);
	bool isCircle2 = isCircle(head2,circleNode2,lastNode2);

	//一个有环，一个无环
	if(isCircle1 != circleNode2)
		return false;
	//两个都无环，判断最后一个节点是否相等
	else if(!isCircle1 && !isCircle2)
	{
		return lastNode1 == lastNode2;
	}
	//两个都有环
	else
	{
		Node *temp = circleNode1->next;
		while(temp!=circleNode1){
			if (temp == circleNode2)
				return true;
			temp = temp->next;
		}
		return false;
	}

}