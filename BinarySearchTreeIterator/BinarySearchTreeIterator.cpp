#include<iostream>
#include<stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	stack<TreeNode*>nodes;
    BSTIterator(TreeNode *root) {
        if(NULL==root)return;
        nodes.push(root);
        while(root->left)nodes.push(root->left),root=root->left;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }
    /** @return the next smallest number */
    int next() {
        TreeNode *t=nodes.top();
        int ret=t->val;
        nodes.pop();
        if(t->right){
            nodes.push(t->right);
            t=t->right->left;
            while(t)nodes.push(t),t=t->left;
        }
        return ret;
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main(){
    TreeNode *t5=new TreeNode(5);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t1=new TreeNode(1);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t6=new TreeNode(6);
    TreeNode *t8=new TreeNode(8);

    t5->left=t3;
    t5->right=t7;
    t3->left=t1;
    t3->right=t4;
    t7->left=t6;
    t7->right=t8;
    BSTIterator i = BSTIterator(t5);
    while (i.hasNext()) cout << i.next();
	return 0;
}
