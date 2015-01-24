#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<climits>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon){
	int m=dungeon.size();
	int n=dungeon[0].size();
	vector<vector<int> >dp(m+1,vector<int>(n+1,0));
	for(int j=n-1;j>=0;j--){
		dp[m-1][j]=max(dp[m-1][j+1]-dungeon[m-1][j],0);
	}
	for(int i=m-1;i>=0;i--){
		dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],0);
	}
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],0);
		}
	}

	return dp[0][0]+1;
}

int main(){
	/*
	int A[3][3]={
		{1,-3,3},
		{0,-2,0},
		{-3,-3,-3}
	};
	int A[3][3]={
		{-2,-3,3},
		{-5,-10,1},
		{10,30,-5}
	};
	*/
	int A[1][2]={{0,-3}};
	int m=1;
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
