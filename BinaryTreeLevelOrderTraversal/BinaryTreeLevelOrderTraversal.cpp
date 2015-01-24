#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> >levelNums;
	if(NULL==root)return levelNums;
	queue<TreeNode*>tree;
	tree.push(root);
	int level=1;
	int cnt=1;
	levelNums.resize(level);
	while(!tree.empty()){
		TreeNode *t=tree.front();
		tree.pop();
		cnt--;
		levelNums[level-1].push_back(t->val);
		if(t->left)tree.push(t->left);
		if(t->right)tree.push(t->right);
		if(0==cnt){
			level++;
			cnt=tree.size();
			levelNums.resize(level);
		}
	}
	levelNums.resize(level-1);
	return levelNums;
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
	vector<vector<int> >levelNums=levelOrder(t5);
	for(int i=0;i<levelNums.size();i++){
		for(int j=0;j<levelNums[i].size();j++){
			cout << levelNums[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
