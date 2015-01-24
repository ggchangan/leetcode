#include<iostream>
#include<vector>
using namespace std;


bool isValidSudoku(vector<vector<char> > &board) {
	vector<bool>ten;
	for(int i=0;i<9;i++){
		ten.clear();
		ten.resize(10,true);
		for(int j=0;j<9;j++){
			if('.'==board[i][j])continue;
			int t=board[i][j]-'0';
			if(ten[t])ten[t]=false;
			else  return false;
		}		
	}
	
	for(int j=0;j<9;j++){
		ten.clear();
		ten.resize(10,true);
		for(int i=0;i<9;i++){
			if('.'==board[i][j])continue;
			int t=board[i][j]-'0';
			if(ten[t])ten[t]=false;
			else  return false;
		}
	}
	for(int i=0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			ten.clear();
			ten.resize(10,true);
			for(int l=i;l<i+3;l++){
				for(int m=j;m<j+3;m++){
					if('.'==board[l][m])continue;
					int t=board[l][m]-'0';
					if(ten[t])ten[t]=false;
					else  return false;
				}
			}
		}
	}

	return true;
}

int main(){
	return 0;
}
