#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<climits>
#include<iterator>
using namespace std;
int trailingZeroes(int n){
    if(0==n)return 0;
    int exp5=log10(n)/log10(5);
    //cout << exp5 << endl;
    vector<int>exp5s(exp5+1);
    int sum=0;
    for(int i=exp5;i>=1;i--){
        exp5s[i]=n/(int)(pow(5,i));
        sum+=exp5s[i]*i;
    }
    int more=0;
    for(int i=2;i<=exp5;i++){
        int t=0;
        for(int j=1;j<=i-1;j++){
            t+=exp5s[i]*j;
        }
        more+=t;
    }

    /*
    ostream_iterator<int>output(cout," ");
    copy(exp5s.begin(),exp5s.end(),output);
    cout << endl;
    */
    return sum-more;
}


int main(){
    cout << trailingZeroes(0) << endl;
	return 0;
}
