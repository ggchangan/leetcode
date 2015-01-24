#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
	ListNode *p,*q;
	if(!head)return head;
	p=head;
	q=p->next;
	while(q){
		ListNode *r=head,*pre=NULL;
		while(r!=q&&r->val<=q->val)pre=r,r=r->next;
		if(r==q)p=q,q=q->next;
		else{
			if(NULL==pre)head=q;
			else
				pre->next=q;
			p->next=q->next;
			q->next=r;
			q=p->next;	
		}	
	}

	return head;
}
int main(){
    /*
	ListNode *t2=new ListNode(2);
	ListNode *t1=new ListNode(1);
	ListNode *t3=new ListNode(3);
	ListNode *t5=new ListNode(5);
	//t2->next=t1;
	t1->next=t3;
	t3->next=t5;
	ListNode *t=insertionSortList(t2);
    */
    ListNode *t4=new ListNode(4);
    ListNode *t19=new ListNode(19);
    ListNode *t14=new ListNode(14);
    ListNode *t5=new ListNode(5);
    ListNode *t3=new ListNode(-3);
    ListNode *t1=new ListNode(1);
    ListNode *t8=new ListNode(8);
    ListNode *t52=new ListNode(5);
    ListNode *t11=new ListNode(11);
    ListNode *t15=new ListNode(15);
    t4->next=t19;
    t19->next=t14;
    t14->next=t5;
    t5->next=t3;
    t3->next=t1;
    t1->next=t8;
    t8->next=t52;
    t52->next=t11;
    t11->next=t15;
	ListNode *t=insertionSortList(t4);
	while(t){
		cout << t->val << " ";
		t=t->next;
	}
	cout << endl;

	return 0;
}
