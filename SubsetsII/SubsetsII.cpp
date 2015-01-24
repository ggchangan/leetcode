#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >&subsets,vector<int>&subset,vector<int>&S,int l, int r,int cur){
    int n=S.size();
    if(l==n){
        vector<int>t(subset.begin(),subset.begin()+cur);
        subsets.push_back(t);
        return;
    }
    while(S[r]==S[l])r++;
    int cnt=r-l;
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<i;j++)subset[cur]=S[l],cur++;
        dfs(subsets,subset,S,r,r+1,cur);
        cur-=i;
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S){
    vector<vector<int> >subsets;
    if(S.empty())return subsets;
    int ns=S.size();
    if(1==ns){
        vector<int>empty;
        subsets.push_back(empty);
        subsets.push_back(vector<int>(1,S[0]));
        return subsets;
    }
    vector<int>subset(ns,0);
    sort(S.begin(),S.end());
    int l=0;
    int r=1;
    int cur=0;
    dfs(subsets,subset,S,l,r,cur);

    return subsets;
}

int main(){
    int A[]={1,2,2};
    vector<int>S(A,A+sizeof(A)/sizeof(A[0]));
    vector<vector<int> >subsets=subsetsWithDup(S);
	for(int i=0;i<subsets.size();i++){
        for(int j=0;j<subsets[i].size();j++){
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
