#include<iostream>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *p=head;
	ListNode *q=head;
	while(n--)q=q->next;
	if(NULL==q)return head->next;
	while(q->next){p=p->next;q=q->next;}
	p->next=p->next->next;
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
	ListNode *t = removeNthFromEnd(t1,1);
	while(t){
		cout << t->val << " ";
		t=t->next;
	}
	cout << endl;
	return 0;
}
