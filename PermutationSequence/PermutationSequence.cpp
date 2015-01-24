#include<iostream>
#include<string>
using namespace std;

string dfs(string str,int n, int t, int &k){
    if(t==n){
        //cout << str << endl;
        if(--k==0)return str;
        else return "";
    }
    for(int i=t;i<n;i++){
        char c=str[t];
        str[t]=str[i],str[i]=c;
        string s=dfs(str,n,t+1,k);
        if(!s.empty())return s;
        c=str[t];
        str[t]=str[i],str[i]=c;
    }

    return "";
}

string getPermutation(int n, int k){
    string str="";
    int cnt=1;
    for(int i=1;i<=n;i++)str+=char(i+'0'),cnt*=i;
    if(k>cnt)return "";
    return dfs(str,n,0,k);
}

int main(){
    int n=3;
    int k=4;
    string s=getPermutation(n,k);
    cout << s << endl;    
	return 0;
}
