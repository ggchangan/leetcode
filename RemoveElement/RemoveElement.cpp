#include<iostream>
using namespace std;
int removeElement(int A[], int n, int elem){
	if(0==n)return 0;
	int p=0,q=n-1;
	while(p<q){
		while(p<q&&A[p]!=elem)p++;
		while(q>p&&A[q]==elem)q--;
		if(p>=q)break;
		int t=A[p];A[p]=A[q];A[q]=t;
		p++;q--;
	}
	p=0;
	while(p<=n-1&&A[p]!=elem)p++;
	return p;
}


int main(){
	int A[]={};
	int m= removeElement(A,sizeof(A)/sizeof(A[0]),5);
	for(int i=0;i<m;i++){
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
