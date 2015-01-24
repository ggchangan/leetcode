#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target){
	int m=matrix.size();
	int n=matrix[0].size();
	int lRow=0,rRow=m-1;
	int row=0;
	while(lRow<rRow){
		int mRow=(lRow+rRow)>>1;
		int t=matrix[mRow][n-1];
		if(t==target){lRow=mRow;break;}
		else if(t<target)lRow=mRow+1;
		else if(t>target)rRow=mRow;
	}
	row=lRow;
	int l=0,r=n-1;
	if(1==n)return matrix[row][0]==target;
	while(l<r){
		int m=(l+r)>>1;
		int t=matrix[row][m];
		if(t==target)return true;
		else if(t<target)l=m+1;
		else if(t>target)r=m-1;
	}
	return false;
}

int main(){
	/*
	int A[][4]={
		{1,3,5,7},
		{10,11,16,20},
		{23,30,34,50}
	};
	*/
	int A[][1]={
		{1},
		{3},
		{5}
	};
	vector<vector<int> >matrix;
	int m=sizeof(A)/sizeof(A[0]);
	int n=sizeof(A[0])/sizeof(A[0][0]);
	matrix.resize(m);
	for(int i=0;i<m;i++){
		matrix[i].resize(n);
		for(int j=0;j<n;j++){
			matrix[i][j]=A[i][j];
		}
	}

	cout << searchMatrix(matrix,3) << endl;
	return 0;
}
