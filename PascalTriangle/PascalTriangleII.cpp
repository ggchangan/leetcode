#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex){
	vector<int> row;
	row.resize(rowIndex+1);
	//row[rowIndex]=1;
	row[0]=1;
	for(int i=1;i<=rowIndex;i++){
		row[i]=1;
		for(int j=i-1;j>0;j--){
			row[j]+=row[j-1];
		}
	}

	return row;
}
int main(){
	int n=0;
	vector<int> row=getRow(n);
	for(int i=0;i<row.size();i++){
		cout << row[i] << " ";
	}
	cout << endl;
	return 0;
}
