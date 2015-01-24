#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> > &matrix){
	int n=matrix.size();
	for(int i=0;i<n/2;i++){
		for(int k=0;k<n-2*i-1;k++){
			int t=matrix[i][i+k];
			int l=n-i-1;
			matrix[i][i+k]=matrix[l-k][i];
			matrix[l-k][i]=matrix[l][l-k];
			matrix[l][l-k]=matrix[i+k][l];
			matrix[i+k][l]=t;
		}
	}
}

int main(){
	vector<vector<int> >matrix;
	int n=3;
	matrix.resize(n);
	for(int i=1;i<=n;i++){
		matrix[i-1].resize(n);
		for(int j=1;j<=n;j++){
			matrix[i-1][j-1]=j+n*(i-1);
			cout << matrix[i-1][j-1] << " ";
		}
		cout << endl;
	}
	cout << endl;

	rotate(matrix);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << matrix[i-1][j-1] << " ";
		}
		cout << endl;
	}

	return 0;
}
