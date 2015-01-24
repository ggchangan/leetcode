#include<iostream>
#include<queue>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
	if(NULL==root) return 0;
	queue<TreeNode*>tree;
	tree.push(root);
	int level=1;
	int cnt=1;
	while(!tree.empty()){
		TreeNode *t=tree.front();
	   	tree.pop();
		if(NULL==t->left&&NULL==t->right)return level;
		if(NULL!=t->left)tree.push(t->left);
		if(NULL!=t->right)tree.push(t->right);
		cnt--;
		if(0==cnt){
				level++;
				cnt=tree.size();
		}
	}	
	return -1;
}

int main(){
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t8 = new TreeNode(8);
	TreeNode *t11 = new TreeNode(11);
	TreeNode *t13 = new TreeNode(13);
	TreeNode *t14 = new TreeNode(4);
	TreeNode *t7 = new TreeNode(7);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t1 = new TreeNode(1);
	t5->left = t4;
	t5->right = t8;
	t4->left = t11;
	t11->left = t7;
	t11->right = t2;
	t8->left = t13;
	t8->right = t14;
	t14->right = t1;
	cout << minDepth(t5) << endl;
	return 0;
}
