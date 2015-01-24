#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findMin(vector<int> &num){
	if(1==num.size())return(num[0]);
	int l=0,r=num.size()-1;
	int m=l;
	while(num[l]>=num[r]){
		if(r-l==1){
			m=r;
			break;
		}
		int m=(r+l)>>1;
		if(num[l]<=num[m]){
			l=m;
			continue;
		}
		if(num[m]<=num[r]){
			r=m;
			continue;
		}
		if(num[m]==num[l]&&num[m]==num[r]){
			int t=INT_MAX;
			for(int i=l;i<=r;i++){
				if(num[i]<t)t=num[i];
			}
			return t;
		}
	}

	return num[m];
}

int main(){
	int A[]={1,1,1,0,1};
	vector<int>num(A,A+sizeof(A)/sizeof(A[0]));
	cout << findMin(num) << endl;
	return 0;
}
