#include<iostream>
#include<cmath>
using namespace std;


bool isPalindrome(int x){
	if(x<0) return false;
	if(0==x)return true;
	if(0==x%10)return false;
	int n=0;
	int t=x;
	while(t)t/=10,n++;
	for(int i=1;i<=n/2;i++){
		int r=(x%(int(pow(10,i))))/(int(pow(10,i-1)));
		int l=(x/(int(pow(10,n-i))))%10;
		if(l!=r)return false;
	}
	return true;
}

int main(){
	cout << isPalindrome(1234321) << endl;
	return 0;
}
