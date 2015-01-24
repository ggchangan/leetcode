#include<iostream>
using namespace std;

void sortColors(int A[], int n){
	int i=0;
	for(int j=1;j<n;j++,i++){
		if(A[j]<A[i]){
			int t=A[j];A[j]=A[i];
			int k;
			for(k=i-1;k>=0;k--){
				if(A[k]>t)A[k+1]=A[k];
				else break;
			}
			A[k+1]=t;
		}
	}
}

int main(){
	//int A[]={1,1,2,1,1,3,2,3,2,2};
	int A[]={};
	sortColors(A,sizeof(A)/sizeof(A[0]));
	for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
