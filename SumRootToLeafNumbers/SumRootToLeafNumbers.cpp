#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *root,vector<int> &path, int &sum){
    path.push_back(root->val);
    if(NULL==root->left&&NULL==root->right){
        int t=0;
        int i=0;
        while(0==path[i])i++;
        for(;i<path.size();i++){
            t=t*10+path[i];
        }
        sum+=t;
    }
    if(NULL!=root->left)preOrder(root->left,path,sum);
    if(NULL!=root->right)preOrder(root->right,path,sum);
    path.pop_back();
}

int sumNumbers(TreeNode *root) {
    if(NULL==root) return 0;
    vector<int>path;
    int sum=0;
    preOrder(root,path,sum);

    return sum;
}
int main(){
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t8 = new TreeNode(8);
	TreeNode *t11 = new TreeNode(6);
	TreeNode *t13 = new TreeNode(9);
	TreeNode *t0 = new TreeNode(0);
	TreeNode *t7 = new TreeNode(7);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t1 = new TreeNode(1);
	t5->left = t4;
	t5->right = t8;
	t4->left = t11;
	t4->right = t2;
	t11->left = t7;
	//t11->right = t2;
	t8->left = t13;
	t8->right = t0;
	t0->right = t1;
    cout << sumNumbers(t5) << endl;
	return 0;
}
