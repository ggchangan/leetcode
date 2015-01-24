#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
	ListNode*p,*q,*ret,*r;
	ret=head,r=NULL,p=head,q=head?head->next:NULL;
	bool start=true;
	while(q){
		if(start){
			ret=q;start=false;
		}
		p->next=q->next;
		q->next=p;
		if(r)r->next=q;
		
		r=p;
		p=p->next;
		q=(NULL==p)?NULL:p->next;
	}

	return ret;	
}
int main(){
	/*
	ListNode*t1=new ListNode(1);
	ListNode*t2=new ListNode(2);
	ListNode*t3=new ListNode(3);
	ListNode*t4=new ListNode(4);
	ListNode*t5=new ListNode(5);
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=t5;
	*/
	ListNode*t1=NULL;
	ListNode*head=swapPairs(t1);
	while(head){
		cout << head->val << " ";
		head=head->next;
	}
	cout << endl;	
	return 0;
}
