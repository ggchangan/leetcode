#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

bool valid(string str){
    int n=str.size();
    if(1==n)return true;
    if('0'==str[0])return false;
    stringstream st(str);
    int i;
    st>>i;
    if(i>255) return false;

    return true;
}
void dfs(vector<string>&ips,vector<string>ip,string s,int l, int r, int k){
    if(0==k&&(l-r==1)){
        string t=ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3];
        ips.push_back(t);
        return;
    }
    int n=r-l+1;
    if(n>k*3) return;
    for(int i=max(1,n-3*(k-1));i<=min(3,n-k+1);i++){
        string t=s.substr(l,i);
        if(!valid(t))continue;
        stringstream st(t);
        st>>ip[4-k];
        dfs(ips,ip,s,l+i,r,k-1);
    }
}

vector<string> restoreIpAddresses(string s){
    int n=s.size();
    vector<string>ips;
    if(n<4) return ips;
    vector<string> ip(4,"");
    dfs(ips,ip,s,0,n-1,4);
    return ips;
}
int main(){
    string s="2520051113";
    vector<string>ips=restoreIpAddresses(s);	
    for(int i=0;i<ips.size();i++){
        cout << ips[i] << endl;
    }
	return 0;
}
