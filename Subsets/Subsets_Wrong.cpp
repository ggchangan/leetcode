#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int> > subsets(vector<int> &S){
    vector<vector<int> >ret;
    vector<int>empty;
    ret.push_back(empty);
    int n=S.size();
    if(0==n)return ret;
    sort(S.begin(),S.end());
    for(int i=0;i<n;i++)ret.push_back(vector<int>(1,S[i]));
    for(int i=1;i<n;i++){
        int cnt=ret.size();
        for(int j=0;j<cnt;j++){
            vector<int>t(ret[j]);
            t.push_back(S[i]);
            ret.push_back(t);
        } 
    }

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
