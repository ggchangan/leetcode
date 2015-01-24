#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head){
    if(NULL==head)return NULL;
    if(NULL==head->next)return head;
    ListNode *t=head->next;
    head->next=NULL;
    ListNode *ret=reverseList(t);
    t=ret;
    while(NULL!=t->next)t=t->next;
    t->next=head;
    return ret;
}

ListNode *mergeList(ListNode *left, ListNode *right){
    ListNode *p=left,*q=right;
    while(q){
        ListNode *lt=p->next,*rt=q->next;
        p->next=q;q->next=lt;q=rt;p=lt;
    }
    return left;
}
/*
void reorderList(ListNode *head) {
    if(NULL==head)return;
    ListNode *p=head,*q=head->next,*right;
    while(q){
        q=q->next;
        if(NULL!=q)q=q->next;
        else{
            continue;
        }
        p=p->next;
    }
    right=p->next;
    p->next=NULL;
    right=reverseList(right);
    head=mergeList(head,right);
}
*/

void reorderList(ListNode *head){
    if(NULL==head || NULL==head->next)return;
    ListNode *slow,*quick,*right;
    slow=quick=head;
    while(NULL!=quick->next && NULL!=quick->next->next){
        slow=slow->next;
        quick=quick->next->next;
    }
    right=slow->next;
    slow->next=NULL;
    ListNode *q=right->next;
    right->next=NULL;
    while(q){
        ListNode *pre=q;q=q->next;
        pre->next=right;right=pre;
    }
    
    head=mergeList(head,right);
}

int main(){
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
	reorderList(t4);
    ListNode *t=t4;
	while(t){
		cout << t->val << " ";
		t=t->next;
	}
	cout << endl;
	return 0;
}
