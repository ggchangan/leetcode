#include<iostream>
#include<string>
#include<cctype>
using namespace std;


int lengthOfLastWord(const char *s){
	const char *p=s;
	while('\0'!=*p&&!isalpha(*p))p++;
	const char *q=p;
	while('\0'!=*q){
		while('\0'!=*q&&isalpha(*q))q++;
		while('\0'!=*q&&!isalpha(*q))q++;
		if('\0'==*q)break;
		p=q;
	}	
	q=p;
	while(isalpha(*q))q++;
	return q-p;
}
int main(){
	const char *s=" Hello World   ";
	cout << lengthOfLastWord(s) << endl;
	return 0;
}
