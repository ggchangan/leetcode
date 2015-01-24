#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findPeakElement(const vector<int> &num){
	int n=num.size();
	if(0==n)return -1;
	if(1==n)return 0;
	if(num[0]>num[1])return 0;
	int l=0,r=n-1;
	while(l<r){
		int m=(l+r)>>1;
		if(r-l==1)return num[l]>num[r]?l:r;
		if(num[m-1]>num[m])r=m-1;
		else l=m;
	}

	return l;
}

int main(){
	int A[]={1,2,3,1};
	vector<int>num(A,A+sizeof(A)/sizeof(A[0]));
	cout << findPeakElement(num)<<endl;
	return 0;
}
