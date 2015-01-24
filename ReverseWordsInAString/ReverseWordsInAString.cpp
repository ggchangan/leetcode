#include<iostream>
#include<string>
using namespace std;


void reverseWords(string &s){
	if(s.empty())return;
	string word="";
	int n=s.size();
	int p=0,q=0;
	string ret="";
	bool start=true;
	while(p<n){
		while(p<n&&' '==s[p])p++;
		q=p;
		while(q<n&&' '!=s[q])q++;
		word=s.substr(p,q-p);
		if(word.empty()){s=ret;return;}
		if(start)ret=word,start=false;
		else ret=word+" "+ret;
		p=q;
	}

	s=ret;
}
int main(){
	string s="   word is    ";
	reverseWords(s);
	cout << s << endl;	
	return 0;
}
