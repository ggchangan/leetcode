#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

bool dfs(vector<vector<char> >&board,const string &word,int t,int x,int y,
        const int step[4][2]){
    int nw=word.size();
    if(t==nw)return true;
    int m=board.size();
    int n=board[0].size();
    if(word[t]==board[x][y]){
        board[x][y]^=0x80;
        for(int i=0;i<4;i++){
            int nx=x+step[i][0],ny=y+step[i][1];
            if((nx>=0&&nx<m)&&(ny>=0&&ny<n)){
                if(dfs(board,word,t+1,nx,ny,step)) return true;
            }
        }
        board[x][y]^=0x80;
    }
    
    return false;
}

bool exist(vector<vector<char> > &board, string word){
    int nw=word.size();
    if(0==nw)return true;
    int step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int m=board.size();
    int n=board[0].size();
    if(1==n&&1==m)return (1==nw&&board[0][0]==word[0]);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0]){
                if(dfs(board,word,0,i,j,step)) return true;
            }
        }
    }
    return false;
}

int main(){
    int m=3;
    int n=4;
    string A[m]={"ABCE","SFCS","ADEE"};
    vector<vector<char> >board;
    board.resize(m);
    for(int i=0;i<m;i++){
        board[i].resize(n);
        for(int j=0;j<n;j++){
            board[i][j]=A[i][j];
        }
    }    
    string words[5]={"SEE","SEEDASABBA","ABCCED","SEE","ABCB"};
    //for(int i=0;i<5;i++)
        //cout << exist(board,words[i]) << endl;
    cout << exist(board,"ABCB") << endl;
	return 0;
}
