#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool isPalindrome(string s){
	s='a'+s;
	s=s+'a';
	int n = s.size();
	if(0==n) return true;
	int i=0,j=n-1;
	while(i<j){
		while(!isalnum(s[i]))i++;
		while(!isalnum(s[j]))j--;
		if(s[i]==s[j]){i++;j--;continue;}
		if(tolower(s[i])==tolower(s[j])){i++;j--;continue;}
		return false;
	}
	return true;
}

int main(){
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	string s3 = " :,:,  :,   ";
	cout << isPalindrome(s1) << endl;
	cout << isPalindrome(s2) << endl;
	cout << isPalindrome(s3) << endl;
	return 0;
}
