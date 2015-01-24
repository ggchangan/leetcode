#include<iostream>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(vector<vector<int> >&paths,TreeNode *root, int sum, vector<int>&path,int level){
   if(NULL==root->left&&NULL==root->right){
        if(sum==root->val){
            path.push_back(root->val);
            paths.push_back(path); 
        }
        return;
    }
    //if(sum<=root->val)return;
    sum-=root->val;
    path.push_back(root->val);
    if(root->left)preOrder(paths,root->left,sum,path,level+1);
    path.resize(level);
    if(root->right)preOrder(paths,root->right,sum,path,level+1);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> >paths;
    if(NULL==root) return paths;
    vector<int>path;
    preOrder(paths,root,sum,path,1);
    return paths;
}
int main(){
    TreeNode *t5=new TreeNode(5);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t8=new TreeNode(8);
    TreeNode *t11=new TreeNode(11);
    TreeNode *t13=new TreeNode(13);
    TreeNode *t14=new TreeNode(4);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t15=new TreeNode(5);
    TreeNode *t1=new TreeNode(1);

    t5->left=t4;
    t5->right=t8;
    t4->left=t11;
    t11->left=t7;
    t11->right=t2;
    t8->left=t13;
    t8->right=t14;
    t14->right=t15;
    t14->left=t1;
    int sum=22;
    vector<vector<int> >paths=pathSum(t5,sum);
    for(int i=0;i<paths.size();i++){
        for(int j=0;j<paths[i].size();j++){
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
