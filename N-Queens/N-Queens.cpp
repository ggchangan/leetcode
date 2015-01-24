#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

bool isValid(const vector<int> solve,int x, int y,int t){
    for(int i=0;i<t;i++){
        if(solve[i]==y||abs(i-x)==abs(solve[i]-y))return false;
    }
    return true;
}

void backtrace(vector<vector<int> >&solves,vector<int> &solve,int n, int t){
    if(t==n){
        solves.push_back(solve);
        return;
    }
    for(int j=0;j<n;j++){
        if(isValid(solve,t,j,t)){
            solve[t]=j;
            backtrace(solves,solve,n,t+1);            
        }
    }
}

vector<vector<string> > solveNQueens(int n){
    vector<vector<string> >results;
    if(0==n)return results;
    vector<vector<int> >solves;
    vector<int>solve(n,-1);
    backtrace(solves,solve,n,0);
    string t(n,'.');
    for(int i=0;i<solves.size();i++){
        vector<string>result(n,t);
        for(int j=0;j<solves[i].size();j++){
            result[j][solves[i][j]]='Q';
        }
        results.push_back(result);
    }

    return results;
}

int main(){
    int n=4;
    vector<vector<string> >solutions=solveNQueens(n);
    for(int i=0;i<solutions.size();i++){
        cout << "Solution" << " " << i+1 << endl;
        for(int j=0;j<solutions[i].size();j++){
            cout << solutions[i][j] << endl;
        }
        cout << endl << endl;
    }
	return 0;
}
