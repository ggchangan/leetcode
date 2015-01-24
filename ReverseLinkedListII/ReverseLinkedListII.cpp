#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n) return head;
    ListNode *preRHead=NULL,*rHead,*p,*q,*prep;
    p=q=head;
    while(--m){
        preRHead=p;
        p=p->next; 
    }
    rHead=p;
    //q多走一步
    while(n--)q=q->next;
    prep=p;//保持不变
    p=p->next;
    while(p!=q){
        prep->next=p->next;
        if(NULL!=preRHead)
            preRHead->next=p;
        p->next=rHead;
        rHead=p;
        p=prep->next;
    }     
    /*
    prep->next=p->next;
    if(NULL!=preRHead)
        preRHead->next=p;
    p->next=rHead;
    rHead=p;
    */
    if(NULL==preRHead)head=rHead;

    return head;
}

int main(){
    ListNode *t1=new ListNode(1);
    ListNode *t2=new ListNode(2);
    ListNode *t3=new ListNode(3);
    ListNode *t4=new ListNode(4);
    ListNode *t5=new ListNode(5);
    t1->next=t2;
    t2->next=t3;
    t3->next=t4;
    t4->next=t5;
    ListNode *t=reverseBetween(t1,1,4);
    while(t){
        cout << t->val << " ";
        t=t->next;
    }
    cout << endl;
	return 0;
}
