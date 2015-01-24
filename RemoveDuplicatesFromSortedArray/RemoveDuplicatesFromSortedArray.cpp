#include<iostream>
using namespace std;

int removeDuplicates(int A[], int n){
	if(0==n||1==n)return n;
	int p,r,q;
	p=r=0;q=p+1;
	while(q<=n-1){
		while(q<=n-1&&A[q]==A[p])q++;
		A[r]=A[p];r++;
		p=q;q++;
	}
	if(p==n-1) A[r]=A[p],r++;
	return r;
}
int main(){
	int A[]={};
	int m=removeDuplicates(A,sizeof(A)/sizeof(A[0]));
	for(int i=0;i<m;i++){
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
