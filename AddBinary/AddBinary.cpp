#include<iostream>
#include<string>

using namespace std;
string addBinary(string a, string b){
	if(b.size()>a.size()){string t=a;a=b;b=t;}
	int carry=0;
	for(int i=b.size()-1,j=a.size()-1;i>=0;i--,j--){
		int sum=carry+(a[j]-'0')+(b[i]-'0');
		carry=sum/2;
		a[j]=sum%2+'0';
	}
	if(0==carry)return a;
	int j;
	for(j=a.size()-b.size()-1;j>=0;j--){
		if('1'==a[j])a[j]='0';
		else{
			a[j]='1';
			break;
		}
	}
	if(-1==j)return '1'+a;
	return a;
}
int main(){
	string a="11111";
	string b="1111";
	cout << addBinary(a,b)<<endl;
	return 0;
}
