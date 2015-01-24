#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int> &digits){
	int n=digits.size();
	int i;
	for(i=n-1;i>=0;i--)if(9!=digits[i])break;
	if(-1==i){digits.resize(0);digits.resize(n+1,0);digits[0]=1;return digits;}
	for(i=n-1;i>=0;i--){
		if(9==digits[i])digits[i]=0;
		else{
			digits[i]++;
			break;
		}
	}	
	return digits;
}
int main(){
	
	return 0;
}
