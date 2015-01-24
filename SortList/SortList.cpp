#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeList(ListNode*left, ListNode*right){
	ListNode *p=left, *q=right;	
	ListNode *ret,*r;
	bool start=true;
	while(p&&q){
		if(start){
			if(p->val<q->val){
				ret=p;
				p=p->next;
			}
			else{
				ret=q;
				q=q->next;
			}
			r=ret;
			start=false;
		}
		else{
			if(p->val<q->val){
				r->next=p;
				p=p->next;
			}
			else{
				r->next=q;
				q=q->next;
			}
			r=r->next;
		}
	}
	r->next=p?p:q;
	return ret;
}

ListNode *sortList(ListNode *head) {
	ListNode *p,*q,*pre;
	if(!head)return head;
	p=head;
	pre=NULL;
	q=p->next;
	if(NULL==q)return head;
	int step=1;
	int n=0;
	while(q){
		pre=p;
		p=p->next;
		q=q->next;
		if(NULL==q){n=step*2;break;}
		else q=q->next,step++;	
	}
	if(0==n)n=step*2+1;
	if(1==n)return head;
	if(2==n){
		if(head->val>p->val)p->next=head,head->next=NULL,head=p;
		return head;
	}
	pre->next=NULL;
	ListNode *left=sortList(head);
	ListNode *right=sortList(p);
	head=mergeList(left,right);
	return head;
}
int main(){
	ListNode *t2=new ListNode(2);
	ListNode *t1=new ListNode(1);
	ListNode *t3=new ListNode(3);
	ListNode *t5=new ListNode(5);
	//t2->next=t1;
	//t1->next=t3;
	//t3->next=t5;
	t2->next=NULL;
	ListNode *t=sortList(NULL);

	while(t){
		cout << t->val << " ";
		t=t->next;
	}
	cout << endl;

	return 0;
}
