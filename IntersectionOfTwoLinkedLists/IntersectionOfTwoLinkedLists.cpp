#include<iostream>
#include<cassert>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
	//assert(headA);assert(headB);
	if(!(headA&&headB)) return NULL;
	int na,nb;
	na=nb=1;
	ListNode *p = headA;
	ListNode *q = headB;
	while(p->next)++na,p=p->next;
	while(q->next)++nb,q=q->next;
	if(p!=q) return NULL;
	int diff=na-nb;
	if(diff>0){
		while(diff--){headA=headA->next;}
	}
	else if(diff<0){
		diff*=-1;
		while(diff--){headB=headB->next;}
	}
	while(headA&&headB){
		if(headA==headB) return headA;
		headA=headA->next;
		headB=headB->next;
	}

	return NULL;
}

int main(){
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t6 = new ListNode(6);
	ListNode *t7 = new ListNode(7);
	ListNode *t8 = new ListNode(8);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);
	ListNode *t5 = new ListNode(5);
	t1->next=t2;t2->next=t3;t3->next=t4;t4->next=t5;
	t6->next=t7;t7->next=t8;t8->next=t3;
	ListNode *t = getIntersectionNode(t1,t6);
	cout << t->val << endl;
	ListNode*p=NULL;
	ListNode*q=NULL;
	t = getIntersectionNode(p,q);
	return 0;
}
