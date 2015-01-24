#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows){
	vector<vector<int> >triangle;
	triangle.resize(numRows);
	for(int i=0;i<numRows;i++){
		triangle[i].resize(i+1);
		triangle[i][i]=1;
		for(int j=triangle[i].size()-2;j>0;j--){
			triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
		}
		triangle[i][0]=1;
	}

	return triangle;
}

int main(){
	int n = 0;
	vector<vector<int> >triangle=generate(n);
	for(int i=0;i<triangle.size();i++){
		for(int j=0;j<triangle[i].size();j++){
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
