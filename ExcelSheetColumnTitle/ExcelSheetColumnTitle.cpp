#include<iostream>
#include<string>
using namespace std;

string convertToTitle(int n){
    string ret="";
    while(n){
        char t=n%26?(n%26-1+'A'):'Z';
        ret=t+ret;
        n=n%26?(n/26):(n-26)/26;
    }

    return ret;
}

int main(){
    int n=703;
    cout << convertToTitle(n) << endl;	
	return 0;
}
