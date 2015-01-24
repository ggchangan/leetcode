#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<climits>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon){
	int m=dungeon.size();
	int n=dungeon[0].size();
	vector<vector<int> >minSum(m+1,vector<int>(n+1,INT_MAX));
	vector<vector<int> >curSum(m+1,vector<int>(n+1,0));
	for(int j=1;j<=n;j++){
		curSum[1][j]=curSum[1][j-1]+dungeon[0][j-1];
		minSum[1][j]=min(minSum[1][j-1],curSum[1][j]);
	}
	for(int i=1;i<=m;i++){
		curSum[i][1]=curSum[i-1][1]+dungeon[i-1][0];
		minSum[i][1]=min(minSum[i-1][1],curSum[i][1]);
	}
	for(int i=2;i<=m;i++){
		for(int j=2;j<=n;j++){
			int top=min(curSum[i-1][j]+dungeon[i-1][j-1],minSum[i-1][j]);
			int left=min(curSum[i][j-1]+dungeon[i-1][j-1],minSum[i][j-1]);
			if(top>left){
				minSum[i][j]=top;curSum[i][j]=curSum[i-1][j]+dungeon[i-1][j-1];
			}
			else if(top<left){
				minSum[i][j]=left;curSum[i][j]=curSum[i][j-1]+dungeon[i-1][j-1];
			}
			else if(top==left){
				minSum[i][j]=top;
				curSum[i][j]=max(curSum[i-1][j],curSum[i][j-1])+dungeon[i-1][j-1];
			}
		}
	}

	return minSum[m][n]>=0?1:-minSum[m][n]+1;
}

int main(){
	int A[3][3]={
		{1,-3,3},
		{0,-2,0},
		{-3,-3,-3}
	};
	//int A[1][2]={{0,-3}};
	int m=3;
	vector<vector<int> >dungeon;
	dungeon.resize(m);
	for(int i=0;i<m;i++){
		dungeon[i].assign(A[i],A[i]+sizeof(A[i])/sizeof(A[i][0]));
	}
	ostream_iterator<int>output(cout," ");
	for(int i=0;i<m;i++){
		copy(dungeon[i].begin(),dungeon[i].end(),output);
		cout << endl;
	}

	cout << calculateMinimumHP(dungeon) << endl;
	return 0;
}
