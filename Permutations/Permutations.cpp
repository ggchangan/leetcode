#include<iostream>
#include<vector>
using namespace std;

void swap(int &x, int &y){
	if(x==y) return;
	x^=y;
	y^=x;
	x^=y;
}

void generate(vector<int>num,int start,vector<int> &permutation, vector<vector<int> >&permutations){
	int n=num.size();
	if(start==n-1){
		permutation[start]=num[start];
		permutations.push_back(permutation);
		return;
	}

	for(int i=start;i<n;i++){
		swap(num[start],num[i]);
		permutation[start]=num[start];
		generate(num,start+1,permutation,permutations);
		swap(num[start],num[i]);
	}
}
vector<vector<int> > permute(vector<int> &num){
		vector<vector<int> >permutations;
		vector<int> permutation;
		permutation.resize(num.size());
		generate(num,0,permutation,permutations);
		return permutations;
}

int main(){
	int A[]={1,2};
	vector<int>num(A,A+sizeof(A)/sizeof(A[0]));
	vector<vector<int> >permutations;
	permutations=permute(num);
	for(int i=0;i<permutations.size();i++){
		for(int j=0;j<permutations[i].size();j++){
			cout << permutations[i][j] << " ";
		}
		cout << endl;
	}	
	return 0;
}
