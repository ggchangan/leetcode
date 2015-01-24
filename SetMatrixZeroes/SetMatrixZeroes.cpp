#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void setZeroes(vector<vector<int> > &matrix){
    if(matrix.empty())return;
    int m=matrix.size();
    int n=matrix[0].size();
    int zeroRow=0,zeroCol=0;
    bool find=false;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(!matrix[i][j]){find=true;zeroRow=i,zeroCol=j;break;} 
        }
        if(find)break;
    }
    if(!find)return;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==zeroRow||j==zeroCol)continue;
           if(!matrix[i][j]){
                matrix[zeroRow][j]=0;
                matrix[i][zeroCol]=0;
           } 
        }
    }
    for(int i=0;i<m;i++){
        if(!matrix[i][zeroCol]){
           for(int j=0;j<n;j++){
               if(i==zeroRow||j==zeroCol)continue;
               matrix[i][j]=0;
           } 
        }
    }

    for(int j=0;j<n;j++){
        if(!matrix[zeroRow][j]){
            for(int i=0;i<m;i++){
                if(i==zeroRow||j==zeroCol)continue;
                matrix[i][j]=0;
            }
        }
    }
    for(int j=0;j<n;j++)matrix[zeroRow][j]=0;
    for(int i=0;i<m;i++)matrix[i][zeroCol]=0;
}

int main(){
    int m=5;
    int n=4;
    int A[m][n]={{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    //int A[m][n]={{9,-6,-1,-2,5},{-1,3,INT_MAX,-4,0},{-3,-4,0,4,INT_MIN}};
    vector<vector<int> >matrix(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            matrix[i][j]=A[i][j];
    
    setZeroes(matrix);    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
