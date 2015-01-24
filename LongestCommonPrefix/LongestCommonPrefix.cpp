#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	int n=strs.size();
	if(0==n)return "";
	if(1==n)return strs[0];
	for(int l=1;l<=strs[0].size();l++){
		for(int i=1;i<strs.size();i++){
			if(strs[0].substr(0,l)!=strs[i].substr(0,l)) return strs[0].substr(0,l-1);
		}
	}

	return strs[0];
}
int main(){
	string s1="gaabbbc";
	string s2="aabbbb";
	string s3="aabbbbbb";
	vector<string>strs;
	strs.push_back(s1);
	strs.push_back(s2);
	strs.push_back(s3);
	cout << longestCommonPrefix(strs) << endl;
}
