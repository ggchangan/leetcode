#include<iostream>
using namespace std;

void merge(int A[], int m, int B[], int n){
	for(int i=m-1;i>=0;i--)A[n+i]=A[i];
	int p=n,q=0,r=0;
	while(p<m+n&&q<n){
		if(A[p]<=B[q]){ A[r++]=A[p++]; }
		else A[r++]=B[q++];
	}
	if(p==m+n){
		while(q<n)A[r++]=B[q++];
	}
}

int main(){
	int A[100]={4};
	int B[]={1,2,3,5,6};
	merge(A,1,B,5);
	for(int i=0;i<10;i++){
		cout << A[i] << endl;
	}
	return 0;
}
