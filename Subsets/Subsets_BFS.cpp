#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
/*
bool myCompare(vector<int>t1, vector<int>t2){
    if(t1.size()<t2.size())return true;
    else if(t1.size()==t2.size()){
        for(int i=0;i<t1.size();i++){
            if(t1[i]<t2[i])return true;
            else if(t1[i]>t2[i]) return false;
        }
    }
    return false;
}
*/

vector<vector<int> > subsets(vector<int> &S){
    vector<vector<int> >ret;
    int n=S.size();
    if(0==n)return ret;
    sort(S.begin(),S.end());
    vector<int>empty;
    queue<vector<int> >setQueue;
    setQueue.push(empty);
    int level=0;
    int cnt=1;
    while(level<n){
        vector<int>subset=setQueue.front();
        setQueue.pop();
        vector<int>t=subset;
        subset.push_back(S[level]);
        setQueue.push(t);
        setQueue.push(subset);
        if(--cnt==0){
            level++;
            cnt=setQueue.size();
        }
    }    
    while(!setQueue.empty())ret.push_back(setQueue.front()),setQueue.pop();
    //sort(ret.begin(),ret.end(),myCompare);
    return ret;
}

int main(){
    int A[]={4,1,0};
    vector<int>S(A,A+sizeof(A)/sizeof(A[0]));
    vector<vector<int> >ret=subsets(S);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }    
	return 0;
}
