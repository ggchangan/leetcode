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
//结果判断也可以以剩余字符串为空来做
void dfs(vector<vector<string> >&palindromes,vector<string>&palindrome,const string &s, int l, int r, int level){
   for(int k=l;k<=r;k++){
        if(isPalindrome(s,l,k)){
            palindrome[level]=s.substr(l,k+1-l);
            if(k==r){
                palindrome.resize(level+1);
                palindromes.push_back(palindrome);
                palindrome.resize(s.size());
                return;
            }
            dfs(palindromes,palindrome,s,k+1,r,level+1);
        }
   } 
}
void dfs(vector<vector<string> >&palindromes,vector<string>&palindrome,string str){
    int n=str.size();
    if(0==n)palindromes.push_back(palindrome);
    for(int k=0;k<n;k++){
        if(isPalindrome(str,0,k)){
            palindrome.push_back(str.substr(0,k+1));
            string s=str.substr(k+1);
            dfs(palindromes,palindrome,s);
            palindrome.pop_back();
        }
    }
}
vector<vector<string> > partition(string s){
    vector<vector<string> >palindromes;
    if(s.empty())return palindromes;
    vector<string>palindrome;
    //dfs(palindromes,palindrome,s,0,n-1,0);
    dfs(palindromes,palindrome,s);
    return palindromes;
}

int main(){
    string s="aab";
    vector<vector<string> > palindromes=partition(s);
    for(int i=0;i<palindromes.size();i++){
        for(int j=0;j<palindromes[i].size();j++){
            cout << palindromes[i][j] << " ";
        }
        cout << endl;
    }    
	return 0;
}
