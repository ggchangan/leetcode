#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string s, int l, int r){
    if(r<=l)return true;
    while(l<r){
        if(s[l++]!=s[r--])return false;
    }

    return true;
}

//ZR 利用回文判定的方法
int minCut_zr(string s){
    int n=s.size();
    if(0==n||1==n)return 0;
    vector<vector<int> >dp(n,vector<int>(n,n));
    for(int i=0;i<n;i++)dp[i][i]=0;
    for(int l=1;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;
            if(isPalindrome(s,i,j))dp[i][j]=0;
            else{
                for(int k=i;k<j;k++){
                    int t=dp[i][k]+dp[k+1][j]+1;
                    if(dp[i][j]>t)dp[i][j]=t;
                }
            }
        }
    }

    return dp[0][n-1];
}
//dp[i][j]用于判断s[i..j]是否为回文串
//cut[j]代表s[0,j]的最小切割数
int minCut(string s){
    int n=s.size();
    if(0==n||1==s.size())return 0;
    vector<vector<bool> >dp(n,vector<bool>(n,false));
    vector<int>cut(n,n);
    for(int j=0;j<n;j++){
        cut[j]=j;
        for(int i=0;i<=j;i++){
            if((s[i]==s[j])&&(j-i<=1||dp[i+1][j-1])){
                dp[i][j]=true;
                if(0==i)cut[j]=0;
                else{
                    cut[j]=min(cut[i-1]+1,cut[j]);
                }
            }
        }
    }

    return cut[n-1];
}

int main(){
    string s="abbab";
    cout << minCut(s) << endl;
	return 0;
}
